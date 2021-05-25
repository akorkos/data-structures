#include "UnsortedArray.h"

UnsortedArray::UnsortedArray(int size) {
    this->size = size;
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

//returns position
int UnsortedArray::search(string key, int position) {
    int pos = position;
    for (int i = 0; i < posOfLastElement && pos == -1; i++) {
        if (array[i].word == key) {
            pos = i;
        }
    }
    return pos;
}

//returns appearances
int UnsortedArray::search(string key) {
    int pos = search(key, -1);
    if (pos != -1) {
        return array[pos].appearances;
    }
    return -1;
}

void UnsortedArray::insert(string key) {
    if (posOfLastElement < size) {
        int pos = search(key, -1);
        if (pos == -1) {
            posOfLastElement++;
            array[posOfLastElement].word = key;
            array[posOfLastElement].appearances = 1;
        } else
            array[pos].appearances++;
    }
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

/*
bool UnsortedArray::search(string key, int &apps) {
    int pos = search(key);
    if (pos != -1) {
        apps = array[pos].appearances;
        return true;
    } else
        return false;
}
 */