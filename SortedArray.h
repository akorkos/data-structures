#ifndef SORTEDARRAY_H
#define SORTEDARRAY_H
#include "UnsortedArray.h"

struct Element{
    string word;
    int appearances;
};

class SortedArray: UnsortedArray{
private:
    Element *array;
    int posOfLastElement, size;
public:
    SortedArray(int size);
    ~SortedArray();
    int search(string key);
};
#endif
