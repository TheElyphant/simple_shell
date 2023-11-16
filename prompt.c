#include "shell.h"

/**
 * get_user_input - Get user input from stdin
 *
 * Return: The user input as a dynamically allocated string
 */
char *get_user_input(void)
{
	size_t n = 0;
	char *buf = NULL;

	printf("$ ");
	getline(&buf, &n, stdin);
	printf("%s", buf);

	free(buf);

	return (0);
}
