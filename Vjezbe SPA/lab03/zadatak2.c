#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "header.h"

int cmpfun(const void* a, const void* b) {
	return (*(int*)a - *(int*)b);
}

void presjek_sortirani(int* skupA, int* skupB) {
	int* presjek_sortirani = (int*)malloc(20000000 * sizeof(int));
	int* trazeni;

	for (int i = 0; i < sizeof(skupA); i++) {
		int key = skupA[i];
		trazeni = (int*)bsearch(&key, skupB, sizeof(skupB), sizeof(int), cmpfun);

		if (trazeni != NULL) {
			presjek_sortirani[i] = trazeni;
		}
	}

	free(presjek_sortirani);
}

int main() {
	int* skupA = (int*)malloc(100000000 * sizeof(int));
	int* skupB = (int*)malloc(100000000 * sizeof(int));

	clock_t start, stop;
	double rez = 0;

	int n = 100000;
	for (int i = 0; i < 10; i++) {
		skupA = generiraj(n);
		skupB = generiraj(n);

		start = clock();
		qsort(skupB, n, sizeof(int), cmpfun);
		presjek_sortirani(skupA, skupB);
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