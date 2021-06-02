#include "UnsortedArray.h"

/*
Δημιουργία πίνακα τύπου Element (struct) μεγέθους 1000 θέσεων
ενώ παράλληλα αρχικοποίηση σε κάθε θέση του πίνακα,
μια κενή λέξη για το word και την τιμή μηδέν (0) στο appearances.
*/
UnsortedArray::UnsortedArray() {
    size = 1000;
    posOfLastElement = 0;
    array = new Element[size];
    for (int i = 0; i < size; i++) {
        array[i].word = " ";
        array[i].appearances = 0;
    }
}

// ελευθερώνει την μνήμη που έχει χρησιμοποιηθεί για τον πίνακα.
UnsortedArray::~UnsortedArray() {
    delete[] array;
}

/*
Πρόκειται για την μέθοδο αναζήτησης που χρησιμοποιείται από τον χρήστη.
Εάν η λέξη εμφανίζεται μέσα στον πίνακα επιστρέφεται ο αριθμός των εμφανίσεων διαφορετικά, επιστρέφεται η τιμή 0
*/
int UnsortedArray::search(string key) {
    int pos = serialSearch(key);
    if (pos == -1)
        return 0;
    else
        return array[pos].appearances;
}

/*
Η μέθοδος που πραγματοποιεί την εισαγωγή κάθε λέξης μέσα στον πίνακα.
Αρχικά βρίσκει εάν η λέξη υπάρχει ήδη (κλήση της serach για αυτό τον σκοπό),
εάν όχι τοποθετεί την λέξη στο τέλος του πίνακα. Αντίθετα εάν η λέξη βρεθεί στον πίνακα,
αυξάνεται η τιμή της appearances της συγκεκριμένης λέξης κατά ένα (1).
Τέλος, ελέγχεται εάν ο πίνακας έχει γεμίσει, σε περίπτωση που έχει γεμίσει καλείται η resize.
*/
void UnsortedArray::insert(string key) {
    if (posOfLastElement < size) {
        int pos = serialSearch(key);
        if (pos == -1) {
            posOfLastElement++;
            array[posOfLastElement].word = key;
            array[posOfLastElement].appearances = 1;
        } else
            array[pos].appearances++;
    }
    if (abs(posOfLastElement-size) == 1)
        resize();
}

/*
Η μέθοδος που πραγματοποιεί την διαγραφή κάποιας λέξης μέσα από τον πίνακα μόνο όταν η λέξη είναι υπάρχων.
Εάν η λέξη εμφανίζεται παραπάνω από μια φορά, μετα την κλήση της remove η appearances μειώνεται κατά ένα (1),
ενώ εάν η λέξη εμφανίζεται μόνο μια φορά, μετα την κλήση της remove η λέξη διαγράφεται
από τον πίνακα και τα υπόλοιπα στοιχεία μετακινούνται κατά μια θέση προς τα αριστερά.
*/
bool UnsortedArray::remove(string key) {
    int pos = serialSearch(key);
    if (pos != -1) {
        posOfLastElement--;
        for (int i = pos; i < posOfLastElement; i++)
            array[i] = array[i + 1];
        return true;
    } else
        return false;
}

/*
Καλείται μόνο όταν ο πίνακας έχει γεμίσει από στοιχεία,
ουσιαστικά διπλασιάζει το μέγεθος του πίνακα δημιουργώντας
έτσι ελεύθερο χώρο για την εισαγωγή και άλλων στοιχειών.
*/
void UnsortedArray::resize() {
    size *= 2;
    Element *tmp = new Element[size];
    for (int i = 0; i < size; i++) {
        if (i <= posOfLastElement) {
            tmp[i].word = array[i].word;
            tmp[i].appearances = array[i].appearances;
        } else {
            tmp[i].word = " ";
            tmp[i].appearances = 0;
        }
    }
    delete[] array;
    array = tmp;
}

// Η μέθοδος που πραγματοποιεί την (σειριακή) αναζήτηση κάποιας λέξης μέσα στο πίνακα.
int UnsortedArray::serialSearch(string key) {
    int pos = -1;
    for (int i = 0; i < posOfLastElement && pos == -1; i++) {
        if (array[i].word == key)
            pos = i;
    }
    return pos;
}
