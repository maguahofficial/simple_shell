#include "shell.h"

/**
 * _myhistory - function displays the history list, one command by line,
 * preceded with line numbers, starting at 0.
 * @info: (pointer) Structure that contains
 * potential arguments. Used to maintain
 * constant function prototype.
 * builtin1.c file in the simple_shell task
 *  Return: function Always returns 0
 */
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias - function sets alias to string
 * @info: (pointer) parameter struct
 * @str: (pointer) the string alias
 * builtin1.c file in the simple_shell task
 * Return: Always returns 0 on success, 1 on error
 */
int unset_alias(info_t *info, char *str)
{
	char *pvarble, cvarble;
	int retvarble;

	pvarble = _strchr(str, '=');
	if (!pvarble)
		return (1);
	cvarble = *pvarble;
	*pvarble = 0;
	retvarble = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*pvarble = cvarble;
	return (retvarble);
}

/**
 * set_alias - function sets alias to string
 * @info: (pointer) parameter struct
 * @str: (pointer) the string alias
 * builtin1.c file in the simple_shell task
 * Return: Always returns 0 on success, 1 on error
 */
int set_alias(info_t *info, char *str)
{
	char *pvarble;

	pvarble = _strchr(str, '=');
	if (!pvarble)
		return (1);
	if (!*++pvarble)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - function prints an alias string
 * @node: (pointer) the alias node
 *
 * Return: Always Returns 0 on success, 1 on error
 */
int print_alias(list_t *node)
{
	char *pvarble = NULL, *avarble = NULL;

	if (node)
	{
		pvarble = _strchr(node->str, '=');
		for (avarble = node->str; avarble <= pvarble; avarble++)
			_putchar(*avarble);
		_putchar('\'');
		_puts(pvarble + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - function mimics the alias builtin (man alias)
 * @info: (pointer) Structure that contains
 * potential arguments. Used to maintain
 * constant function prototype.
 *  Return: This function Always Returns 0
 */
int _myalias(info_t *info)
{
	int ivarble = 0;
	char *pvarble = NULL;
	list_t *nodevarble = NULL;

	if (info->argc == 1)
	{
		nodevarble = info->alias;
		while (nodevarble)
		{
			print_alias(nodevarble);
			nodevarble = nodevarble->next;
		}
		return (0);
	}
	for (ivarble = 1; info->argv[ivarble]; ivarble++)
	{
		pvarble = _strchr(info->argv[ivarble], '=');
		if (pvarble)
			set_alias(info, info->argv[ivarble]);
		else
			print_alias(node_starts_with(info->alias, info->argv[ivarble], '='));
	}

	return (0);
}
