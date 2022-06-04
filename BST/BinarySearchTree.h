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
    node *minimum(node *rt);
    node *privSearch(string key);
    bool insert(node *rt, string key);
    bool remove(node *rt);
    void inOrder(node *pos);
    void preOrder(node *pos);
    void postOrder(node *pos);
    void destroy(node *rt);
public:
    BinarySearchTree();
    ~BinarySearchTree();
    bool insert(string key); //εισαγωγή λέξης στο δέντρο
    int search(string key); //αναζήτηση κόμβου με τη λέξη key
    bool remove(string key); //διαγραφή κόμβου με τη λέξη key
    void printInOrder();
    void printPreOrder();
    void printPostOrder();
};