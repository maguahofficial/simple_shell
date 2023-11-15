#include "shell.h"

/**
 * add_node - function adds a node to the start of the list
 * @head: (list_t double pointer)address of pointer to head node
 * @str: (const char pointer)str field of node
 * @num: (int variable)node index used by history
 * lists.c file in the simple_shell task
 * Return: returns the size of list
 */
list_t *add_node(list_t **head, const char *str, int num)
{
	list_t *new_headlist_tvarble;

	if (!head)
		return (NULL);
	new_headlist_tvarble = malloc(sizeof(list_t));
	if (!new_headlist_tvarble)
		return (NULL);
	_memset((void *)new_headlist_tvarble, 0, sizeof(list_t));
	new_headlist_tvarble->num = num;
	if (str)
	{
		new_headlist_tvarble->str = _strdup(str);
		if (!new_headlist_tvarble->str)
		{
			free(new_headlist_tvarble);
			return (NULL);
		}
	}
	new_headlist_tvarble->next = *head;
	*head = new_headlist_tvarble;
	return (new_headlist_tvarble);
}
/**
 * add_node_end - function adds a node to the end of the list
 * @head: (list_t double pointer)address of pointer to head node
 * @str: str (const char pointer)field of node
 * @num: (int variable)node index used by history
 * lists.c file in the simple_shell task
 * Return: returns the size of list
 */
list_t *add_node_end(list_t **head, const char *str, int num)
{
	list_t *new_nodelist_tvarble, *nodelist_tvarble;

	if (!head)
		return (NULL);

	nodelist_tvarble = *head;
	new_nodelist_tvarble = malloc(sizeof(list_t));
	if (!new_nodelist_tvarble)
		return (NULL);
	_memset((void *)new_nodelist_tvarble, 0, sizeof(list_t));
	new_nodelist_tvarble->num = num;
	if (str)
	{
		new_nodelist_tvarble->str = _strdup(str);
		if (!new_nodelist_tvarble->str)
		{
			free(new_nodelist_tvarble);
			return (NULL);
		}
	}
	if (nodelist_tvarble)
	{
		while (nodelist_tvarble->next)
			nodelist_tvarble = nodelist_tvarble->next;
		nodelist_tvarble->next = new_nodelist_tvarble;
	}
	else
		*head = new_nodelist_tvarble;
	return (new_nodelist_tvarble);
}
/**
 * print_list_str - function prints only the str element
 * of a list_t linked list
 * @h: (list_t pointer) pointer to first node
 * lists.c file in the simple_shell task
 * Return: returns the size of list
 */
size_t print_list_str(const list_t *h)
{
	size_t isze_tvarble = 0;

	while (h)
	{
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		isze_tvarble++;
	}
	return (isze_tvarble);
}
/**
 * delete_node_at_index - function deletes node at given index
 * @head: (double pointer)address of pointer to first node
 * @index: (unsigned int variable)index of node to delete
 * lists.c file in the simple_shell task
 * Return: 1 on success, 0 on failure
 */
int delete_node_at_index(list_t **head, unsigned int index)
{
	list_t *nodelst_tvarble, *prev_nodelst_tvarble;
	unsigned int iunintvarble = 0;

	if (!head || !*head)
		return (0);
	if (!index)
	{
		nodelst_tvarble = *head;
		*head = (*head)->next;
		free(nodelst_tvarble->str);
		free(nodelst_tvarble);
		return (1);
	}
	nodelst_tvarble = *head;
	while (nodelst_tvarble)
	{
		if (iunintvarble == index)
		{
			prev_nodelst_tvarble->next = nodelst_tvarble->next;
			free(nodelst_tvarble->str);
			free(nodelst_tvarble);
			return (1);
		}
		iunintvarble++;
		prev_nodelst_tvarble = nodelst_tvarble;
		nodelst_tvarble = nodelst_tvarble->next;
	}
	return (0);
}
/**
 * free_list - function frees all nodes of a list
 * @head_ptr: (double pointer)address of pointer to head node
 * lists.c file in simple_shell task
 * Return: this returns void
 */
void free_list(list_t **head_ptr)
{
	list_t *nodelst_tvarble, *next_nodelst_tvarble, *headlst_tvarble;

	if (!head_ptr || !*head_ptr)
		return;
	headlst_tvarble = *head_ptr;
	nodelst_tvarble = headlst_tvarble;
	while (nodelst_tvarble)
	{
		next_nodelst_tvarble = nodelst_tvarble->next;
		free(nodelst_tvarble->str);
		free(nodelst_tvarble);
		nodelst_tvarble = next_nodelst_tvarble;
	}
	*head_ptr = NULL;
}
