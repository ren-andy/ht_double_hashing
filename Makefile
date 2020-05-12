all: ht_doublehash

ht_doublehash: main.c hash_table.c hash_table.h hash_functions.h
	gcc -o ht_test main.c hash_table.c hash_table.h hash_functions.h

clean:
	rm *.o ht_test ht_test.exe