#ifndef SORTEDARRAY_H
#define SORTEDARRAY_H
#include "UnsortedArray.h"

class SortedArray{
private:
    Element *array;
    int posOfLastElement;
    int insert(string key, bool &found);
public:
    SortedArray(int size);
    ~SortedArray();
    void insert(string key);
    bool search(string key, int &apps);
    int search(string key); //this method returns the number of appearances of the word or -1
    bool remove(string key);
    Element *getArray(){return array;}
};
#endif