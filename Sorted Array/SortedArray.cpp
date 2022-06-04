#include "SortedArray.h"

/*
Δημιουργία πίνακα τύπου Element (struct) μεγέθους 1000 θέσεων
ενώ παράλληλα αρχικοποίηση σε κάθε θέση του πίνακα,
μια κενή λέξη για το word και την τιμή μηδέν (0) στο appearances.
*/
SortedArray::SortedArray() {
    size = 1000;
    posOfLastElement = 0;
    array = new Element[size];
    for (int i = 0; i < size; i++) {
        array[i].word = " ";
        array[i].appearances = 0;
    }
}

// ελευθερώνει την μνήμη που έχει χρησιμοποιηθεί για τον πίνακα.
SortedArray::~SortedArray() {
    delete[] array;
}

/*
Πρόκειται για την μέθοδο αναζήτησης που χρησιμοποιείται από τον χρήστη.
H υλοποίηση της δυαδικής αναζήτησης.
*/
int SortedArray::binarySearch(string key) {
    int first = 0, last = posOfLastElement;
    while (first <= last) {
        int mid = (first + last) / 2;
        if (array[mid].word == key)
            return mid;
        if (array[mid].word < key)
            first = mid + 1;
        else
            last = mid - 1;
    }
    return -1;
}

/*
Πρόκειται για παραλλαγή της δυαδικής αναζήτησης. Σε περίπτωση που το στοιχείο βρίσκεται μέσα στον πίνακα
επιστρέφει την θέση του (εάν η found γίνει true), διαφορετικά επιστρέφει την θέση στην οποία
θα πρέπει να εισαχθεί το στοιχείο (η found γίνεται false).
*/
int SortedArray::insert(string key, bool &found) {
    int first = 0, last = posOfLastElement - 1, mid;
    while (true) {
        mid = (first + last) / 2;
        if (posOfLastElement == 0)
            return mid;
        if (array[mid].word == key) {
            found = true;
            return mid;
        } else if (array[mid].word < key) {
            first = mid + 1;
            if (first > last)
                return mid + 1;
        } else {
            last = mid - 1;
            if (first > last)
                return mid;
        }
    }
}

/*
Πρόκειται για την μέθοδο εισαγωγής που καλείται από τον χρήστη. Καλεί την insert για να μάθει ποια είναι η σωστή
θέση για να εισαχθεί η λέξη χωρίς να διαταράξει την ταξινόμηση των στοιχείων εφόσον η λέξη δεν υπάρχει στον πίνακα, ενώ
εάν η λέξη βρεθεί στον πίνακα, αυξάνεται η τιμή της appearances της συγκεκριμένης λέξης κατά ένα (1).
Τέλος, ελέγχεται εάν ο πίνακας έχει γεμίσει, σε περίπτωση που έχει γεμίσει καλείται η resize.
 */

void SortedArray::insert(string key) {
    bool found = false;
    int j = insert(key, found);
    if (found)
        array[j].appearances++;
    else {
        for (int i = posOfLastElement; i > j; i--)
            array[i] = array[i - 1];
        array[j].word = key;
        array[j].appearances = 1;
        posOfLastElement++;
        if (abs(posOfLastElement-size) == 1)
            resize();
    }
}

/*
Πρόκειται για την μέθοδο αναζήτησης που χρησιμοποιείται από τον χρήστη.
Εάν βρεθεί η λέξη μέσα στον πίνακα επιστρέφεται ο αριθμός εμφανίσεων της λέξης, εάν όχι επιστρέφεται η τιμή 0.
*/

int SortedArray::search(string key) {
    int pos = binarySearch(key);
    if (pos == -1)
        return 0;
    else
        return array[pos].appearances;
}

/*
Η μέθοδος που πραγματοποιεί την διαγραφή κάποιας λέξης μέσα από τον πίνακα μόνο όταν η λέξη είναι υπάρχων.
Εάν η λέξη εμφανίζεται παραπάνω από μια φορά, μετα την κλήση της remove η appearances μειώνεται κατά ένα (1),
ενώ εάν η λέξη εμφανίζεται μόνο μια φορά, μετα την κλήση της remove η λέξη διαγράφεται
από τον πίνακα και τα υπόλοιπα στοιχεία μετακινούνται κατά μια θέση προς τα αριστερά.
 */
bool SortedArray::remove(string key) {
    int pos = binarySearch(key);
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
void SortedArray::resize() {
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
