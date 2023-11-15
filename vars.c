#include "shell.h"

/**
 * is_chain - function test if current char in buffer is a chain delimeter
 * @info: (pointer) the parameter struct
 * @buf: (pointer) the char buffer
 * @p: (pointer) address of current position in buf
 * vars.c file in simple_shell
 * Return: returns 1 if chain delimeter, 0 otherwise
 */
int is_chain(info_t *info, char *buf, size_t *p)
{
	size_t jvariable = *p;

	if (buf[jvariable] == '|' && buf[jvariable + 1] == '|')
	{
		buf[jvariable] = 0;
		jvariable++;
		info->cmd_buf_type = CMD_OR;
	}
	else if (buf[jvariable] == '&' && buf[jvariable + 1] == '&')
	{
		buf[jvariable] = 0;
		jvariable++;
		info->cmd_buf_type = CMD_AND;
	}
	else if (buf[jvariable] == ';')
	{
		buf[jvariable] = 0;
		info->cmd_buf_type = CMD_CHAIN;
	}
	else
		return (0);
	*p = jvariable;
	return (1);
}

/**
 * check_chain - function checks we should
 * continue chaining based on last status
 * @info: (pointer) the parameter struct
 * @buf: (pointer) the char buffer
 * @p: (pointer) address of current position in buf
 * @i: (size_t variable) starting position in buf
 * @len: (variable) length of buf
 * vars.c file in simple_shell
 * Return: return Void
 */
void check_chain(info_t *info, char *buf, size_t *p, size_t i, size_t len)
{
	size_t jvariable = *p;

	if (info->cmd_buf_type == CMD_AND)
	{
		if (info->status)
		{
			buf[i] = 0;
			jvariable = len;
		}
	}
	if (info->cmd_buf_type == CMD_OR)
	{
		if (!info->status)
		{
			buf[i] = 0;
			jvariable = len;
		}
	}
	*p = jvariable;
}

/**
 * replace_alias - function replaces an aliases in the tokenized string
 * @info: (pointer) the parameter struct
 * vars.c file in simple_shell
 * Return: returns 1 if replaced, 0 otherwise
 */
int replace_alias(info_t *info)
{
	int ivariable;
	list_t *nodevariable;
	char *pvariable;

	for (ivariable = 0; ivariable < 10; ivariable++)
	{
		nodevariable = node_starts_with(info->alias, info->argv[0], '=');
		if (!nodevariable)
			return (0);
		free(info->argv[0]);
		pvariable = _strchr(nodevariable->str, '=');
		if (!pvariable)
			return (0);
		pvariable = _strdup(pvariable + 1);
		if (!pvariable)
			return (0);
		info->argv[0] = pvariable;
	}
	return (1);
}

/**
 * replace_vars - function replaces vars in the tokenized string
 * @info: (pointer) the parameter struct
 * vars.c file in simple_shell
 * Return: returns 1 if replaced, 0 otherwise
 */
int replace_vars(info_t *info)
{
	int ivariable = 0;
	list_t *nodevariable;

	for (ivariable = 0; info->argv[ivariable]; ivariable++)
	{
		if (info->argv[ivariable][0] != '$' || !info->argv[ivariable][1])
			continue;
		if (!_strcmp(info->argv[ivariable], "$?"))
		{
			replace_string(&(info->argv[ivariable]),
					_strdup(convert_number(info->status, 10, 0)));
			continue;
		}
		if (!_strcmp(info->argv[ivariable], "$$"))
		{
			replace_string(&(info->argv[ivariable]),
					_strdup(convert_number(getpid(), 10, 0)));
			continue;
		}
		nodevariable = node_starts_with(info->env, &info->argv[ivariable][1], '=');
		if (nodevariable)
		{
			replace_string(&(info->argv[ivariable]),
					_strdup(_strchr(nodevariable->str, '=') + 1));
			continue;
		}
		replace_string(&info->argv[ivariable], _strdup(""));
	}
	return (0);
}

/**
 * replace_string - function replaces string
 * @old: (double pointer) address of old string
 * @new: (pointer) new string
 * vars.c file in simple_shell
 * Return: returns 1 if replaced, 0 otherwise
 */
int replace_string(char **old, char *new)
{
	free(*old);
	*old = new;
	return (1);
}
