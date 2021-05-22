#ifndef SORTEDARRAY_H
#define SORTEDARRAY_H
#include "UnsortedArray.h"

class SortedArray{
private:
    Element *array;
    int posOfLastElement, size;
    int search(string key);
    int insert(string key, bool &found);
public:
    SortedArray(int size);
    ~SortedArray();
    void insert(string key);
    bool search(string key, int &apps);
    bool remove(string key);
};
#endif
