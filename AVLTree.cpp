#include "AVLTree.h"

AVLTree::AVLTree() {
    root = nullptr;
}

AVLTree::~AVLTree() {
    destroy(root);
}

void AVLTree::insert(string key) {
    root = insert(root, key);
}

Node* AVLTree::insert(Node* rt, string key) {
    if (rt == nullptr){
        rt = new Node;
        rt->word = key;
        rt->left = nullptr;
        rt->right = nullptr;
        rt->appearances = 1;
        rt->height = 1;
        return rt;
    } else if (key < rt->word){
        rt->left = insert(rt->left, key);
        rt = balance(rt);
    } else if (key > rt->word){
        rt->right = insert(rt->right, key);
        rt = balance(rt);
    } else if (key == rt->word){
        rt->appearances++;
        return rt;
    }
    return rt;
}

Node *AVLTree::search(string key) {
    Node *pos = root;
    while(pos != nullptr && key != pos->word){
        if (key > pos->word)
            pos = pos->right;
        else
            pos = pos->left;
    }
    return pos;
}

void AVLTree::inOrder(Node *pos){
    if (pos == nullptr)
        return;

    inOrder(pos->left);
    cout << pos->word <<" : " << pos->appearances << endl;
    inOrder(pos->right);
}

void AVLTree::printInOrder(){
    inOrder(root);
}

void AVLTree::preOrder(Node *pos){
    if (pos == nullptr)
        return;

    cout << pos->word <<" : " << pos->appearances << endl;
    preOrder(pos->left);
    preOrder(pos->right);
}

void AVLTree::printPreOrder(){
    preOrder(root);
}

void AVLTree::postOrder(Node *pos){
    if (pos == nullptr)
        return;
    postOrder(pos->left);
    postOrder(pos->right);
    cout << pos->word <<" : " << pos->appearances << endl;
}

void AVLTree::printPostOrder(){
    postOrder(root);
}

void AVLTree::destroy(Node *rt){
    if (rt != nullptr){
        destroy(rt->left);
        destroy(rt->right);
        delete (rt);
    }
}

int AVLTree::height(Node *rt) {
    if(rt == nullptr)
        return 0;
    return rt->height;
}

int AVLTree::getBalance(Node *rt) {
    if(rt == nullptr)
        return 0;
    return height(rt->left) - height(rt->right);
}

Node *AVLTree::minimum(Node *rt) {
    Node *current = rt;
    while (current && current->left != nullptr)
        current = current->left;
    return current;
}

Node *AVLTree::balance(Node *rt) {
    rt->height = 1 + maximum(height(rt->left),height(rt->right));
    int difference = getBalance(rt);
    if (difference > 1){
        if (getBalance(rt->left) > 0)
            rt = rLL(rt);
        else
            rt= rLR(rt);
    } else if (difference < -1) {
        if (getBalance(rt->right) > 0)
            rt = rRL(rt);
        else
            rt = rRR(rt);
    }
    return rt;
}

Node *AVLTree::rRR(Node *rt) {
    Node *temp = rt->right;
    rt->right = temp->left;
    temp->left = rt;
    rt->height = 1 + maximum(height(rt->left),height(rt->right));
    temp->height = 1 + maximum(height(rt->left),height(rt->right));
    return temp;
}

Node *AVLTree::rLR(Node *rt) {
    Node *temp;
    temp = rt->left;
    rt->left = rRR(temp);
    return rLL(rt);
}

Node *AVLTree::rLL(Node *rt) {
    Node *temp = rt->left;
    rt->left = temp->right;
    temp->right = rt;
    rt->height = 1 + maximum(height(rt->left),height(rt->right));
    temp->height = 1 + maximum(height(rt->left),height(rt->right));
    return temp;
}

Node *AVLTree::rRL(Node *rt) {
    Node *temp = rt->right;
    rt->right= rLL(temp);
    return rRR(rt);
}

void AVLTree::remove(string key) {
    root = remove(root, key);
}

Node *AVLTree::remove(Node *rt, string key) {
    if (rt == nullptr)
        return rt;
    if (key < rt->word){
        rt->left = remove(rt->left, key);
        rt = balance(rt);
    } else if (key > rt->word){
        rt->right = remove(rt->right, key);
        rt = balance(rt);
    } else{
        if (rt->left == nullptr){
            Node *temp = rt->right;
            delete rt;
            return temp;
        } else if (rt->right == nullptr){
            Node *temp = rt->left;
            delete rt;
            return temp;
        }
        Node *temp = minimum(rt->right);
        rt->word = temp->word;
        rt->right = remove(rt->right, temp->word);
    }
}

int AVLTree::maximum(int x, int y) {
    return x>y?x:y;
}