#include "shell.h"

/**
* main - truncate string
*
* Return: 0
*/

int main(void)
{
	char *str = "This is a seperated word by spaces";
	char *stc = malloc(sizeof(char) * strlen(str));
	char delim[5] = " ";
	char *trunks;
	int i;

	strcpy(stc, str);
	trunks = strtok(stc, delim);
	/*printf("%p\n %p\n", str, trunks);*/

	while (trunks != NULL)
	{
		printf("%s\n", trunks);
		trunks = strtok(NULL, delim);
	}

	for (i = 0; i < 35; i++)
	{
		if (stc[i] == '\0')
			printf("\\0");
		else
		printf("%c", stc[i]);
	}

	return (0);
}
