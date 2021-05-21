#include "SortedArray.h"

SortedArray::SortedArray(int len) : UnsortedArray(size) {
    size = len;
}

SortedArray::~SortedArray() {

}

int SortedArray::search(string key) {
        int first = 0, last = size;
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
