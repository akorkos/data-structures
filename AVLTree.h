#ifndef AVLTREE_H
#define AVLTREE_H

#include <string>
#include <iostream>
using namespace std;

struct Node
{
    string word;
    Node *right, *left;
    int appearances, height;
};

class AVLTree{
private:
    Node *root;
    Node *insert(Node* rt, string key);
    Node *search(string key); //αναζήτηση κόμβου με τη λέξη key
    Node *remove(Node *rt, string key);
    Node *rRR(Node *rt);
    Node *rLR(Node *rt);
    Node *rLL(Node *rt);
    Node *rRL(Node *rt);
    Node *minimum(Node *rt);
    Node *balance(Node *rt);
    int maximum(int x, int y);
    int height(Node *rt);
    int getBalance(Node *rt);
    void inOrder(Node *pos);
    void preOrder(Node *pos);
    void postOrder(Node *pos);
    void destroy(Node *rt);
public:
    AVLTree();
    ~AVLTree();

    void insert(string key); //εισαγωγή λέξης στο AVL Tree
    void remove(string key); //διαγραφή κόμβου με τη λέξη key
    int search(string key, int apps); //αναζήτηση κόμβου με τη λέξη key
    void printInOrder();
    void printPreOrder();
    void printPostOrder();
};
#endif