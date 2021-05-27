#include <iostream>
#include <fstream>
#include <chrono>

#include "UnsortedArray.h"
#include "SortedArray.h"
#include "BinarySearchTree.h"
#include "AVLTree.h"
#include "HashTable.h"

using namespace std;

//Method that counts the number of words in the file.
int wordCounter(string filename) {
    string word;
    fstream file;
    int count = 0;

    file.open(filename.c_str());

    while (file >> word)
        count++;

    file.close();

    return count;
}

//Method that counts the time that is needed for the search in data structures: Unsorted and Sorted Array.
//it apples in these structures because search() returns int -> number of appearances of the key
//It uses <chrono>.
template<class X>
void timeNeededForSearchInArrays(string *q, X dataStructure, string structure, int numberOfWords) {
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < numberOfWords; i++) {
        int times = dataStructure->search(q[i]);
        if (times == 1) {
            cout << "The word: '" << q[i] << "' is shown once in " << structure << endl;
            continue;
        } else {
            cout << "The word: '" << q[i] << "' is shown " << times << " times in " << structure << endl;
        }
    }
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = (stop - start); //auto duration = duration_cast<std::chrono::microseconds>(stop-start);
    cout << endl << "The time needed for the search in " << structure << " was: " << duration.count() << " microseconds"  << endl;
    cout<<numberOfWords<<endl; //!!!DEN XREIAZETAI!!!
}

//Method that counts the time that is needed for the search in BST, AVLTree and HashTable.
//it applies in these structures, because search() returns typename Y
//It uses <chrono>.
template<class X, typename Y>
void timeNeededForSearch(string *q, X dataStructure, string structure, Y node, int numberOfWords) {
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < numberOfWords; i++) {
        node = dataStructure->search(q[i]);
        if (node->appearances == 1) {
            cout << "The word: '" << q[i] << "' is shown once in " << structure << endl;
            continue;
        } else {
            cout << "The word: '" << q[i] << "' is shown " << node->appearances << " times in " << structure << endl;
        }
    }
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = (stop - start); //auto duration = duration_cast<std::chrono::microseconds>(stop-start);
    cout << endl << "The time needed for the search in " << structure << " was: " << duration.count() << " microseconds"  << endl;
}

int main() {
    //open and read file
    string filename = "test.txt"; //!!! change into "small-file.txt"; !!!!
    string word; //each word from file
    fstream file;
    file.open(filename.c_str());

    int numberOfWords = wordCounter(filename);

    //total Q of words
    string *q = new string[100];//!!!!!change into 1000!!!
    int qIndex = 0;

    //create each data structure
    UnsortedArray *unArr = new UnsortedArray();
    SortedArray *sorArr = new SortedArray();
    BinarySearchTree *bst = new BinarySearchTree();
    AVLTree *avl = new AVLTree();
    HashTable *table = new HashTable();

    //insert words from file to each data structure
    while (file >> word) {
        int len = word.size();

        //clear grammatical marks from word
        for (int i = 0; i < len; i++) {
            word[i] = tolower(word[i]); //we set all characters to lower, in order to control the strings easier
            if (!(word[i] >= 'a' && word[i] <= 'z')) {
                word.erase(i--, 1);
                len = word.size();
            }
        }

        if (rand()%2 && qIndex<100) { //!!!!!change into 1000!!!
            q[qIndex] = word;
            qIndex++;
        }

        //insert word in each data structure
        if(word!="") {
            unArr->insert(word);
            sorArr->insert(word);
            bst->insert(word);
            avl->insert(word);
            table->insert(word);
        }
    }

    //UnsortedArray
    timeNeededForSearchInArrays(q, unArr, "Unsorted Array", qIndex);

    //SortedArray
    //timeNeededForSearchInArrays(q, sorArr, "Sorted Array", qIndex);

    //BinarySearchTree
    //timeNeededForSearch(q, bst, "Binary Search Tree", bst->getRoot(), qIndex);

    //AVLTree
    //timeNeededForSearch(q, avl, "AVL Tree", avl->getRoot(), qIndex);

    //HashTable
    //timeNeededForSearch(q, table, "HashTable", *table->getRoot(), qIndex);

    //bst->remove(""); //an den kanw auto, uparxei kenos kombos
    bst->printInOrder();

    //cout<<numberOfWords<<endl;

    file.close();

    return 0;
}