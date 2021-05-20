#ifndef UNSORTEDARRAY_H
#define UNSORTEDARRAY_H
#include <string>

using namespace std;

struct Element{
    int appearances;
    string word;
};

class UnsortedArray {
public:
    UnsortedArray();
    //UnsortedArray(int);
    ~UnsortedArray();

    Element *array;

    int insert(Element *array, int n, string key, int capacity);
    Element *search(Element *array, int n, string key);
    int deleteElement(Element *previousElement, int n, string key);

private:

};


#endif //DOMES_DEDOMENWN_2021_UNSORTEDARRAY_H
