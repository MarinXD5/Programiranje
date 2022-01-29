#include <stdio.h>

void mystrcat(char* string1, char* string2) {
	int a = 0, b = 0;
	while (string1[a] != '\0') {
		a++;
	}

	while (string2[b] != '\0') {
		string1[a] = string2[b];
		a++;
		b++;
	}

	string1[a] = '\0';
}

int main() {
	char string1[] = "ABC", string2[] = "DEF";

	mystrcat(string1, string2);

	printf("Spojeni string je: \"%s\"\n", string1);

	return 0;
}