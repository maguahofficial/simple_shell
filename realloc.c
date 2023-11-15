#include "shell.h"
/**
 * _memset - function fills memory with a constant byte
 * @s: (pointer)the pointer to the memory area
 * @b: (char variable)the byte to fill *s with
 * @n: (intr variable)the amount of bytes to be filled
 * realloc.c file in simple_shell
 * Return: return (s) a pointer to the memory area s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int ivariable;

	for (ivariable = 0; ivariable < n; ivariable++)
		s[ivariable] = b;
	return (s);
}
/**
 * ffree - function frees a string of strings
 * @pp: (double pointer)string of strings
 * realloc.c file in simple_shell
 */
void ffree(char **pp)
{
	char **acharvariable = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(acharvariable);
}
/**
 * _realloc - function reallocates a block of memory
 * @ptr: (pointer) to previous malloc'ated block
 * @old_size: (unsigned int variable)byte size of previous block
 * @new_size: (unsigned int variable)byte size of new block
 * realloc.c file in simple_shell
 * Return: return pointer to da ol'block nameen.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *pcharvariable;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);
	pcharvariable = malloc(new_size);
	if (!pcharvariable)
		return (NULL);
	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		pcharvariable[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (pcharvariable);
}
