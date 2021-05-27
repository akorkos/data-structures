#include <iostream>
#include <string>
using namespace std;

struct node{
    string word;
    int appearances;
    node *parent, *left, *right;
};

class BinarySearchTree{
private:
    node *root;
    node *insert(node *rt, string key);
    node *search(string key);
    bool remove(node *rt);
    node *minimum(node *rt);
    void inOrder(node *pos);
    void preOrder(node *pos);
    void postOrder(node *pos);
    void destroy(node *rt);
public:
    BinarySearchTree();
    ~BinarySearchTree();
    void insert(string key);
    bool search(string key, int &apps);
    bool remove(string key);
    void printInOrder();
    void printPreOrder();
    void printPostOrder();
};