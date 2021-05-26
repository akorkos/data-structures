#include "UnsortedArray.h"

UnsortedArray::UnsortedArray() {
    size = 1000;
    posOfLastElement = 0;
    array = new Element[size];
    for (int i = 0; i < size; i++) {
        array[i].word = " ";
        array[i].appearances = 0;
    }
}

UnsortedArray::~UnsortedArray() {
    delete[] array;
}

int UnsortedArray::search(string key) {
    int pos = -1;
    for (int i = 0; i < posOfLastElement && pos == -1; i++) {
        if (array[i].word == key)
            pos = i;
    }
    return pos;
}

void UnsortedArray::insert(string key) {
    if (posOfLastElement < size) {
        int pos = search(key);
        if (pos == -1) {
            posOfLastElement++;
            array[posOfLastElement].word = key;
            array[posOfLastElement].appearances = 1;
        } else
            array[pos].appearances++;
    }
    if (posOfLastElement == size)
        resize();
}

bool UnsortedArray::remove(string key) {
    int pos = search(key);
    if (pos != -1) {
        if (array[pos].appearances > 1)
            array[pos].appearances--;
        else if (array[pos].appearances == 1) {
            posOfLastElement--;
            for (int i = pos; i < posOfLastElement; i++)
                array[i] = array[i + 1];
        }
        return true;
    } else
        return false;
}

void UnsortedArray::resize() {
    size *= 2;
    Element *tmp = new Element[size];
    for (int i = 0; i < size; i++){
        if (i <= posOfLastElement){
            tmp[i].word = array[i].word;
            tmp[i].appearances = array[i].appearances;
        } else {
            tmp[i].word = " ";
            tmp[i].appearances = 0;
        }
    }
    delete[] array;
    array = tmp;
}

bool UnsortedArray::search(string key, int &apps) {
    int pos = search(key);
    if (pos != -1) {
        apps = array[pos].appearances;
        return true;
    } else
        return false;
}