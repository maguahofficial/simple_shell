#include "shell.h"

/**
 * get_environ - function returns the string array copy of our environ
 * @info: (pointer)Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: this returns always 0
 * getenv.c file simple_shell task
 */
char **get_environ(info_t *info)
{
	if (!info->environ || info->env_changed)
	{
		info->environ = list_to_strings(info->env);
		info->env_changed = 0;
	}

	return (info->environ);
}
/**
 * _unsetenv - function Removes an environment variable
 * @info: (pointer)Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: returns 1 on delete, 0 otherwise
 * getenv.c file simple shell tesk
 * @var: (char pointer)the string env var property
 */
int _unsetenv(info_t *info, char *var)
{
	list_t *nodelst_tvariable = info->env;
	size_t isze_tvarble = 0;
	char *pcharvarble;

	if (!nodelst_tvariable || !var)
		return (0);

	while (nodelst_tvariable)
	{
		pcharvarble = starts_with(nodelst_tvariable->str, var);
		if (pcharvarble && *pcharvarble == '=')
		{
			info->env_changed = delete_node_at_index(&(info->env), isze_tvarble);
			isze_tvarble = 0;
			nodelst_tvariable = info->env;
			continue;
		}
		nodelst_tvariable = nodelst_tvariable->next;
		isze_tvarble++;
	}
	return (info->env_changed);
}
/**
 * _setenv - function initializes a new environment variable,
 * or modifies an existing one
 * @info: (pointer)Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * @var: (char pointer)string env var property
 * @value: (char pointer)string env var value
 * getenv.c file in simple shell task
 *  Return: this returns always 0
 */
int _setenv(info_t *info, char *var, char *value)
{
	char *bufcharvarble = NULL;
	list_t *nodelst_tvarble;
	char *pcharvarble;

	if (!var || !value)
		return (0);

	bufcharvarble = malloc(_strlen(var) + _strlen(value) + 2);

	if (!bufcharvarble)
		return (1);

	_strcpy(bufcharvarble, var);
	_strcat(bufcharvarble, "=");
	_strcat(bufcharvarble, value);
	nodelst_tvarble = info->env;
	while (nodelst_tvarble)
	{
		pcharvarble = starts_with(nodelst_tvarble->str, var);
		if (pcharvarble && *pcharvarble == '=')
		{
			free(nodelst_tvarble->str);
			nodelst_tvarble->str = bufcharvarble;
			info->env_changed = 1;
			return (0);
		}
		nodelst_tvarble = nodelst_tvarble->next;
	}
	add_node_end(&(info->env), bufcharvarble, 0);
	free(bufcharvarble);
	info->env_changed = 1;

	return (0);
}
