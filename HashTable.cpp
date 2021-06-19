#include "HashTable.h"

HashTable::HashTable() {
    root = new HashNode *[N];
    for (int i = 0; i < N; i++) {
        root[i] = nullptr;
    }
}

HashTable::~HashTable() {
    for (int i = 0; i < N; i++) {
        delete root[i];
    }
}

int HashTable::findAddress(string key) {

    int address = 0;
    for (int i = 0; i < key.length(); i++) {
        address += key[i];
    }
    //ουσιαστικά μετατρέπουμε την λέξη σε αριθμό
    return address;
}

void HashTable::insert(string key) {
    //καταχωρούμε την διεύθυνση σαν αρχικό βήμα
    int step = findAddress(key);

    //μέχρι να βρει άδειο κόμβο ή κόμβο με την ίδια λέξη
    while ((root[step] != nullptr) && (root[step]->word != key)) {
        step++;
        step %= N;
    }

    if (root[step] == nullptr) { // άδειος κόμβος, βάζουμε μέσα τα στοιχεία
        root[step] = new HashNode;
        root[step]->address = step;
        root[step]->word = key;
        root[step]->appearances = 1;
    } else if (root[step]->address == step) { //  κόμβος με την ίδια λέξη, αυξάνουμε μετρητή
        root[step]->appearances++;
    }
}

HashNode* HashTable::privSearch(string key) {
    //ίδια διαδικασία με insert
    int step = findAddress(key);
    while ((root[step] != nullptr) && (root[step]->word != key)) {
        step++;
        step %= N;
    }
    //όταν βρεί την λέξη
    if (root[step]->address == step)
        return root[step]; //γυρνάμε πίσω τον μετρητή
    else
        return nullptr;
}

int HashTable::search(string key) {
    HashNode *pos = privSearch(key); //καλεί την αντίστοιχη private μέθοδο
    if (pos == nullptr) {
        return 0;
    } else
        return pos->appearances;
}
