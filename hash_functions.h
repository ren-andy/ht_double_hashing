// Hash functions header file
// Author: Andy R.
// Date: 5/12/2020

int double_hash(int value, int ht_size, int i);
int h1(int value, int ht_size);
int h2(int value, int ht_size);

int double_hash(int value, int ht_size, int i) {
    return (h1(value, ht_size) + i*h2(value, ht_size)) % ht_size;
}

int h1(int value, int ht_size) {
    return value % ht_size;
}

int h2(int value, int ht_size) {
    return 7 - (value % 7);
}