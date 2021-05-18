#include "BinaryTree.h"

BinaryTree::BinaryTree(){
	root = NULL;
}

BinaryTree::~BinaryTree(){
	destroy_tree();
}

void BinaryTree::destroy_tree(node *leaf){
	if(leaf != NULL){
		destroy_tree(leaf->left);
		destroy_tree(leaf->right);
		delete leaf;
	}
}

void BinaryTree::insert(string key, node *leaf) {

    if (key < leaf->value) {
        if (leaf->left != NULL) {
            insert(key, leaf->left);
        } else {
            leaf->left = new node;
            leaf->left->value = key;
            leaf->left->left = NULL;
            leaf->left->right = NULL;
        }
    }else if (key >= leaf->value) {
        if (leaf->right != NULL) {
            insert(key, leaf->right);
        } else {
            leaf->right = new node;
            leaf->right->value = key;
            leaf->right->right = NULL;
            leaf->right->left = NULL;
        }
    }
}

void BinaryTree::insert(string key){
	if(root != NULL){
		insert(key, root);
		cout << key << "mphka!" << endl;
	}else{
		root = new node;
		root->value = key;
		root->left = NULL;
		root->right = NULL;
	}
}

node *BinaryTree::search(string key, node *leaf){
	if(leaf != NULL){
		if(key == leaf->value){
			return leaf;
		}
		if(key < leaf->value){
			return search(key, leaf->left);
		}else{
			return search(key, leaf->right);
		}
	}else{
		return NULL;
	}
}


node *BinaryTree::search(string key){
	return search(key, root);
}

void BinaryTree::destroy_tree(){
	destroy_tree(root);
}
/*
void BinaryTree::inorder_print(){
	inorder_print(root);
	cout << "\n";
}

void BinaryTree::inorder_print(node *leaf){
	if(leaf != NULL){
		inorder_print(leaf->left);
		cout << leaf->value << ",";
		inorder_print(leaf->right);
	}
}

void BinaryTree::postorder_print(){
	postorder_print(root);
	cout << "\n";
}

void BinaryTree::postorder_print(node *leaf){
	if(leaf != NULL){
		inorder_print(leaf->left);
		inorder_print(leaf->right);
		cout << leaf->value << ",";
	}
}

void BinaryTree::preorder_print(){
	preorder_print(root);
	cout << "\n";
}

void BinaryTree::preorder_print(node *leaf){
	if(leaf != NULL){
		cout << leaf->value << ",";
		inorder_print(leaf->left);
		inorder_print(leaf->right);
	}
}
*/
