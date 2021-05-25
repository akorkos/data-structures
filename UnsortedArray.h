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
public:
    UnsortedArray(int size);
    ~UnsortedArray();
    void insert(string key);
    //bool search(string key, int &apps);
    int search(string key, int pos); //this method returns the appearances from the key
    int search(string key); //this method returns the position of the element
    bool remove(string key);
    Element *getArray(){return array;}
};
#endif