#include <stdio.h>

int mystrlen(char* string) {
	int duljina_stringa = 0;
	int i = 0;

	while (string[i] != '\0') {
		duljina_stringa++;
		i++;
	}

	return duljina_stringa;
}

int main() {

	int n;
	char string[] = "ABCDEFG";

	int rez = 0;

	rez = mystrlen(string);

	printf("Rez je %d", rez);


}