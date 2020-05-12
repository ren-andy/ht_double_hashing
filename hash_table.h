// Hash table header file
// Author: Andy R.
// Date: 5/12/2020

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Key-value node struct
typedef struct node {
    int key;
    int value;
} node;

// Doubly hashed hash table struct
typedef struct doubly_hashed_table {
    node **ht;
    int ht_size;

} ht_inst;


// ht constructor
bool ht_init(ht_inst *instance, int size);

// ht insert
bool insert(ht_inst *instance, int key, int value);

// ht search
bool search(ht_inst *instance, int key);

// ht delete
bool delete(ht_inst *instance, int key);

// ht destructor
bool ht_dest(ht_inst *instance);