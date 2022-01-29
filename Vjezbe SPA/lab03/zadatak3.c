#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "header.h"

int cmpfun(const void* a, const void* b) {
	return (*(int*)a - *(int*)b);
}

void presjek_oba_sortirana(int* skupA, int* skupB) {
	int* presjek = (int*)malloc(100000000 * sizeof(int));
	int k = 0;

	for (int i = 0; i < sizeof(skupA); i++) {
		for (int j = 0; j < sizeof(skupB); j++) {
			if (skupA[i] == skupB[j]) {
				presjek[k] = skupA[i];
				k++;
			}
		}
	}

	free(presjek);
}


int main() {
	int* skupA = (int*)malloc(100000000 * sizeof(int));
	int* skupB = (int*)malloc(100000000 * sizeof(int));
	int n = 100000;
	time_t start, stop;
	double rez = 0;



	for (int i = 0; i < 10; i++) {
		skupA = generiraj(n);
		skupB = generiraj(n);

		start = clock();
		qsort(skupA, n, sizeof(int), cmpfun);
		qsort(skupB, n, sizeof(int), cmpfun);
		presjek_oba_sortirana(skupA, skupB);
		stop = clock();

		n += 300000;

		rez = ((double)(stop - start) / CLOCKS_PER_SEC);
		printf("---------------\n");
		printf("%f\n", rez);
		printf("---------------\n\n");

	}
	free(skupA);
	free(skupB);

}