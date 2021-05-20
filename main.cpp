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

void removeSpaces(char *str)
{
    // To keep track of non-space character count
    int count = 0;

    // Traverse the given string. If current character
    // is not space, then place it at index 'count++'
    for (int i = 0; str[i]; i++)
        if (str[i] != ' ')
            str[count++] = str[i]; // here count is
    // incremented
    str[count] = '\0';
}

int main() {
    string filename = "test.txt";
    int k;
    string word;
    fstream file;
    int pos;
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
            if (word[j] != ' ')
                pos = j;
        }
       word.resize(pos+1);
       /*if (word[word.length()-1] == ' ')
           word.resize(word.length()-2);*/

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
