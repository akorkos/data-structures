#include <iostream>
#include <fstream>
#include <chrono>

#include "UnsortedArray.h"
#include "SortedArray.h"
#include "BinarySearchTree.h"
#include "AVLTree.h"
#include "HashTable.h"

using namespace std;

//Μέθοδος που μετράει το χρόνο που χρειάζεται για την αναζήτηση λέξεων σε κάθε δομή δεδομένων
//Χρήση βιβλιοθήκης <chrono>.
template<class X>
void timeNeededForSearch(string *q, X dataStructure, string structure, int numberOfWords) {
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
    auto duration = (stop - start);
    cout << endl << "The time needed for the search in " << structure << " was: " << duration.count() << " microseconds"
         << endl;
}

int main() {
    //άνοιγμα και διάβασμα αρχείου
    string filename = "small-file.txt";
    string word; //κάθε λέξη του αρχείου
    fstream file;
    file.open(filename.c_str());

    //Σύνολο Q τυχαίων λέξεων που ζητείται
    string *q = new string[1000];
    int qIndex = 0;

    //Δημιουργία κάθε δομής δεδομένων
    UnsortedArray *unArr = new UnsortedArray();
    SortedArray *sorArr = new SortedArray();
    BinarySearchTree *bst = new BinarySearchTree();
    AVLTree *avl = new AVLTree();
    HashTable *table = new HashTable();

    //διάβασμα κάθε λέξης από το αρχείο και μετατροπή της σε κατάλληλη μορφή
    while (file >> word) {
        int len = word.size();

        //βγάζουμε τα σημεία στίξης
        for (int i = 0; i < len; i++) {
            word[i] = tolower(word[i]); //μετατροπή όλων των γραμμάτων σε πεζά
            if (!(word[i] >= 'a' && word[i] <= 'z')) {
                word.erase(i--, 1);
                len = word.size();
            }
        }

        //δημιουργία συνόλου Q
        if (rand() % 2 && qIndex < 1000) {
            q[qIndex] = word;
            qIndex++;
        }

        //εισαγωγή λέξεων από το αρχείο στις 5 δομές
        unArr->insert(word);
        //sorArr->insert(word);
        //bst->insert(word);
        //avl->insert(word);
        //table->insert(word);
    }

    //Αναζήτηση όλων των λέξεων του συνόλου Q σε κάθε δομή. Εμφαζίνεται ο χρόνος που χρειάστηκε για την εκτέλεση
    //αναζήτησης της κάθε δομής & πόσες φορές εμφανίζεται η κάθε λέξη


    //UnsortedArray
    timeNeededForSearch(q, unArr, "Unsorted Array", qIndex);

    //SortedArray
   // timeNeededForSearch(q, sorArr, "Sorted Array", qIndex);

    //BinarySearchTree
   // timeNeededForSearch(q, bst, "Binary Search Tree", qIndex);

    //AVLTree
   // timeNeededForSearch(q, avl, "AVL Tree", qIndex);

    //HashTable
   // timeNeededForSearch(q, table, "HashTable", qIndex);

    //κλέισιμο αρχείου
    file.close();

    return 0;
}