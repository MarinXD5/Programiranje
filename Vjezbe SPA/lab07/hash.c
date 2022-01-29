#include "hash.h"
#include <malloc.h>
#include <stdio.h>
#include <string.h>

#define HCONST 3567892

HashTable* NewTable(int size){
	// kreira novu hash tablicu (alocira samu strukturu i niz pokazivaèa)
	HashTable* tablica = (HashTable*)malloc(sizeof(HashTable));
	tablica->table = (Bin**)malloc(sizeof(Bin*) * size);
	tablica->size = size;

	int cnt = 0;

	//napravit ce novu tablica sve sa dummy headovima (jer ce se dodavati u glavu)
	while (cnt < size) {
		tablica->table[cnt] = (Bin*)malloc(sizeof(Bin));
		tablica->table[cnt]->word = NULL;
		tablica->table[cnt]->next = NULL;
	}

	return tablica;
}

unsigned int hashCode(char* word){
	// od kljuca generira hash kod
	unsigned int key = 0;
	while (*word != '\0')
	{
		key = key * HCONST + *word;
		word++;
	}
	return key;
}

void Insert(HashTable* ht, char* word){
	// dodaje novu rijec u listu na odgovarajucem pretincu

	unsigned int index = hashCode(word);
	index %= ht->size;

	Bin *novi = (Bin*)malloc(sizeof(Bin));
	novi->word = _strdup(word);
	Bin* temp = ht->table[index]->next;

	ht->table[index]->next = novi;
	novi->next = temp;
}

int Get(HashTable* ht, char* word){
	// vraca 0 ili 1 ovisno o tome da li rijec postoji u tablici
	unsigned int index = hashCode(word);
	index %= ht->size;
	Bin* temp = ht->table[index];

	
	if (temp->word == NULL && temp->next != NULL) {
		temp = temp->next;
	}

	while (temp->next != NULL) {
		if (!strcmp(word,temp->word)) {
			return 1;
		}

		temp = temp->next;
	}

	if (temp->word != NULL) {
		//provjerava zadnji uvjet
		if (!strcmp(word, temp->word)) {
			return 1;
		}
	}

	return 0;
}

void DeleteTable(HashTable* ht){
	// brise cijelu hash tablicu (liste na svim pretincima (rijec i element liste), pretince ...)
	int cnt = 0;

	while (cnt < ht->size) {
		while (ht->table[cnt]->next != NULL) {
			Bin* temp = ht->table[cnt];
			ht->table[cnt] = ht->table[cnt]->next;
			free(temp->word);
			free(temp);
		}
		cnt++;
	}

	free(ht->table);
	free(ht);
}