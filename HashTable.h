#ifndef HASHMAP_H
#define HASHMAP_H
#include <iostream>
#include <string>

using namespace std;

struct HashNode{
    string word;
    int address, appearances;
};

const int size = 100000;

class HashTable{
private:
    HashNode **root;
    int findAddress(string key);
public:
    HashTable();
    ~HashTable();
    void insert(string key);
    int search(string key);
};
#endif
