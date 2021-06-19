#ifndef HASHMAP_H
#define HASHMAP_H
#include <string>

using namespace std;

struct HashNode{
    string word;
    int address, appearances;
};

const int size=100000;

class HashTable{
private:
    void insert(string key, bool done);
    int findAddress(string key);   //η συνάρτηση μέσω της οποίας βρίσκουμε διεύθυνση για την λέξη
    HashNode *privSearch(string key);
    HashNode **root;
public:
    HashTable();
    ~HashTable();
    void insert(string key); //εισαγωγή λέξης στο hashtable
    int search(string key); //αναζήτηση λέξης στο hashtable
};
#endif
