#include "AVLTree.h"
#include <iostream>

using namespace std;

AVLTree::AVLTree(){

}

AVLTree::~AVLTree() {

}

//Μέθοδος που επιστρέφει το ύψος του δένδρου
int AVLTree::height(Node *N)
{
    if (N == nullptr)
        return 0;
    return N->height;
}

//Μέθοδος που επιστρέφει το μεγαλύτερο ακέραιο
int AVLTree::max(int a, int b){
    return (a > b)? a : b;
}


//Μέθοδος που δημιουργεί ένα νέο κόμβο με τη λέξη που δίνεται
Node* AVLTree::newNode(string key){
    Node* node = new Node();
    node->key = key;
    node->left = nullptr;
    node->right = nullptr;
    node->appearances = 1; //πρώτη εμφάνιση της λέξης στο κείμενο
    node->height = 1;
    return(node);
}

//Συνάρτηση που υλοποιεί τη δεξιά περιστροφή
Node *AVLTree::rightRotate(Node *y){
    //αρχικοποίηση
    Node *x = y->left;
    Node *T2 = x->right;

    //περιστροφή
    x->right = y;
    y->left = T2;

    //Αλλαγή heights
    y->height = max(height(y->left),height(y->right)) + 1;
    x->height = max(height(x->left),height(x->right)) + 1;

    //επιστρέφει τη νέα ρίζα
    return x;
}

//Μέθοδος που υλοποιεί την αριστερή περιστροφή
Node *AVLTree::leftRotate(Node *x){
    //αρχικοποίηση κόμβων
    Node *y = x->right;
    Node *T2 = y->left;

    // περιστροφή
    y->left = x;
    x->right = T2;

    //αλλαγή heights
    x->height = max(height(x->left),height(x->right)) + 1;
    y->height = max(height(y->left),height(y->right)) + 1;

    //επιστρέφει τη νέα ρίζα
    return y;
}

//Επιστρέφει τη διαφορά μεταξύ των υψών του αριστερού και του δεξιού υποδένδρου
int AVLTree::getBalance(Node *N){
    if (N == nullptr)
        return 0;
    return height(N->left) - height(N->right);
}

//Μέθοδος που υλοποιεί την εισαγωγή
Node* AVLTree::insert(Node* node, string key){
    if (node == nullptr) //δημιουργείται νέου κόμβου
        return(newNode(key));

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else { //η ίδια λέξη έχει ξανά εμφανιστεί στο κείμενο
        node->appearances++;
        return node;
    }

    //αλλαγή heights
    node->height = 1 + max(height(node->left),height(node->right));

    //Διαφορά υψών μεταξύ υποδένδρων - έλεγχος αν το δένδρο παραμένει ισορροπημένο
    int balance = getBalance(node);

    // Left Left Case
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && key > node->left->key){
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && key < node->right->key){
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void AVLTree::printInOrder(Node *pos) {
    if (pos == nullptr)
        return;

    printInOrder(pos->left);
    cout << pos->key << " : " << pos->appearances << endl;
    printInOrder(pos->right);
}


void AVLTree::printPreOrder(Node *pos) {
    if (pos == nullptr)
        return;

    cout << pos->key << " : " << pos->appearances << endl;
    printPreOrder(pos->left);
    printPreOrder(pos->right);
}

void AVLTree::printPostOrder(Node *pos) {
    if (pos == nullptr)
        return;

    printPostOrder(pos->left);
    printPostOrder(pos->right);
    cout << pos->key << " : " << pos->appearances << endl;
}


//μέθοδος που επιστρέφει τη μικρότερη τιμή που υπάρχει στο δένδρο
Node * AVLTree::minValueNode(Node* node){
    Node* current = node;

    //βρόχος για να βρεθεί το αριστερό φύλλο του δένδρου
    while (current->left != nullptr)
        current = current->left;

    return current;
}

//μέθοδος που υλοποιεί την αναζήτηση
int AVLTree::search(Node* root, string key){

    if(root == nullptr)
        return 0;

    if (root->key == key)
        return root->appearances;

    if (root->key < key)
        return search(root->right, key);

    return search(root->left, key);
}

//μέθοδος που υλοποιεί την διαγραφή
Node* AVLTree::remove(Node* root, string key){
    if (root == nullptr)
        return root;

    if ( key < root->key )//αν η λέξη που θέλουμε να διαγραφεί είναι μικρότερη από τη λέξη του κόμβου, τότε βρίσκεται στο αριστερό υποδένδρο
        root->left = remove(root->left, key);
    else if( key > root->key ) //αν η λέξη που θέλουμε να διαγραφεί είναι μεγαλύτερη από τη λέξη του κόμβου, τότε βρίσκεται στο δεξί υποδένδρο
        root->right = remove(root->right, key);
    else //η περίπτωση στην οποία βρέθηκε ο κόμβος με τη λέξη που δίνεται - ο κόμβος που θα διαγραφεί
    {
        //κόμβος με ένα ή κανένα παιδί
        if((root->left == nullptr) || (root->right == nullptr)){
            Node *temp = root->left ? root->left : root->right;

            //η περίπτωση που δεν έχει κανένα παιδί
            if (temp == nullptr){
                temp = root;
                root = nullptr;
            }
            else //η περίπτωση που έχει ένα παιδί
                *root = *temp; //αντιγραφή του παιδιού που δεν είναι κενό
            free(temp);
        }
        else //κόμβος με δύο παιδιά
        {
            Node* temp = minValueNode(root->right); //παίρνει τη πιο μικρή τιμή του δεξιού υποδένδρου

            //αντιγραφή key και appearances του temp στο root
            root->key = temp->key;
            root->appearances = temp->appearances;

            //διαγραφή στο δεξί υποδένδρο
            root->right = remove(root->right, temp->key);
        }
    }

    if (root == nullptr)
        return root;

    // αλλαγή height
    root->height = 1 + max(height(root->left),height(root->right));

    //Διαφορά υψών μεταξύ υποδένδρων - έλεγχος αν το δένδρο παραμένει ισορροπημένο
    int balance = getBalance(root);

    // Left Left Case
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    // Left Right Case
    if (balance > 1 && getBalance(root->left) < 0){
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    // Right Left Case
    if (balance < -1 && getBalance(root->right) > 0){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}
