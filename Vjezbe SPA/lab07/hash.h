#ifndef HASH_H
#define HASH_H

typedef struct Bin {
	char* word;
	struct Bin* next;
} Bin;

typedef struct {
	Bin** table;
	int size, load; //moguce fizicka i logicka velicina
} HashTable;

HashTable* NewTable(int size);

unsigned int hash(char* word);

void Insert(HashTable* ht, char* word);

int Get(HashTable* ht, char* word);

void DeleteTable(HashTable* ht);

#endif