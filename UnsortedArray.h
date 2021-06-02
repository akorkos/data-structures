#ifndef UNSORTEDARRAY_H
#define UNSORTEDARRAY_H
#include <string>
using namespace std;

struct Element{
    int appearances;
    string word;
};

class UnsortedArray {
private:
    Element *array;
    int posOfLastElement, size; // posOfLastElement = κρατά την θέση του τελευταίου στοιχείου του πίνακα, size = κρατάει το μέγεθος πίνακα
    int serialSearch(string key); // υλοποίση της σειριακής αναζήτησης
    void resize(); // μεγαλώνει το μέγεθος του πίνακα
public:
    UnsortedArray();
    ~UnsortedArray();
    void insert(string key); // μέθοδος που εισάγει την λέξη στο πίνακα
    int search(string key); // μέθοδος που αναζητά μια λέξη μέσα από τον πίνακα με σειριακό τρόπο
    bool remove(string key); // μέθοδος για την διαγραφή μιας λέξης μέσα από τον πίνακα
};
#endif