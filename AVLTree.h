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

    Node *getRoot(){return root;}
    void insert(string key);
    void remove(string key);
    Node *search(string key);
    void printInOrder();
    void printPreOrder();
    void printPostOrder();
};
#endif