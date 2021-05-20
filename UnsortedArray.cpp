#include "UnsortedArray.h"
#include <iostream>

UnsortedArray::UnsortedArray() {
    array = NULL;
}

/*
UnsortedArray::UnsortedArray(int k) {

}
*/

UnsortedArray::~UnsortedArray() {

}

Element *UnsortedArray::search(Element *array, int n, string key) {
    int i;
    for (i = 0; i < n; i++)
        if (array->word == key){
            return array;
        }

    return NULL;
}

// Inserts a key in Array->word a of given capacity.
// n is current size of Array *a. This
// function returns n + 1 if insertion
// is successful, else n.
int UnsortedArray::insert(Element *array, int n, string key, int capacity)
{

    // Cannot insert more elements if n is
    // already more than or equal to capcity
    if (n >= capacity)
        return n;

   // arr[n] = key;
    array->word = key;
    array->appearances = 1;

    return (n + 1);
}

//koita auto me appearances
int UnsortedArray::deleteElement(Element *array, int n, string key){

    // Find position of element to be deleted
  //  int pos = search(current, n, key);

    Element *newElement = search(array, n, key);
    if (newElement==NULL)
    {
        cout << "Element not found";
        return n;
    }


    // Deleting element
   else{

   }
   // for (i = pos; i < n - 1; i++)
     //   arr[i] = arr[i + 1];

    return n - 1;
}