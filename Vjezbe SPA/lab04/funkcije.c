#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "Source.h"

Dictionary create() {
	Dictionary dict = (Dictionary)malloc(sizeof(Word));
	dict->count = 0;
	dict->word = "";
	dict->next = NULL;

	return dict;
}

void print(Dictionary dict){
	Dictionary tmp = dict->next;
	while (tmp != NULL){
		printf("%s: %d\n", tmp->word, tmp->count);
		tmp = tmp->next;
	}
}

int filter(Word* w) {
	if ((w->count >= 5 && w->count <= 10) && (strlen(w->word) > 3)){
		return 1;
	}
}

Dictionary filterDictionary(Dictionary indict, int (*filter)(Word* w)) {
	Dictionary tmp = indict;

	while (tmp->next != NULL) {
		if (filter(tmp->next)) {
			tmp = tmp->next;
		}
		else {
			Dictionary tmp1 = tmp->next;
			tmp->next = tmp1->next;
			free(tmp1);
		}
	}

	return indict;
}

void destroy(Dictionary dict) {

	Dictionary tmp;

	while (dict) {
		tmp = dict;
		dict = dict->next;
		free(tmp);
	}
}

void add(Dictionary dict, char* str) {
	Dictionary tmp = dict;

	if (dict == NULL) {
		return;
	}

	while (tmp != NULL) {
		if (strcmp(str, tmp->word)==0) {
			tmp->count+=1;
			break;
		}
		else if (strcmp(str, tmp->word) > 0 && strcmp(str, tmp->word) < 0) {
			Dictionary node = (Dictionary)malloc(sizeof(Word));
			node->word = _strdup(str);
			node->count = 0;
			node->next = tmp->next;
			tmp->next = node;
		}
		else if (tmp->next == NULL) {
			Dictionary node = (Dictionary)malloc(sizeof(Word));
			node->word = _strdup(str);
			node->count = 0;
			node->next = tmp->next;
			tmp->next = NULL;
		}
		tmp = tmp->next;
	}
}