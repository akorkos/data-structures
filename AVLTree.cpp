#include "AVLTree.h"

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
Node* AVLTree::insert(Node* rt, string key) {
    //έλεγχος αν το δέντρο είναι κενό

    Node *p = new Node;
    Node *parent;
    parent = nullptr;

    p->word = key;
    p->right = nullptr;
    p->left = nullptr;

    if (rt == nullptr)
        rt = p;
    else {
        Node *ptr;
        ptr = rt;

        while (ptr != nullptr){
            parent = ptr;
            if (key > ptr->word)
                ptr = ptr->right;
            else
                ptr = ptr->left;
        }
        if (key < parent->word)
            parent->left = p;
        else
            parent->right = p;
    }

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

    return rt;

}

//αναζήτηση κόμβου με τη λέξη key
Node *AVLTree::privSearch(string key) {
    Node *pos = root;
    while(pos != nullptr && key != pos->word){
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

void AVLTree::inOrder(Node *pos){
    if (pos == nullptr)
        return;

    inOrder(pos->left);
    cout << pos->word <<endl;
    inOrder(pos->right);
}

void AVLTree::printInOrder(){
    Node *rt = nullptr;
    inOrder(rt); //καλεί την αντίστοιχη private μέθοδο για εκτύπωση των κόμβων με in-order
}

void AVLTree::preOrder(Node *pos){
    if (pos == nullptr)
        return;

    cout << pos->word <<endl;
    preOrder(pos->left);
    preOrder(pos->right);
}

void AVLTree::printPreOrder(){
    preOrder(root); //καλεί την αντίστοιχη private μέθοδο για εκτύπωση των κόμβων με pre-order
}

void AVLTree::postOrder(Node *pos){
    if (pos == nullptr)
        return;
    postOrder(pos->left);
    postOrder(pos->right);
    cout << pos->word <<endl;
}

void AVLTree::printPostOrder(){
    postOrder(root); //καλεί την αντίστοιχη private μέθοδο για εκτύπωση των κόμβων με post-order
}

//χρησιμοποιείται στο καταστροφέα
//καταστροφή παιδιών και μετά καταστροφή ρίζας (αναδρομικά)
void AVLTree::destroy(Node *rt){
    if (rt != nullptr){
        destroy(rt->left);
        destroy(rt->right);
        delete (rt);
    }
}

//επιστρέφει το ύψος του δοθέντος κόμβου
int AVLTree::height(Node *rt) {
    if(rt == nullptr)
        return 0;
    return rt->height;
}

//διαφορά ύψους των παιδιών ενός κόμβου, αν ο κόμβος δεν είναι κενός
int AVLTree::getBalance(Node *rt) {
    if(rt == nullptr)
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

    rt->height = 1 + maximum(height(rt->left),height(rt->right));
    x->height = 1 + maximum(height(rt->left),height(rt->right));
    return x;
}


//περιστροφή αριστερά - αριστερά
Node *AVLTree::rL(Node *rt) {
    Node *x = rt->right;
    Node *tmp = x->left;

    x->left = rt;
    rt->right = tmp;

    rt->height = 1 + maximum(height(rt->left),height(rt->right));
    x->height = 1 + maximum(height(rt->left),height(rt->right));
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
    else if(key > rt->word)
        rt->right = remove(rt -> right, key);
    else{
        if((rt -> left == nullptr) || (rt -> right == nullptr)){
            Node *temp = new Node;
            if(temp == rt->left)
                temp = rt->left;
            else
                temp = rt->right;
            if (temp == nullptr){
                temp = rt;
                rt = nullptr;
            } else
                *rt = *temp;
            delete(temp);
        } else {
            Node* temp = minimum(rt->right);
            rt->word = temp->word;
            rt->right = remove(rt->right,temp->word);
        }
    }

    rt->height = 1 + max(height(rt->left), height(rt->right));

    int balance = getBalance(rt);
    //ελέγχουμε αν το δέντρο είναι ισοσκελισμένο
    //και αν δεν είναι το τροποποιύμε με τις συναρτήσεις αριστερής και δεξιας περιστροφης:
    if (balance > 1){
        if (getBalance(rt->left) >= 0)
            return rR(rt);
        else if (getBalance(rt->left) < 0){
            rt -> left = rL(rt -> left);
            return rR(rt);
        }
    } else if (balance < -1){
        if (getBalance(rt->right) <= 0)
            return rL(rt);
        else if (getBalance(rt -> right) > 0) {
            rt->right = rR(rt->right);
            return rL(rt);
        }
    }
    return rt;
}

//επιστροφή μεγαλύτερου ακέραιου αριθμού
int AVLTree::maximum(int x, int y) {
    return x>y?x:y;
}

