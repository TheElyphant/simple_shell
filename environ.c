#include "shell.h"

/**
* main - print the environ.
*
* Return: 0
*/

int main(void)
{
	int i = 0;

	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		i++;
	}
	return (0);
}
