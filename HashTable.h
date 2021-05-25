#ifndef HASHMAP_H
#define HASHMAP_H
#include <iostream>
#include <string>

using namespace std;

struct HashNode{
    string value;
    int address;
    int appearances;
};

const int size=100000;

class HashTable{
public:
    HashTable();
    ~HashTable();

    void insert(string key);
    int search(string key);

private:
    int findAddress(string key);
    HashNode **root;
};

#endif //DOMES_DEDOMENWN_2021_HASHMAP_H
