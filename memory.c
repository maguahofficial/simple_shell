#include "shell.h"

/**
 * bfree - function frees a pointer and NULLs the address
 * @ptr: (double pointer)address of the pointer to free
 * memory.c file in simple_shell
 * Return: return 1 if freed, otherwise 0.
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
