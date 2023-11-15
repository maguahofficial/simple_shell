#include "shell.h"

/**
 *_eputs - fucntion prints an input string
 * @str: (pointer) the string to be printed
 * errors.c file in the simple_shell task
 * Return: This returns Nothing
 */
void _eputs(char *str)
{
	int ivarble = 0;

	if (!str)
		return;
	while (str[ivarble] != '\0')
	{
		_eputchar(str[ivarble]);
		ivarble++;
	}
}

/**
 * _eputchar - function writes the character c to stderr
 * @c: (pointer) The character to print
 * errors.c file in the simple_shell task
 * Return: This returns On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _eputchar(char c)
{
	static int ivarble;
	static char bufvarble[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || ivarble >= WRITE_BUF_SIZE)
	{
		write(2, bufvarble, ivarble);
		ivarble = 0;
	}
	if (c != BUF_FLUSH)
		bufvarble[ivarble++] = c;
	return (1);
}

/**
 * _putfd - function writes the character c to given fd
 * @c: (char variable) The character to print
 * @fd: (int variable)The filedescriptor to write to
 * errors.c file in the simple_shell task
 * Return: This Returns On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putfd(char c, int fd)
{
	static int ivarble;
	static char bufvarble[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || ivarble >= WRITE_BUF_SIZE)
	{
		write(fd, bufvarble, ivarble);
		ivarble = 0;
	}
	if (c != BUF_FLUSH)
		bufvarble[ivarble++] = c;
	return (1);
}

/**
 *_putsfd - function prints an input string
 * @str: (pointer) the string to be printed
 * @fd: (int variable) the filedescriptor to write to
 * errors.c file in the simple_shell task
 * Return: This Returns the number of chars put
 */
int _putsfd(char *str, int fd)
{
	int ivarble = 0;

	if (!str)
		return (0);
	while (*str)
	{
		ivarble += _putfd(*str++, fd);
	}
	return (ivarble);
}
