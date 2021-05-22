#ifndef UNSORTEDARRAY_H
#define UNSORTEDARRAY_H
#include <string>
using namespace std;

struct Element{
    int appearances;
    string word;
};

class UnsortedArray {
protected:
    Element *array;
    int posOfLastElement, size;
    int search(string key);
public:
    UnsortedArray(int size);
    ~UnsortedArray();
    void insert(string key);
    bool search(string key, int &apps);
    bool remove(string key);
};
#endif
