#ifndef SIMPLE_SHELL
#define SIMPLE_SHELL

extern char **environ;

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <fcntl.h>

#define BUFFER_t 1024


/**
 * struct cmdnode -  node for one command in a command list
 * @cmd: command string
 * @op: operation between current command and next command
 * @estat: exit status ( to show if the command has been excuted or not)
 * @next:  pointer to the next operand
 */

typedef struct cmdnode
{
	char *cmd;
	char *op;
	int estat;
	struct cmdnode *next;
} cmdnode;

/**
 * struct alias -  node for 1 alias
 * @key: the alais
 * @value: value of the alias
 * @next:  pointer to the next alias
 */

typedef struct alias
{
	char *key;
	char *value;
	struct alias *next;
} alias;

char *_getenv(const char *name);
int _putenv(char *es);
int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(const char *name);
void _printenv(void);

char _strtok(const char *str, char delimeter);

#endif
