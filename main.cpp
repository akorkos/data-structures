#include <iostream>
#include <fstream>
#include <chrono>

#include "UnsortedArray.h"
#include "SortedArray.h"
#include "BinarySearchTree.h"
#include "AVLTree.h"
#include "HashTable.h"

using namespace std;
using namespace std::chrono;

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
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "The time needed for the search in " << structure << " was: " << duration.count() << " microseconds" << endl;
}

//Μέθοδος που μετράει το χρόνο που χρειάζεται για την αναζήτηση λέξεων στη δομή AVLTree
void timeForAVL(string *q, AVLTree dataStructure, int numberOfWords, Node *root){
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < numberOfWords; i++) {
        int times = dataStructure.search(root, q[i]);
        if (times == 1) {
            cout << "The word: '" << q[i] << "' is shown once in AVL Tree" << endl;
            continue;
        } else {
            cout << "The word: '" << q[i] << "' is shown " << times << " times in AVL Tree "<< endl;
        }
    }
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "The time needed for the search in AVL Tree was: " << duration.count() << " microseconds" << endl;
}

int main() {
    string filename = "small-file.txt"; //ονομα αρχειου αναγνωσης
    string word; //κάθε λέξη του αρχείου
    fstream file;
    file.open(filename.c_str());
    string *q = new string[1000]; //Σύνολο Q τυχαίων λέξεων που ζητείται
    int qIndex = 0;

    Node *rt = nullptr; //κόμβος-ρίζα για τη δομή AVL Tree
    //Δημιουργία κάθε δομής δεδομένων
    UnsortedArray *Array = new UnsortedArray();
    SortedArray *sArray= new SortedArray();
    BinarySearchTree *BST = new BinarySearchTree();
    AVLTree *AVL = new AVLTree();
    HashTable *HASH = new HashTable();

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
        Array->insert(word);
        sArray->insert(word);
        BST->insert(word);
        rt = AVL->insert(rt,word);
        HASH->insert(word);
    }

    //Αναζήτηση όλων των λέξεων του συνόλου Q σε κάθε δομή. Εμφαζίνεται ο χρόνος που χρειάστηκε για την εκτέλεση
    //αναζήτησης της κάθε δομής & πόσες φορές εμφανίζεται η κάθε λέξη

    timeNeededForSearch(q, Array, "Unsorted Array", qIndex); //UnsortedArray

    timeNeededForSearch(q, sArray, "Sorted Array", qIndex); //SortedArray

    timeNeededForSearch(q, BST, "Binary Search Tree", qIndex); //BinarySearchTree

    timeForAVL(q, *AVL, qIndex, rt); //AVLTree

    timeNeededForSearch(q, HASH, "HashTable", qIndex); //HashTable

    file.close(); //κλέισιμο αρχείου

    return 0;
}
