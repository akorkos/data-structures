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
    int posOfLastElement;
    int size;
    Element *array;
public:
    UnsortedArray(int size);
    ~UnsortedArray();
    void insert(string key);
    int search(string key);
    void remove(string key);
    int getSize();
    string getArray(int i);
};

#endif
