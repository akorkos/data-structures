#ifndef HASHMAP_H
#define HASHMAP_H
#include <string>

using namespace std;

struct HashNode{
    string word;
    int address;
    int appearances;
};

const int size=100000;

class HashTable{
public:
    HashTable();
    ~HashTable();

    void insert(string key);
    HashNode* search(string key);
    HashNode **getRoot(){return root;}

private:
    int findAddress(string key);
    HashNode **root;
};

#endif //DOMES_DEDOMENWN_2021_HASHMAP_H
