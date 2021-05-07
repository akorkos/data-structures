#include <iostream>
#include <fstream>

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
    int i = 0, k;
    string word;
    fstream file;
    string t = "\000";
    int N = wordCounter(filename);
    string *Array = new string[N];

    file.open(filename.c_str());

   while (file >> word){
        for (int j = 0;  word[j] != '\0'; j++) {
            word[j] = tolower(word[j]);
            while (!(word[j] >= 'a' && word[j] <= 'z') &&  !(word[j] == '\0')) {
                for (k = j; word[k] != '\0'; k++)
                    word[k] = word[k + 1];
                word[k] = '\0';
            }
        }

        Array[i++] = word;
    }

    file.close();

    for (i = 0; i < N; i++)
        cout << Array[i] << endl;

    return 0;
}
