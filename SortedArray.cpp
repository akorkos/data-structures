#include "SortedArray.h"

SortedArray::SortedArray(int size){
    this->size = size;
    posOfLastElement = 0;
    array = new Element[size];
    for (int i = 0; i < size; i++){
        array[i].word = " ";
        array[i].appearances = 0;
    }
}

SortedArray::~SortedArray() {
    delete[] array;
}

int SortedArray::search(string key) {
    int first = 0, last = posOfLastElement;
    while (first <= last) {
        int mid = (first + last) / 2;
        if (array[mid].word == key)
            return mid;
        if (array[mid].word < key)
            first = mid + 1;
        else
            last = mid - 1;
    }
    return -1;
}

int SortedArray::insert(string key, bool &found) {

    int first = 0, last = posOfLastElement - 1, mid;

    while (true) {
        mid = (first + last) / 2;
        if (posOfLastElement == 0)
            return mid;
        if (array[mid].word == key) {
            found = true;
            return mid;
        } else if (array[mid].word < key) {
            first = mid + 1;
            if (first > last)
                return mid + 1;

        } else {
            last = mid - 1;
            if (first > last)
                return mid;
        }
    }
}

void SortedArray::insert(string key) {
    bool found = false;
    int j = insert(key, found);
    if (found)
        array[j].appearances++;
    else {
        for (int i = posOfLastElement; i > j; i--)
            array[i] = array[i - 1];
        array[j].word = key;
        array[j].appearances = 1;
        posOfLastElement++;
    }
}

bool SortedArray::search(string key, int &apps) {
    int pos = search(key);
    if (pos != -1) {
        apps = array[pos].appearances;
        return true;
    }
    else
        return false;
}

bool SortedArray::remove(string key) {
    int pos = search(key);
    if (pos != -1){
        if (array[pos].appearances > 1)
            array[pos].appearances--;
        else {
            posOfLastElement--;
            for (int i = pos; i < posOfLastElement; i++)
                array[i] = array[i+1];
        }
        return true;
    }else
        return false;
}


