#include "UnsortedArray.h"
#include <iostream>

UnsortedArray::UnsortedArray(int size) {
    this->size = size;
    posOfLastElement = 0;
    array = new Element[size];
    for (int i = 0; i < size; i++){
        array[i].word = " ";
        array[i].appearances = 0;
    }
}

UnsortedArray::~UnsortedArray() {
    delete[] array;
}

int UnsortedArray::search(string key) {
    int pos = -1;
    for (int i = 0; i < size && pos == -1; i++){
        if (array[i].word == key)
            pos = i;
    }
    //if (pos!=-1)
    //    cout << array[pos].word << ": " << array[pos].appearances << endl;
    return pos;
}

// Inserts a key in Array->word a of given capacity.
// n is current size of Array *a. This
// function returns n + 1 if insertion
// is successful, else n.
void UnsortedArray::insert(string key){
    if (posOfLastElement < size){
        int pos = search(key);
        if (pos == -1){
            posOfLastElement++;
            array[posOfLastElement].word = key;
            array[posOfLastElement].appearances = 1;
        }else
            array[pos].appearances++;
    }
}

void UnsortedArray::remove(string key){
    int pos = search(key);
    if (pos != -1){
        if (array[pos].appearances > 1)
            array[pos].appearances--;
        else if (array[pos].appearances == 1 || array[pos].appearances == 0){
            size--;
            for (int i = pos; i < size; i++)
                array[i] = array[i+1];
        }
    }
}

int UnsortedArray::getSize() {
    return posOfLastElement;
}

string UnsortedArray::getArray(int i) {
    return array[i].word;
}
