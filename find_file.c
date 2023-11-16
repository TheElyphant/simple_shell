#include "shell.h"

/**
* check_command - check command for file.
* @command: character pointer
* Return: none
*/
void check_command(char *command)
{
	if (access(command, F_OK) == 0)
		printf("%s: FOUND THE FILE\n", command);
	else
		printf("%s: FILE DOESN'T EXIST\n", command);
}

/**
* main - print command
*
* Return: 0
*/

int main(void)
{
	char *buffer = NULL;
	size_t buffer_size = 0;
	char *token;

	while (1)
	{
		write(1, "CISFUN$ ", 9);
		getline(&buffer, &buffer_size, stdin);
		token = strtok(buffer, " \t\n");
		if (strcmp(token, "which") == 0)
		{
			token = strtok(NULL, " \t\n");
			while (token)
			{
				check_command(token);
				token = strtok(NULL, " \t\n");
			}
		}
		else
		{
			write(1, "COMMAND DOESN'T EXIST\n", 23);
		}
	}
	return (0);
}
