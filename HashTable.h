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

    void insert(string key); //εισαγωγή λέξης στο hashtable
    int search(string key, int apps); //αναζήτηση λέξης στο hashtable

private:
    void insert(string key, bool done);
    int findAddress(string key);   //η συνάρτηση μέσω της οποίας βρίσκουμε διεύθυνση για την λέξη
    HashNode* search(string key);
    HashNode **root;
};

#endif //DOMES_DEDOMENWN_2021_HASHMAP_H
