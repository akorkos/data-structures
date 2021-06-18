#include "AVLTree.h"
#include <iostream>

using namespace std;

AVLTree::AVLTree(){

}

AVLTree::~AVLTree() {

}

// A utility function to get maximum
// of two integers
//int AVLTree::max(int a, int b);

// A utility function to get the
// height of the tree
int AVLTree::height(Node *N)
{
    if (N == nullptr)
        return 0;
    return N->height;
}

// A utility function to get maximum
// of two integers
int AVLTree::max(int a, int b)
{
    return (a > b)? a : b;
}

/* Helper function that allocates a
   new node with the given key and
   NULL left and right pointers. */
Node* AVLTree::newNode(string key)
{
    Node* node = new Node();
    node->key = key;
    node->left = nullptr;
    node->right = nullptr;
    node->appearances=1;
    node->height = 1; // new node is initially
    // added at leaf
    return(node);
}

// A utility function to right
// rotate subtree rooted with y
// See the diagram given above.
Node *AVLTree::rightRotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left),
                    height(y->right)) + 1;
    x->height = max(height(x->left),
                    height(x->right)) + 1;

    // Return new root
    return x;
}

// A utility function to left
// rotate subtree rooted with x
// See the diagram given above.
Node *AVLTree::leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(height(x->left),
                    height(x->right)) + 1;
    y->height = max(height(y->left),
                    height(y->right)) + 1;

    // Return new root
    return y;
}

// Get Balance factor of node N
int AVLTree::getBalance(Node *N)
{
    if (N == nullptr)
        return 0;
    return height(N->left) - height(N->right);
}

// Recursive function to insert a key
// in the subtree rooted with node and
// returns the new root of the subtree.
Node* AVLTree::insert(Node* node, string key)
{
    /* 1. Perform the normal BST insertion */
    if (node == nullptr)
        return(newNode(key));

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else { // Equal keys are not allowed in BST
        node->appearances++;
        return node;
    }

    /* 2. Update height of this ancestor node */
    node->height = 1 + max(height(node->left),
                           height(node->right));

    /* 3. Get the balance factor of this ancestor
        node to check whether this node became
        unbalanced */
    int balance = getBalance(node);

    // If this node becomes unbalanced, then
    // there are 4 cases

    // Left Left Case
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    /* return the (unchanged) node pointer */
    return node;
}

// A utility function to print preorder
// traversal of the tree.
// The function also prints height
// of every node
void AVLTree::preOrder(Node *root)
{
    if(root != nullptr)
    {
        cout << root->key << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void AVLTree::printPostorder(Node* root)
{
    if (root == NULL)
        return;

    printPostorder(root->left);                     //ΞµΟ€ΞΉΟƒΞΊΞµΟ€Ο„ΟΞΌΞ±ΟƒΟ„Ξµ Ο„ΞΏΟ…Ο‚ ΞΊΟΞΌΞ²ΞΏΟ…Ο‚ Ο„ΞΏΟ… Ξ±ΟΞΉΟƒΟ„ΞµΟΞΏΟ Ο…Ο€ΞΏΞ΄Ξ­Ξ½Ο„ΟΞΏΟ…

    printPostorder(root->right);                    //ΞµΟ€ΞΉΟƒΞΊΞµΟ€Ο„ΟΞΌΞ±ΟƒΟ„Ξµ Ο„ΞΏΟ…Ο‚ ΞΊΟΞΌΞ²ΞΏΟ…Ο‚ Ο„ΞΏΟ… Ξ΄ΞµΞΎΞΉΞΏΟ Ο…Ο€ΞΏΞ΄Ξ­Ξ½Ο„ΟΞΏΟ…

    cout << root->key << " ";                       //Ο„Ο…Ο€ΟΞ½ΞΏΟ…ΞΌΞµ Ο„ΞΏΞ½ Ξ―Ξ΄ΞΉΞΏ Ο„ΞΏΞ½ ΞΊΟΞΌΞ²ΞΏ
}


void AVLTree::printInorder(Node* root)
{
    if (root == NULL)
        return;

    printInorder(root->left);                      //ΞµΟ€ΞΉΟƒΞΊΞµΟ€Ο„ΟΞΌΞ±ΟƒΟ„Ξµ Ο„ΞΏΟ…Ο‚ ΞΊΟΞΌΞ²ΞΏΟ…Ο‚ Ο„ΞΏΟ… Ξ±ΟΞΉΟƒΟ„ΞµΟΞΏΟ Ο…Ο€ΞΏΞ΄Ξ­Ξ½Ο„ΟΞΏΟ…

    cout << root->key << " ";                      //Ο„Ο…Ο€ΟΞ½ΞΏΟ…ΞΌΞµ Ο„ΞΏΞ½ Ξ―Ξ΄ΞΉΞΏ Ο„ΞΏΞ½ ΞΊΟΞΌΞ²ΞΏ

    printInorder(root->right);                     //ΞµΟ€ΞΉΟƒΞΊΞµΟ€Ο„ΟΞΌΞ±ΟƒΟ„Ξµ Ο„ΞΏΟ…Ο‚ ΞΊΟΞΌΞ²ΞΏΟ…Ο‚ Ο„ΞΏΟ… Ξ΄ΞµΞΎΞΉΞΏΟ Ο…Ο€ΞΏΞ΄Ξ­Ξ½Ο„ΟΞΏΟ…
}


/* Given a non-empty binary search tree,
return the node with minimum key value
found in that tree. Note that the entire
tree does not need to be searched. */
Node * AVLTree::minValueNode(Node* node)
{
    Node* current = node;

    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
        current = current->left;

    return current;
}

int AVLTree::search(Node* root, string key)
{

    if(root== nullptr)
    {
       // time = clock() - time;
        //times2=times2+time;
        return 0;
    }

    if (root->key == key)
    {
        //time = clock() - time;
       // times2=times2+time;
        return root->appearances;
    }

    if (root->key < key)
        return search(root->right, key);

    return search(root->left, key);
}


Node* AVLTree::deleteNode(Node* root, string key)
{

    // STEP 1: PERFORM STANDARD BST DELETE
    if (root == NULL)
        return root;

    // If the key to be deleted is smaller
    // than the root's key, then it lies
    // in left subtree
    if ( key < root->key )
        root->left = deleteNode(root->left, key);

        // If the key to be deleted is greater
        // than the root's key, then it lies
        // in right subtree
    else if( key > root->key )
        root->right = deleteNode(root->right, key);

        // if key is same as root's key, then
        // This is the node to be deleted
    else
    {
        // node with only one child or no child
        if( (root->left == NULL) ||
            (root->right == NULL) )
        {
            Node *temp = root->left ?
                         root->left :
                         root->right;

            // No child case
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else // One child case
                *root = *temp; // Copy the contents of
            // the non-empty child
            free(temp);
        }
        else
        {
            // node with two children: Get the inorder
            // successor (smallest in the right subtree)
            Node* temp = minValueNode(root->right);

            // Copy the inorder successor's
            // data to this node
            root->key = temp->key;

            // Delete the inorder successor
            root->right = deleteNode(root->right,
                                     temp->key);
        }
    }

    // If the tree had only one node
    // then return
    if (root == NULL)
        return root;

    // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
    root->height = 1 + max(height(root->left),
                           height(root->right));

    // STEP 3: GET THE BALANCE FACTOR OF
    // THIS NODE (to check whether this
    // node became unbalanced)
    int balance = getBalance(root);

    // If this node becomes unbalanced,
    // then there are 4 cases

    // Left Left Case
    if (balance > 1 &&
        getBalance(root->left) >= 0)
        return rightRotate(root);

    // Left Right Case
    if (balance > 1 &&
        getBalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 &&
        getBalance(root->right) <= 0)
        return leftRotate(root);

    // Right Left Case
    if (balance < -1 &&
        getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

/**
AVLTree::AVLTree() {
    root = nullptr;
}

AVLTree::~AVLTree() {
    destroy(root);
}

//void AVLTree::insert(string key) {
//    Node *rt = nullptr;
//    insert(rt, key); //καλεί την αντίστοιχη private μέθοδο για την εισαγωγή λέξης στο δέντρο
//}

//εισαγωγή λέξης στο δέντρο

//Node* AVLTree::insert(Node* rt, string key)
Node* AVLTree::insert(Node *rt, string key) {
    //έλεγχος αν το δέντρο είναι κενό
    Node *p = new Node;
    Node *parent = new Node;

    p->word = key;
    p->right = nullptr;
    p->left = nullptr;
    p->appearances = 1;


    if (rt == nullptr) {
        rt = p;

    } else {
        Node *ptr;
        ptr = rt;
cout<<ptr->appearances<<endl;
        while (ptr != nullptr) { //den mpainei edw
            parent = ptr;    /*
            if(key==ptr->word)
                ptr->appearances++;

            if (key > ptr->word)
                ptr = ptr->right;
            else if (key < ptr->word)
                ptr = ptr->left;

            if (key < parent->word)
                parent->left = rt;
                /*
                else if (key==parent->word)
                    parent->appearances++;

            else
                parent->right = rt;
        }
        cout << "wtf" << endl; //den ftanei edw

        rt->height = 1 + maximum(height(rt->left), height(rt->right));

        int balance = getBalance(rt);

        if (balance > 1 && rt->left->word > key)
            return rR(rt);
        if (balance > 1 && rt->left->word < key)
            return rR(rt);

        if (balance < -1 && rt->right->word < key)
            return rL(rt);
        if (balance < -1 && rt->right->word > key)
            return rL(rt);

        //  cout<<"wtf"<<endl;
        //den ftanei edw
        return rt;
    }
}

//αναζήτηση κόμβου με τη λέξη key
Node *AVLTree::privSearch(string key) {
    Node *pos = root;
    while (pos != nullptr && key != pos->word) {
        if (key > pos->word)
            pos = pos->right;
        else
            pos = pos->left;
    }
    return pos;
}


int AVLTree::search(string key) {
    Node *pos = privSearch(key); //καλεί την αντίστοιχη private μέθοδο
    if (pos == nullptr) {
        return 0;
    } else
        return 1;
}

void AVLTree::inOrder(Node *pos) {
    if (pos == nullptr)
        return;

    inOrder(pos->left);
    cout << pos->word << endl;
    inOrder(pos->right);
}

void AVLTree::printInOrder() {
    Node *rt = nullptr;
    inOrder(rt); //καλεί την αντίστοιχη private μέθοδο για εκτύπωση των κόμβων με in-order
}

void AVLTree::preOrder(Node *pos) {
    if (pos == nullptr)
        return;

    cout << pos->word << endl;
    preOrder(pos->left);
    preOrder(pos->right);
}

void AVLTree::printPreOrder() {
    preOrder(root); //καλεί την αντίστοιχη private μέθοδο για εκτύπωση των κόμβων με pre-order
}

void AVLTree::postOrder(Node *pos) {
    if (pos == nullptr)
        return;
    postOrder(pos->left);
    postOrder(pos->right);
    cout << pos->word << endl;
}

void AVLTree::printPostOrder() {
    postOrder(root); //καλεί την αντίστοιχη private μέθοδο για εκτύπωση των κόμβων με post-order
}

//χρησιμοποιείται στο καταστροφέα
//καταστροφή παιδιών και μετά καταστροφή ρίζας (αναδρομικά)
void AVLTree::destroy(Node *rt) {
    if (rt != nullptr) {
        destroy(rt->left);
        destroy(rt->right);
        delete (rt);
    }
}

//επιστρέφει το ύψος του δοθέντος κόμβου
int AVLTree::height(Node *rt) {
    if (rt == nullptr)
        return 0;
    return rt->height;
}

//διαφορά ύψους των παιδιών ενός κόμβου, αν ο κόμβος δεν είναι κενός
int AVLTree::getBalance(Node *rt) {
    if (rt == nullptr)
        return 0;
    return height(rt->left) - height(rt->right);
}

//ψάχνει αν υπάρχει κόμβος με μικρότερη λεξικογραφικά λέξη (αριστερό παιδί)
//αν δεν έχει αριστερό παιδί, επιστρέφει τον κόμβο που δίνεται σαν παράμετρος (current node)
Node *AVLTree::minimum(Node *rt) {
    Node *current = rt;
    while (current && current->left != nullptr)
        current = current->left;
    return current;
}

//περιστροφή δεξιά - δεξιά
Node *AVLTree::rR(Node *rt) {
    Node *x = rt->left;
    Node *tmp = x->right;

    x->right = rt;
    rt->left = tmp;

    rt->height = 1 + maximum(height(rt->left), height(rt->right));
    x->height = 1 + maximum(height(rt->left), height(rt->right));
    return x;
}


//περιστροφή αριστερά - αριστερά
Node *AVLTree::rL(Node *rt) {
    Node *x = rt->right;
    Node *tmp = x->left;

    x->left = rt;
    rt->right = tmp;

    rt->height = 1 + maximum(height(rt->left), height(rt->right));
    x->height = 1 + maximum(height(rt->left), height(rt->right));
    return x;
}

//void AVLTree::remove(string key) {
// root = remove(root, key); //καλεί την αντίστοιχη private μέθοδο για διαγραφή κόμβου από το δέντρο
//}

//διαγραφή κόμβου από το δέντρο
Node *AVLTree::remove(Node *rt, string key) {
    if (rt == nullptr)
        return rt;
    if (key < rt->word)
        rt->left = remove(rt->left, key);
    else if (key > rt->word)
        rt->right = remove(rt->right, key);
    else {
        if ((rt->left == nullptr) || (rt->right == nullptr)) {
            Node *temp = new Node;
            if (temp == rt->left)
                temp = rt->left;
            else
                temp = rt->right;
            if (temp == nullptr) {
                temp = rt;
                rt = nullptr;
            } else
                *rt = *temp;
            delete (temp);
        } else {
            Node *temp = minimum(rt->right);
            rt->word = temp->word;
            rt->right = remove(rt->right, temp->word);
        }
    }

    rt->height = 1 + max(height(rt->left), height(rt->right));

    int balance = getBalance(rt);
    //ελέγχουμε αν το δέντρο είναι ισοσκελισμένο
    //και αν δεν είναι το τροποποιύμε με τις συναρτήσεις αριστερής και δεξιας περιστροφης:
    if (balance > 1) {
        if (getBalance(rt->left) >= 0)
            return rR(rt);
        else if (getBalance(rt->left) < 0) {
            rt->left = rL(rt->left);
            return rR(rt);
        }
    } else if (balance < -1) {
        if (getBalance(rt->right) <= 0)
            return rL(rt);
        else if (getBalance(rt->right) > 0) {
            rt->right = rR(rt->right);
            return rL(rt);
        }
    }
    return rt;
}

//επιστροφή μεγαλύτερου ακέραιου αριθμού
int AVLTree::maximum(int x, int y) {
    return x > y ? x : y;
}
*/