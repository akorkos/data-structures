#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree(){
    root = nullptr;
}
BinarySearchTree::~BinarySearchTree(){
    destroy(root);
}
bool BinarySearchTree::insert(string key){
    if (root == nullptr){
        root = new node;
        root->word = key;
        root->appearances = 1;
        root->parent = nullptr;
        root->right = nullptr;
        root->left = nullptr;
        return true;
    } else
        return insert(root, key);
}

bool BinarySearchTree::insert(node *rt, string key){
    if(key == rt->word){
        rt->appearances++;
        return true;
    }
    if (key > rt->word){
        if (rt->right == nullptr){
            rt->right = new node;
            rt->right->word = key;
            rt->right->appearances = 1;
            rt->right->parent = rt;
            rt->right->right = nullptr;
            rt->right->left = nullptr;
            return true;
        }
        return insert(rt->right, key);
    } else {
        if (rt->left == nullptr){
            rt->left = new node;
            rt->left->word = key;
            rt->left->appearances = 1;
            rt->left->parent = rt;
            rt->left->right = nullptr;
            rt->left->left = nullptr;
            return true;
        }
        return insert(rt->left, key);
    }
}

bool BinarySearchTree::search(string key, int &apps){
    node *pos = search(key);
    if (pos == nullptr){
        apps = 0;
        return false;
    } else {
        apps = pos->appearances;
        return true;
    }
}

node *BinarySearchTree::search(string key){
    node *pos = root;
    while(pos != nullptr && key != pos->word){
        if (key > pos->word)
            pos = pos->right;
        else
            pos = pos->left;
    }
    return pos;
}

bool BinarySearchTree::remove(node *rt){
  node *parent = rt->parent;
  /*
  if (rt == nullptr) //Warning: condition is always false
    return false;
  */
  if (rt->left == nullptr && rt->right == nullptr){
    if (parent == nullptr){
      delete(rt);
      root = nullptr;
    }
    else if (parent->left == rt){
      if (rt->appearances == 1){
        delete (parent->left);
        parent->left = nullptr;
      } else
        rt->appearances--;
    }
    else {
      if (rt->appearances == 1){
        delete (parent->right);
        parent->right = nullptr;
      } else
        rt->appearances--;
    }
  } else if (rt->left == nullptr || rt->right == nullptr){
    if (parent == nullptr){
      if (rt->left == nullptr)
        root = rt->right;
      else
        root = rt->left;
      delete (rt);
    } else if (parent->left == rt){
      if (rt->left == nullptr)
        parent->left = rt->right;
      else
        parent->left = rt->left;
      delete (rt);
    } else {
      if (rt->left == nullptr)
        parent->right = rt->right;
      else
        parent->right = rt->left;
      delete (rt);
    }
  } else {
    node *successor = minimum(rt->right);
    if (rt->appearances == 1){
      rt->word = successor->word;
      rt->appearances = successor->appearances;
      remove(successor);
    } else
      rt->appearances--;
  }
    return true;
}

bool BinarySearchTree::remove(string key){
  node *hasChild = search(key);
  if (hasChild == nullptr)
    return false;
  else
    return remove(hasChild);
}

node *BinarySearchTree::minimum(node *rt){
    while (rt->left != nullptr)
        rt = rt->left;
    return rt;
}

void BinarySearchTree::inOrder(node *pos){
    if (pos == nullptr)
        return;

    inOrder(pos->left);
    cout << pos->word <<" : " << pos->appearances << endl;
    inOrder(pos->right);
}

void BinarySearchTree::printInOrder(){
    inOrder(root);
}

void BinarySearchTree::preOrder(node *pos){
    if (pos == nullptr)
        return;

    cout << pos->word <<" : " << pos->appearances << endl;
    preOrder(pos->left);
    preOrder(pos->right);
}

void BinarySearchTree::printPreOrder(){
    preOrder(root);
}

void BinarySearchTree::postOrder(node *pos){
    if (pos == nullptr)
        return;

    postOrder(pos->left);
    postOrder(pos->right);
    cout << pos->word <<" : " << pos->appearances << endl;
}

void BinarySearchTree::printPostOrder(){
    postOrder(root);
}

void BinarySearchTree::destroy(node *rt){
    if (rt != nullptr){
        destroy(rt->left);
        destroy(rt->right);
        delete (rt);
    }
}