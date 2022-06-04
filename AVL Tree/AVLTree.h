#ifndef AVLTREE_H
#define AVLTREE_H

#include <string>
#include <iostream>
using namespace std;

class Node{
public:
    string key;
    Node *left, *right;
    int height, appearances;
};

class AVLTree {
private:
    int getBalance(Node *N);
    int max(int a, int b);
    int height(Node *N);
    Node* newNode(string key);
    Node * minValueNode(Node* node);
    Node *rightRotate(Node *y);
    Node *leftRotate(Node *x);
public:
    AVLTree();
    ~AVLTree();
    void printInOrder(Node *pos);
    void printPreOrder(Node *pos);
    void printPostOrder(Node *pos);
    int search(Node* root, string key);
    Node* insert(Node* node, string key);
    Node* remove(Node* root, string key);
};
#endif