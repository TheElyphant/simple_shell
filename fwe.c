#include "shell.h"

/**
* main - fork + wait + execute
*
* Return: 0
*/

int main(void)
{
	pid_t child_pid;
	int status;
	int i;
	char *args[] = {"ls", "-l", "/tmp", NULL};

	for (i = 1; i <= 5; i++)
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error:");
			return (1);
		}
	}
	if (child_pid == 0)
	{
		execve("/usr/bin/ls", args, NULL);
		perror("Error:");
		exit(1);
	}
	else
	{
		wait(&status);
	}
	return (0);
}
