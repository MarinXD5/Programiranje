#include <stdio.h>
#include <stdlib.h>

void mystrcpy(char* stringp, char* stringd)
{
	int i = 0;

	while (stringd[i] != '\0')
	{
		stringp[i] = stringd[i];
		i++;
	}

	stringp[i] = '\0';
}

int main()
{


	char stringp[1000], stringd[1000];

	printf("Unesite prvi string: \n");
	gets(stringp);

	printf("Unesite drugi string: \n");
	gets(stringd);

	mystrcpy(stringp, stringd);

	printf("Kopirani drugi string u prvi je: %s", stringp);

	return 0;
}
