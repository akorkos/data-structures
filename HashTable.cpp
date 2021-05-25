#include "HashTable.h"

HashTable::HashTable() {
    root = new HashNode *[size];
    for (int i = 0; i < size; i++) {
        root[i] = nullptr;
    }
}

HashTable::~HashTable() {
    for (int i = 0; i < size; i++) {
        delete root[i];
    }
}

int HashTable::findAddress(string key) {

    int address = 0;
    for (int i = 0; i < key.length(); i++) {
        address += key[i];
    }
    return address;
}

void HashTable::insert(string key) {
    int step = findAddress(key);

    while ((root[step] != nullptr) && (root[step]->value != key)) {
        step++;
        step %= size;
    }
    if (root[step] == nullptr) {
        root[step] = new HashNode;
        root[step]->address = step;
        root[step]->value = key;
        root[step]->appearances = 1;
    } else if (root[step]->address == step) {
        root[step]->appearances++;
    }
}

int HashTable::search(string key) {
    int step = findAddress(key);
    while ((root[step] != nullptr) && (root[step]->value != key)) {
        step++;
        step %= size;
    }
    if (root[step]->address == step)
        return root[step]->appearances;
    else
        return 0;
}