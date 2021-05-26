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
    int search(string key); // επιστρέφει την θέση της λέξης μέσα στον πίνακα (σειριακά)
    void resize(); // μεγαλώνει το μέγεθος του πίνακα
public:
    UnsortedArray();
    ~UnsortedArray();
    void insert(string key); // μέθοδος που εισάγει την λέξη στο πίνακα
    bool search(string key, int &apps); // μέθοδος που αναζητά μια λέξη μέσα από τον πίνακα
    bool remove(string key); // μέθοδος για την διαγραφή μιας λέξης μέσα από τον πίνακα
    //Element *getArray(){return array;}
};
#endif