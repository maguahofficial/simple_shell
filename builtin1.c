#include "shell.h"
/**
 * _myhistory - function displays history list, one command by line, preceded
 * with line numbers, starting at 0.
 * @info: the structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: this returns always 0
 */
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}
/**
 * unset_alias - function sets alias to string
 * @info: there parameter struct
 * @str: String alias
 *
 * Return: this Always returns  0 on success, 1 on error
 */
int unset_alias(info_t *info, char *str)
{
	char *pcharvariable, ccharvariable;
	int retintvarble;

	pcharvariable = _strchr(str, '=');

	if (!pcharvariable)
		return (1);

	ccharvariable = *pcharvariable;
	*pcharvariable = 0;
	retintvarble = delete_node_at_index(&(info->alias),
			get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*pcharvariable = ccharvariable;

	return (retintvarble);
}
/**
 * set_alias - function sets alias to string
 * @info: parameter struct
 * @str: String alias
 *
 * Return: This Always returns 0 on success, 1 on error
 */
int set_alias(info_t *info, char *str)
{
	char *pcharvarble;

	pcharvarble = _strchr(str, '=');

	if (!pcharvarble)
		return (1);

	if (!*++pcharvarble)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}
/**
 * print_alias - function prints an alias string
 * @node: Alias node
 *
 * Return: this Always retuns 0 on success, 1 on error
 */
int print_alias(list_t *node)
{
	char *pvarble = NULL, *a = NULL;

	if (node)
	{
		pvarble = _strchr(node->str, '=');

		for (a = node->str; a <= pvarble; a++)
			_putchar(*a);

		_putchar('\'');
		_puts(pvarble + 1);
		_puts("'\n");

		return (0);
	}
	return (1);
}
/**
 * _myalias - function mimics the alias builtin (man alias)
 * @info: the Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: this Always retuns 0
 */
int _myalias(info_t *info)
{
	int iintvarble = 0;
	char *pchvarble = NULL;
	list_t *nodelstvarble = NULL;

	if (info->argc == 1)
	{
		nodelstvarble = info->alias;
		while (nodelstvarble)
		{
			print_alias(nodelstvarble);
			nodelstvarble = nodelstvarble->next;
		}
		return (0);
	}
	for (iintvarble = 1; info->argv[iintvarble]; iintvarble++)
	{
		pchvarble = _strchr(info->argv[iintvarble], '=');

		if (pchvarble)
			set_alias(info, info->argv[iintvarble]);

		else
			print_alias(node_starts_with(info->alias, info->argv[iintvarble], '='));
	}
	return (0);
}
