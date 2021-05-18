#include <iostream>
#include <fstream>

#include "BinaryTree.h"

using namespace std;

int wordCounter(string filename){
    string word;
    fstream file;
    int count = 0;

    file.open(filename.c_str());

    while (file >> word)
        count++;

    file.close();

    return count;
}

int main() {
    string filename = "test.txt";
    //int i = 0,
    int k;
    string word;
    fstream file;
    string t = "\000";
   // int N = wordCounter(filename);
   // string *Array = new string[N];

    file.open(filename.c_str());

    BinaryTree b;

   while (file >> word){
        for (int j = 0;  word[j] != '\0'; j++) {
            word[j] = tolower(word[j]);
            while (!(word[j] >= 'a' && word[j] <= 'z' || word[j] == '\0')) { //des ti fash me : ktl na mi menoyn kena
                for (k = j; word[k] != '\0'; k++)
                    word[k] = word[k + 1];
                word[k] = '\0';
            }
        }
        b.insert(word);
       // Array[i++] = word;
    }
   b.deleteNode(b.root, "a");
   b.inorder_print();

    file.close();

   /*
    for (i = 0; i < N; i++)
        cout << Array[i] << endl;
        */

    return 0;
}
