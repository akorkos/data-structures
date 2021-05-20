#include "BinaryTree.h"

BinaryTree::BinaryTree(){
	root = NULL;
}

BinaryTree::~BinaryTree(){
	destroy_tree();
}

//might not be needed
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
            leaf->left->app = 1;
            leaf->left->left = NULL;
            leaf->left->right = NULL;
        }
    }else if (key >= leaf->value) {
        if (leaf->right != NULL) {
            insert(key, leaf->right);
        } else {
            leaf->right = new node;
            leaf->right->value = key;
            leaf->right->app = 1;
            leaf->right->right = NULL;
            leaf->right->left = NULL;
        }
    }
}

void BinaryTree::insert(string key){
    if(root != NULL){
        node *temp = search(key);
        if (temp == NULL)
            insert(key, root);
        else{
            temp->app++;
        }
    }else{
        root = new node;
        root->value = key;
        root->app = 1;
        root->left = NULL;
        root->right = NULL;
    }
}

node * BinaryTree::search(node *node, string key)
{
    // The given key is-
    // not found in BST
    if (node == NULL)
        return NULL;
        // The given key is found
    else if(node->value == key){
        cout<<"Word \""<<node->value<<"\" with "<<node->app<<" appearances"<<endl;
        return node;
    }
        // The given is greater than
        // current node's key
    else if(node->value < key)
        return search(node->right, key);
        // The given is smaller than
        // current node's key
    else
        return search(node->left, key);
}

node *BinaryTree::search(string key){
    // Invoking Search() operation
    // and passing root node
    node * result = search(root, key);

    // If key is found, returns TRUE
    // otherwise returns FALSE
    return result;
}

void BinaryTree::destroy_tree(){
	destroy_tree(root);
}

void BinaryTree::inorder_print(){
	inorder_print(root);
	cout << "\n";
}

void BinaryTree::inorder_print(node *leaf){
	if(leaf != NULL){
		inorder_print(leaf->left);
		cout << leaf->value << ": "<< leaf->app << ",";
		inorder_print(leaf->right);
	}
}

void BinaryTree::postorder_print(){
	postorder_print(root);
	cout << "\n";
}

void BinaryTree::postorder_print(node *leaf){
	if(leaf != NULL){
		postorder_print(leaf->left);
		postorder_print(leaf->right);
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
		preorder_print(leaf->left);
		preorder_print(leaf->right);
	}
}

node* getMinimumKey(node* curr)
{
    while (curr->left != nullptr) {
        curr = curr->left;
    }
    return curr;
}

void BinaryTree::searchKey(node* &curr, string key, node* &parent)
{
    // traverse the tree and search for the key
    while (curr != nullptr && curr->value != key)
    {
        // update the parent to the current node
        parent = curr;

        // if the given key is less than the current node, go to the left subtree;
        // otherwise, go to the right subtree
        if (key < curr->value) {
            curr = curr->left;
        }
        else {
            curr = curr->right;
        }
    }
}

void BinaryTree::deleteNode(node*& root, string key)
{
    // pointer to store the parent of the current node
    node* parent = nullptr;

    // start with the root node
    node* curr = root;

    // search key in the BST and set its parent pointer
    searchKey(curr, key, parent);

    // return if the key is not found in the tree
    if (curr == nullptr) {
        return;
    }

    // Case 1: node to be deleted has no children, i.e., it is a leaf node
    if (curr->left == nullptr && curr->right == nullptr)
    {
        // if the node to be deleted is not a root node, then set its
        // parent left/right child to null
        if (curr != root)
        {
            if (parent->left == curr) {
                parent->left = nullptr;
            }
            else {
                parent->right = nullptr;
            }
        }
            // if the tree has only a root node, set it to null
        else {
            root = nullptr;
        }

        // deallocate the memory
        free(curr);        // or delete curr;
    }

        // Case 2: node to be deleted has two children
    else if (curr->left && curr->right)
    {
        // find its inorder successor node
        node* successor = getMinimumKey(curr->right);

        // store successor value
        string val = successor->value;

        // recursively delete the successor. Note that the successor
        // will have at most one child (right child)
        deleteNode(root, successor->value);

        // copy value of the successor to the current node
        curr->value = val;
    }

        // Case 3: node to be deleted has only one child
    else {
        // choose a child node
        node* child = (curr->left)? curr->left: curr->right;

        // if the node to be deleted is not a root node, set its parent
        // to its child
        if (curr != root)
        {
            if (curr == parent->left) {
                parent->left = child;
            }
            else {
                parent->right = child;
            }
        }

            // if the node to be deleted is a root node, then set the root to the child
        else {
            root = child;
        }

        // deallocate the memory
        free(curr);
    }
}