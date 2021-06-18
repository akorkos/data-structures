#ifndef AVLTREE_H
#define AVLTREE_H

#include <string>
#include <iostream>
using namespace std;

struct Node{
    string word;
    Node *right, *left;
    int height;
};

class AVLTree{
private:
    Node *root;
    Node *privSearch(string key); //αναζήτηση κόμβου με τη λέξη key
    Node *rR(Node *rt); //δεξία περιστροφή
    Node *rL(Node *rt); //αριστερά περιστροφή
    Node *minimum(Node *rt);
    int maximum(int x, int y);
    int height(Node *rt);
    int getBalance(Node *rt);
    void preOrder(Node *pos);
    void postOrder(Node *pos);
    void destroy(Node *rt);
public:
    AVLTree();
    Node *insert(Node* rt, string key);
    Node *remove(Node *rt, string key);
    ~AVLTree();
    void inOrder(Node *pos);
    //void insert(string key); //εισαγωγή λέξης στο AVL Tree
    //void remove(string key); //διαγραφή κόμβου με τη λέξη key
    int search(string key); //αναζήτηση κόμβου με τη λέξη key
    void printInOrder();
    void printPreOrder();
    void printPostOrder();

    Node *getRoot(){
        return root;
    }
    bool isBalanced(Node *root)
    {
        int lh; /* for height of left subtree */
        int rh; /* for height of right subtree */

        /* If tree is empty then return true */
        if (root == nullptr)
            return 1;

        /* Get the height of left and right sub trees */
        lh = height(root->left);
        rh = height(root->right);

        if (abs(lh - rh) <= 1 && isBalanced(root->left) && isBalanced(root->right))
            return 1;

        /* If we reach here then
        tree is not height-balanced */
        return 0;
    }
};
#endif