#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <malloc.h>

int* filtriraj(int* niz, int n, int th, int* nth) {
	int* novi_niz = malloc(sizeof(int));
	int j = 0;
	
	for (int i = 0; i < n; i++) {
		if (niz[i] < th) {
			novi_niz = realloc(novi_niz, (j + 1) * sizeof(int));
			novi_niz[j] = niz[i];
			j++;
		}
	}
	*nth = j;

	return novi_niz;
}

int main() {
	int niz[] = { 3,6,2,7,5,9,8 };
	int th, nth;
	printf("Unesite threshold: ");
	scanf("%d", &th);

	int n = sizeof(niz)/sizeof(niz[0]);

	int* a = malloc(n * sizeof(int));

	a = filtriraj(niz, n, th, &nth);

	printf("Duljina novog niza je: %d", nth);
	printf("\n");

	printf("Novi niz je: ");
	for (int i = 0; i < nth; i++) {
		printf("%d ", a[i]);
	}

	return 0;
}