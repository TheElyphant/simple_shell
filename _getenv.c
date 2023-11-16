#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
* _getenv - homevalue of the environ.
* @name: the name og the environ.
* Return: NULL.
*/
char *_getenv(const char *name)
{
	int i;
	char *token;

	i = 0;
	while (environ[i])
	{
		token = strtok(environ[i], "=");
		if (strcmp(token, name) == 0)
		{
			return (strtok(NULL, "="));
		}
		i++;
	}
	return (NULL);
}

/**
* main - get homevalue.
*
* Return: 0
*/
int main(void)
{
	char *homevalue = _getenv("HOME");

	printf("%s\n", homevalue);
	return (0);
}
