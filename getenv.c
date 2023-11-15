#include "shell.h"

/**
 * get_environ - function returns the string array copy of our environ
 * @info: (pointer) Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * getenv.cfile inthe simple_shell task
 * Return: This function Always Returns 0
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
 * _unsetenv - function Remove an environment variable
 * @info: (pointer) Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * getenv.cfile inthe simple_shell task
 * Return: This Returns 1 on delete, 0 otherwise
 * @var: (pointer) the string env var property
 */
int _unsetenv(info_t *info, char *var)
{
	list_t *nodevarbel = info->env;
	size_t ivarbel = 0;
	char *pvarbel;

	if (!nodevarbel || !var)
		return (0);

	while (nodevarbel)
	{
		pvarbel = starts_with(nodevarbel->str, var);
		if (pvarbel && *pvarbel == '=')
		{
			info->env_changed = delete_node_at_index(&(info->env), ivarbel);
			ivarbel = 0;
			nodevarbel = info->env;
			continue;
		}
		nodevarbel = nodevarbel->next;
		ivarbel++;
	}
	return (info->env_changed);
}

/**
 * _setenv - function Initialize a new environment variable,
 * or modify an existing one
 * @info: (pointer) Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * getenv.cfile inthe simple_shell task
 * @var: (pointer) the string env var property
 * @value: (pointer) the string env var value
 *  Return: This function Always returns 0
 */
int _setenv(info_t *info, char *var, char *value)
{
	char *bufvarbel = NULL;
	list_t *nodevarbel;
	char *pvarbel;

	if (!var || !value)
		return (0);

	bufvarbel = malloc(_strlen(var) + _strlen(value) + 2);
	if (!bufvarbel)
		return (1);
	_strcpy(bufvarbel, var);
	_strcat(bufvarbel, "=");
	_strcat(bufvarbel, value);
	nodevarbel = info->env;
	while (nodevarbel)
	{
		pvarbel = starts_with(nodevarbel->str, var);
		if (pvarbel && *pvarbel == '=')
		{
			free(nodevarbel->str);
			nodevarbel->str = bufvarbel;
			info->env_changed = 1;
			return (0);
		}
		nodevarbel = nodevarbel->next;
	}
	add_node_end(&(info->env), bufvarbel, 0);
	free(bufvarbel);
	info->env_changed = 1;
	return (0);
}
