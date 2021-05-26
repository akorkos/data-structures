#ifndef SORTEDARRAY_H
#define SORTEDARRAY_H
#include "UnsortedArray.h"

class SortedArray{
private:
    Element *array;
    int posOfLastElement, size; // posOfLastElement = κρατά την θέση του τελευταίου στοιχείου του πίνακα, size = κρατάει το μέγεθος πίνακα
    int insert(string key, bool &found); // υλοποιεί μια μορφή της δυαδική αναζήτησης για να προσδιοριστεί η θέση εισαγωγής ενός νέου στοιχείου
    int search(string key); // δυαδική αναζήτηση, επιστρέφει την θέση της λέξης μέσα στον πίνακα
    void resize(); // μεγαλώνει το μέγεθος του πίνακα
public:
    SortedArray();
    ~SortedArray();
    void insert(string key); // μέθοδος που εισάγει την λέξη στο πίνακα
    bool search(string key, int &apps); // μέθοδος που αναζητά μια λέξη μέσα από τον πίνακα
    bool remove(string key); // μέθοδος για την διαγραφή μιας λέξης μέσα από τον πίνακα
    // Element *getArray(){return array;}
};
#endif