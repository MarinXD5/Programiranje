#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <malloc.h>

int** podijeli(int* niz, int n) {
	int** nizovi = malloc(2 * sizeof(int*));
	nizovi[0] = malloc((n / 2) * sizeof(int));
	nizovi[1] = malloc((n / 2) * sizeof(int));

	for (int i = 0; i < n / 2; i++) {
		nizovi[0][i] = niz[i];
	}

	for (int i = 0; i < n / 2; i++) {
		nizovi[1][i] = niz[i + (n / 2)];
	}
	return nizovi;
}

int main() {
	int n;
	printf("Unesite duljinu niza: ");
	scanf("%d", &n);

	if (n % 2 != 0) {
		return -1;
	}
	else if (n % 2 == 0){
		int* niz = malloc(n * sizeof(int));

		printf("Unesite elemente niza: ");
		for (int i = 0; i < n; i++) {
			scanf("%d", &niz[i]);
		}

		int** nizovi = malloc(2 * sizeof(int*));
		nizovi[0] = malloc((n / 2) * sizeof(int));
		nizovi[1] = malloc((n / 2) * sizeof(int));

		nizovi = podijeli(niz, n);
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < n / 2; j++) {
				printf("%d ", nizovi[i][j]);
			}
		}
	}

	return 0;
}