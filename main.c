// Hash table test file
// Date: 5/12/2020

#include "hash_table.h"

int main() {

    ht_inst *inst = malloc(sizeof(ht_inst));

    ht_init(inst, 9);
    insert(inst, 123, 10000);
    insert(inst, 122, 1234);
    search(inst, 123);
    delete(inst, 122);
    ht_dest(inst);
    free(inst);

    return 0;
}