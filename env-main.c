#include "shell.h"
#define l(x) _strlen((x))
#define cch const char

/**
 * _putenv - write to the environment variables
 * @es: environ, variable, value arg pair
 * Return: 0 on success and -1 on faliure
 */
int _putenv(char *es)
{
	char **_environ = environ, **newenviron, **_newenviron;
	char *var = strtok(es, "="), *value = strtok(NULL, "=");
	char *newvar = (char *)malloc(strlen(var) + strlen(value) + 2);
	int len = 0;

	while (*_environ)
	{
		len++;
		_environ++;
	}

	newenviron = (char **)malloc(sizeof(char *) * (len + 2));

	_environ = environ;
	_newenviron = newenviron;
	while (len)
	{
		*_newenviron = strdup(*_environ);
		_newenviron++, _environ++, len--;
	}

	var = strtok(es, "=");
	value = strtok(NULL, "=");
	newvar = (char *)malloc(strlen(var) + strlen(value) + 2);

	strcpy(newvar, var);
	strcat(newvar, "=");
	strcat(newvar, value);

	*_newenviron = newvar;
	_newenviron++;

	*_newenviron = NULL;

	free(environ);
	environ = newenviron;

	free(es);

	return (0);
}

int _setenv(const char *name, const char *value, int overwrite);

/**
 * _setenv - set the environment variables
 * @name: variable name
 * @value: value
 * @overwrite: overwrite the status
 *
 * Return: 0 on success -1 on faliure.
 */
int _setenv(const char *name, const char *value, int overwrite)
{
	char *es, **ep, *var;
	int i = 0;

	if (name == NULL || name[0] == '\0' || value == NULL)
		return (-1);
	if (environ)
	{
		ep = environ;
		while (ep[i])
		{
			var = strtok(ep[i], "=");
			if (var != NULL && strcmp(var, name) == 0)
			{
				if (overwrite)
				{
					free(environ[i]);
					environ[i] = (char *)malloc(strlen(name) + strlen(value) + 2);

					if (environ[i] == NULL)
						return (-1);
					strcpy(environ[i], name);
					strcat(environ[i], "=");
					strcat(environ[i], value);
					return (0);
				}
				return (0);
			}
			i++;
		}
	}
	es = (char *)malloc(strlen(name) + strlen(value) + 2);

	if (es == NULL)
		return (-1);
	strcpy(es, name);
	strcat(es, "=");
	strcat(es, value);
	if (_putenv(es) != 0)
	{
		free(es);
		return (-1);
	}
	return (0);
}
/**
 * _unsetenv - delete the environment variables.
 * @name: varable name
 * Return: 0 on success and -1 on faliure.
 */

int _unsetenv(const char *name)
{
	char **env, **next, *var;

	if (name == NULL || name[0] == '\0')
	{
		return (-1);
	}
	for (env = environ; *env != NULL; ++env)
	{
		var = strtok(*env, "=");

		if (var != NULL && strcmp(var, name) == 0)
		{
			for (next = env; *next != NULL; ++next)
			{
				*next = *(next + 1);
			}
			putenv(*env);
			return (0);
		}
	}
	return (-1);
}

/**
 * _printenv - print the environment variables
 */

void _printenv(void)
{
	char **env = environ;

	if (!env)
	return;

	while (*env)
	{
		printf("%s\n", *env);
		env++;
	}
}
