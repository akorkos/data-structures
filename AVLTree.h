#ifndef AVLTREE_H
#define AVLTREE_H

#include <string>
#include <iostream>
using namespace std;

class Node
{
public:
    string key;
    Node *left;
    Node *right;
    int height, appearances;
};

class AVLTree {
public:
    AVLTree();
    ~AVLTree();

    Node* newNode(string key);
    void printPostorder(Node* root);
    void printInorder(Node* root);
    Node *rightRotate(Node *y);
    Node *leftRotate(Node *x);
    int getBalance(Node *N);
    Node* insert(Node* node, string key);
    void preOrder(Node *root);
    int max(int a, int b);
    int height(Node *N);
    Node* deleteNode(Node* root, string key);
    Node * minValueNode(Node* node);
    int search(Node* root, string key);
};
#endif