#include "shell.h"

/**
 * _strcpy - function copies a string
 * @dest: (pointer) the destination
 * @src: (pointer) the source
 * string1.c file in the simple_shell task
 * Return: retuns pointer to destination
 */
char *_strcpy(char *dest, char *src)
{
	int ivariable = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[ivariable])
	{
		dest[ivariable] = src[ivariable];
		ivariable++;
	}
	dest[ivariable] = 0;
	return (dest);
}
/**
 * _strdup - function duplicates a string
 * @str: (pointer)the string to duplicate
 * string1.c file in the simple_shell task
 * Return: retuns pointer to the duplicated string
 */
char *_strdup(const char *str)
{
	int lengthvariable = 0;
	char *retvariable;

	if (str == NULL)
		return (NULL);
	while (*str++)
		lengthvariable++;
	retvariable = malloc(sizeof(char) * (lengthvariable + 1));
	if (!retvariable)
		return (NULL);
	for (lengthvariable++; lengthvariable--;)
		retvariable[lengthvariable] = *--str;
	return (retvariable);
}
/**
 * _puts - function prints an input string
 * @str: (pointer) the string to be printed
 * string1.c file in the simple_shell task
 * Return: returns Nothing
 */
void _puts(char *str)
{
	int ivariable = 0;

	if (!str)
		return;
	while (str[ivariable] != '\0')
	{
		_putchar(str[ivariable]);
		ivariable++;
	}
}
/**
 * _putchar - function writes the character c to stdout
 * @c: (pointer) The character to print
 * string1.c file in the simple_shell task
 * Return: returns On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	static int ivariable;
	static char bufvariable[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || ivariable >= WRITE_BUF_SIZE)
	{
		write(1, bufvariable, ivariable);
		ivariable = 0;
	}
	if (c != BUF_FLUSH)
		bufvariable[ivariable++] = c;
	return (1);
}
