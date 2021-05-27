#include <iostream>
#include <fstream>

#include "UnsortedArray.h"
#include "SortedArray.h"
#include "BinarySearchTree.h"
#include "AVLTree.h"
#include "HashTable.h"

using namespace std;

int main() {
     //open and read file
    string filename = "test.txt"; //"small-file.txt";
    string word; //each word from file
    fstream file;
    file.open(filename.c_str());

    //create each data structure
    UnsortedArray *unArr = new UnsortedArray();
    SortedArray *sorArr = new SortedArray();
    BinarySearchTree *bst = new BinarySearchTree();
    AVLTree *avl = new AVLTree();
    HashTable *table = new HashTable();

    //insert words from file to each data structure
    while (file >> word){
        int  len=word.size();
        //?????????? ??? ????? ??? ???????
        for (int i = 0; i <len; i++)
        {
            word[i] = tolower(word[i]); //we set all characters to lower, in order to control the strings easier
            if (!(word[i]>='a' && word[i]<='z'))
            {
                //?? ????? ??? ????????
                word.erase(i--, 1);
                //???????????????? ?? ????? ??? ?????????????
                len = word.size();
            }
        }

        //insert word in each data structure
        unArr->insert(word);
        bst->insert(word);
        table->insert(word);
        sorArr->insert(word);
    }
    cout << sorArr->search("the");
    cout << unArr->search("the");
    file.close();

    return 0;
}