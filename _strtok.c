#include "shell.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
* _strtok - tokenize string.
* @str: string to be tokenized.
* @delimeter: token delimeter.
* Return: character pointer
*/

char _strtok(const char *str, char delimeter)
{
	int len = strlen(str);
	int i, j;
	char numwords[100];

	for (i = 0; i <= len; i++)
	{
		j = 0;
		if (str[i] == delimeter || str[i] == '\0')
			numwords[j] = '\0';
		if (j > 0)
		{
			printf("%s\n", numwords);
			j = 0;
		}
		else
		{
			numwords[j++] = str[i];
		}
	}
	return (0);
}
