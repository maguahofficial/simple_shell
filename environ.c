#include "shell.h"

/**
 * _myenv - function prints the current environment
 * @info: The structure containing potential arguments. Used to maintain
 * constant function prototype.
 * environ.c file in the simple shell
 * Return: This Always returns 0
 */

int _myenv(info_t *info)
{
	print_list_str(info->env);

	return (0);
}

/**
 * _getenv - function gets the value of an environ variable
 * @info: This structure containing potential arguments. Used to maintain
 * @name: The env var name
 *environ.c file in the simple shell
 * Return: Returns the value
 */

char *_getenv(info_t *info, const char *name)
{
	list_t *nodevarblelst = info->env;
	char *pchvarble;

	while (nodevarblelst)
	{
		pchvarble = starts_with(nodevarblelst->str, name);

		if (pchvarble && *pchvarble)
			return (pchvarble);

		nodevarblelst = nodevarblelst->next;
	}
	return (NULL);
}

/**
 * _mysetenv - function initialize a new environment varble,
 * or modify an existing one
 * @info: The structure containing potential argument.Used to maintain
 * constant function prototype.
 * environ.c file in the simple shell
 *  Return: This will returns Always 0
 */

int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect numb of arguements\n");

		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);

	return (1);
}

/**
 * _myunsetenv - function remove an environment variable
 * @info: The structure containing potential arguments. Used to maintain
 * constant function prototype.
 * environ.c file in the simple shell
 * Return: This will Always return 0
 */

int _myunsetenv(info_t *info)
{
	int ivariable;

	if (info->argc == 1)
	{
		_eputs("Too few arguements.\n");

		return (1);
	}
	for (ivariable = 1; ivariable <= info->argc; ivariable++)
		_unsetenv(info, info->argv[ivariable]);

	return (0);
}

/**
 * populate_env_list - function populates env linked list
 * @info: The structure containing potential arguments. Used to maintain
 * constant the function prototype.
 * environ.c file in simple shell
 * Return: This Always Returns 0
 */

int populate_env_list(info_t *info)
{
	list_t *nodevarblest = NULL;
	size_t iszeintvarble;

	for (iszeintvarble = 0; environ[iszeintvarble]; iszeintvarble++)
		add_node_end(&nodevarblest, environ[iszeintvarble], 0);
	info->env = nodevarblest;

	return (0);
}
