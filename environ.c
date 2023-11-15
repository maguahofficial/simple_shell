#include "shell.h"

/**
 * _myenv - function prints the current environment
 * @info: (pointer) Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * environ.c file in the simple_shell task
 * Return: This Always Returns 0
 */
int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * _getenv - function gets the value of an environ variable
 * @info: (pointer) Structure containing potential arguments. Used to maintain
 * @name: (pointer) env var name
 * environ.c file in the simple_shell task
 * Return: returns the value
 */
char *_getenv(info_t *info, const char *name)
{
	list_t *nodevarble = info->env;
	char *pvarble;

	while (nodevarble)
	{
		pvarble = starts_with(nodevarble->str, name);
		if (pvarble && *pvarble)
			return (pvarble);
		nodevarble = nodevarble->next;
	}
	return (NULL);
}

/**
 * _mysetenv - function Initialize a new environment variable,
 * or modify an existing one
 * @info: (pointer) Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * environ.c file inthe simple_shell task
 *  Return: This Always Returns 0
 */
int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenv - function Remove an environment variable
 * @info: (pointer) Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: This Always Returns 0
 */
int _myunsetenv(info_t *info)
{
	int ivarble;

	if (info->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (ivarble = 1; ivarble <= info->argc; ivarble++)
		_unsetenv(info, info->argv[ivarble]);

	return (0);
}

/**
 * populate_env_list - function populates env linked list
 * @info: (pointer) Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * environ.c file in the simple_shell task
 * Return: This Always Returns 0
 */
int populate_env_list(info_t *info)
{
	list_t *nodevarble = NULL;
	size_t ivarble;

	for (ivarble = 0; environ[ivarble]; ivarble++)
		add_node_end(&nodevarble, environ[ivarble], 0);
	info->env = nodevarble;
	return (0);
}
