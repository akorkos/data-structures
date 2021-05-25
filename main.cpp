#include <iostream>
#include <fstream>

#include "UnsortedArray.h"
#include "SortedArray.h"
#include "BinarySearchTree.h"
#include "AVLTree.h"
#include "HashTable.h"

using namespace std;

//Method that counts the number of words in the file.
int wordCounter(string filename){
    string word;
    fstream file;
    int count = 0;

    file.open(filename.c_str());

    while (file >> word)
        count++;

    file.close();

    return count;
}

int main() {
     //open and read file
    string filename = "test.txt"; //"small-file.txt";
    string word; //each word from file
    fstream file;
    file.open(filename.c_str());

    int numberOfWords = wordCounter(filename);

    //create each data structure
    UnsortedArray *unArr = new UnsortedArray(numberOfWords);
    //!!!!!!ERROR!!!!!!!! SortedArray *sorArr = new SortedArray(numberOfWords);
    BinarySearchTree *bst = new BinarySearchTree();
    AVLTree *avl = new AVLTree();
    HashTable *table = new HashTable();

    //insert words from file to each data structure
    while (file >> word){
        int  len=word.size();
        //καθαρισμός της λέξης από σύμβολα
        for (int i = 0; i <len; i++)
        {
            word[i] = tolower(word[i]); //we set all characters to lower, in order to control the strings easier
            if (!(word[i]>='a' && word[i]<='z'))
            {
                //αν είναι τον διαγράφω
                word.erase(i--, 1);
                //επαναπροσδιορίζω το μήκος της συμβολοσειράς
                len = word.size();
            }
        }

        //insert word in each data structure
        unArr->insert(word);
        bst->insert(word);
        table->insert(word);
    }
    //b.remove("a");
    bst->printInOrder();

    file.close();

    return 0;
}