// Hash table implementation file
// Author: Andy R.
// Date: 5/12/2020

#include <stdio.h>
#include <stdlib.h>
#include "hash_table.h"
#include "hash_functions.h"

// Hash table constructor
bool ht_init(ht_inst *instance, int size) {
    printf("Initializing hash table...\n");
    // Initialize dynamically allocated array of "size"
    instance->ht = malloc(sizeof(node *) * size);

    // Initialize all hash table values to some default value (for checking if bucket is empty)
    for (size_t i = 0; i < size; ++i) {
        instance->ht[i] = malloc(sizeof(node));
        instance->ht[i]->key = -1;
        instance->ht[i]->value = -1;
        //printf("key: %d value: %d \n", instance->ht[i]->key, instance->ht[i]->value);
    }
    // Initialize size value
    instance->ht_size = size;

    printf("success\n");
    return true;
}

// ht insert method
bool insert(ht_inst *instance, int key, int value) {
    if (instance->ht_size == 0) { // If hash table is empty, fail
        printf("failure\n");
        return false;
    }

    int iter = 0;
    int hash_val = 0;

    while (iter != instance->ht_size - 1) {
        hash_val = double_hash(key, instance->ht_size, iter);
        if (instance->ht[hash_val]->key == -1) { // Key not occupied in hash table
            instance->ht[hash_val]->key = key;
            instance->ht[hash_val]->value = value;
            printf("success\n");
            return true;
        }

        if (instance->ht[hash_val]->key == key) { // Value already exists in hash table
            instance->ht[hash_val]->value = value; // Override previous value stored at key
            printf("failure \n");
            return false;
        }
        ++iter;
    }

    printf("failure\n");
    return false;
}

// ht search method
bool search(ht_inst *instance, int key) {
    if (instance->ht_size == 0) { // If hash table is empty
        printf("failure\n");
        return false;
    }

    int iter = 0;
    int hashed_key = 0;

    while (iter != instance->ht_size - 1) { // Iterate through all elements of the hash table to find the node with the param key
        hashed_key = double_hash(key, instance->ht_size, iter);
        if (instance->ht[hashed_key]->key == key) {
            printf("found key: %d with value: %d\n", instance->ht[hashed_key]->key, instance->ht[hashed_key]->value);
            return true;
        }
        ++iter;
    }

    return false; // Key not found
}

// ht delete
bool delete(ht_inst *instance, int key) {
    if (instance->ht_size == 0) {
        printf("failure\n");
        return false;
    }

    int iter = 0;
    int hashed_key = 0;

    while (iter != instance->ht_size - 1) { // Iterate through the hash table for the node to be deleted
        hashed_key = double_hash(key, instance->ht_size, iter);
        if (instance->ht[hashed_key]->key == key) { // Reset the node back to default "empty" values
            instance->ht[hashed_key]->key = -1;
            instance->ht[hashed_key]->value = -1;
            printf("success\n");
            return true;
        }
        ++iter;
    }

    return false; // Key not found.
}

// ht destructor
bool ht_dest(ht_inst *instance) {
    printf("Destructing hash table...\n");
    if (instance->ht_size == 0) { // If empty then do nothing
        printf("success\n");
        return true;
    }

    // Free all node pointers of hash table
    for (size_t i = 0; i < instance->ht_size; ++i) {
        free(instance->ht[i]);
    }

    free(instance->ht); // Free hash table pointer
    instance->ht_size = 0;

    printf("success\n");
    return true;
}