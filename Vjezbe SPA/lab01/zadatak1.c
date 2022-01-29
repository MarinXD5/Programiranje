#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <malloc.h>

int* podniz(int* niz, int start, int stop) {
	int* pniz = malloc((stop - start) * sizeof(int));
	int i = 0;
	for (start; start <= stop; start++) {
		pniz[i] = niz[start];
		i++;
	}

	return pniz;
}

int main() {
	int start, stop, niz[] = { 3,6,2,7,5,9,8 };
	printf("Unesite pocetni index: ");
	scanf("%d", &start);

	printf("Unesite krajnji index: ");
	scanf("%d", &stop);

	if (start > stop) {
		printf("Pocetni index ne moze biti veci od krajnjeg...");
		return 0;
	}

	int* novi_niz = malloc((stop - start) * sizeof(int));

	novi_niz = podniz(niz, start, stop);
	for (int i = 0; i <= stop - start; i++) {
		printf("%d ", novi_niz[i]);
	}

	return 0;
}