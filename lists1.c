#include "shell.h"
/**
 * list_len - function determines length of linked list
 * @h: (pointer)pointer to first node
 * lists1.c file in simple_shell
 * Return: returns size of list
 */
size_t list_len(const list_t *h)
{
	size_t isze_tvarble = 0;

	while (h)
	{
		h = h->next;
		isze_tvarble++;
	}
	return (isze_tvarble);
}
/**
 * list_to_strings - function returns an array of strings of the list->str
 * @head: (pointer) to first node
 * lists1.c file in simple shell
 * Return: return array of strings
 */
char **list_to_strings(list_t *head)
{
	list_t *nodelstvarble = head;
	size_t isze_tvarble = list_len(head), jsze_tvarble;
	char **strscharvarble;
	char *strcharvarble;

	if (!head || !isze_tvarble)
		return (NULL);
	strscharvarble = malloc(sizeof(char *) * (isze_tvarble + 1));
	if (!strscharvarble)
		return (NULL);
	for (isze_tvarble = 0; nodelstvarble;
			nodelstvarble = nodelstvarble->next, isze_tvarble++)
	{
		strcharvarble = malloc(_strlen(nodelstvarble->str) + 1);
		if (!strcharvarble)
		{
			for (jsze_tvarble = 0; jsze_tvarble < isze_tvarble; jsze_tvarble++)
				free(strscharvarble[jsze_tvarble]);
			free(strscharvarble);
			return (NULL);
		}

		strcharvarble = _strcpy(strcharvarble, nodelstvarble->str);
		strscharvarble[isze_tvarble] = strcharvarble;
	}
	strscharvarble[isze_tvarble] = NULL;
	return (strscharvarble);
}
/**
 * print_list - function prints all elements of a list_t linked list
 * @h: (pointer) to first node
 * lists1.c file in simple shell
 * Return: return size of list
 */
size_t print_list(const list_t *h)
{
	size_t iszevarble = 0;

	while (h)
	{
		_puts(convert_number(h->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		iszevarble++;
	}
	return (iszevarble);
}
/**
 * node_starts_with - function returns node whose string starts with prefix
 * @node: (pointer) to list head
 * @prefix: (char pointer)string to match
 * @c: (char variable)the next character after prefix to match
 * lists1.c file in simple shell
 * Return: retun match node or null
 */
list_t *node_starts_with(list_t *node, char *prefix, char c)
{
	char *pcharvarble = NULL;

	while (node)
	{
		pcharvarble = starts_with(node->str, prefix);
		if (pcharvarble && ((c == -1) || (*pcharvarble == c)))
			return (node);
		node = node->next;
	}
	return (NULL);
}
/**
 * get_node_index -  function gets the index of a node
 * @head: (pointer) to list head
 * @node: (pointer) to the node
 * lists1.c file in simple shell
 * Return: retuns index of node or -1
 */
ssize_t get_node_index(list_t *head, list_t *node)
{
	size_t issze_tvarble = 0;

	while (head)
	{
		if (head == node)
			return (issze_tvarble);
		head = head->next;
		issze_tvarble++;
	}
	return (-1);
}
