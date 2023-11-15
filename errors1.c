#include "shell.h"

/**
 * _erratoi - function converts a string to an integer
 * @s: (pointer) the string to be converted
 * Return: This Returns 0 if no numbers in string, converted number otherwise
 * -1 on error
 * errors1.c file in the simple_shell task
 */
int _erratoi(char *s)
{
	int ivarble = 0;
	unsigned long int resultvarble = 0;

	if (*s == '+')
		s++;
	for (ivarble = 0;  s[ivarble] != '\0'; ivarble++)
	{
		if (s[ivarble] >= '0' && s[ivarble] <= '9')
		{
			resultvarble *= 10;
			resultvarble += (s[ivarble] - '0');
			if (resultvarble > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (resultvarble);
}

/**
 * print_error - function prints an error message
 * @info: (pointer) the parameter & return info struct
 * @estr: (pointer) string containing specified error type
 * Return: This Returns 0 if no numbers in string, converted number otherwise
 * -1 on error
 *errors1.c file in the simple_shell task
 */
void print_error(info_t *info, char *estr)
{
	_eputs(info->fname);
	_eputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(estr);
}

/**
 * print_d - This (function) prints a decimal (integer) number (base 10)
 * @input: (int variable) the input
 * @fd: (int variable) the filedescriptor to write to
 * errors1.c file in the simple_shell task
 * Return: This Returns number of characters printed
 */
int print_d(int input, int fd)
{
	int (*__putchar)(char) = _putchar;
	int ivarble, countvarble = 0;
	unsigned int _abs_varble, currentvarble;

	if (fd == STDERR_FILENO)
		__putchar = _eputchar;
	if (input < 0)
	{
		_abs_varble = -input;
		__putchar('-');
		countvarble++;
	}
	else
		_abs_varble = input;
	currentvarble = _abs_varble;
	for (ivarble = 1000000000; ivarble > 1; ivarble /= 10)
	{
		if (_abs_varble / ivarble)
		{
			__putchar('0' + currentvarble / ivarble);
			countvarble++;
		}
		currentvarble %= ivarble;
	}
	__putchar('0' + currentvarble);
	countvarble++;

	return (countvarble);
}

/**
 * convert_number - function converter function, a clone of itoa
 * @num: (long int variable) number
 * @base: (int variable) base
 * @flags: (int variable) argument flags
 * errors1.c file in the simple_shell task
 * Return: This Returns a string
 */
char *convert_number(long int num, int base, int flags)
{
	static char *arrayvarble;
	static char buffervarble[50];
	char signvarble = 0;
	char *ptrvarble;
	unsigned long nvarble = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		nvarble = -num;
		signvarble = '-';

	}
	arrayvarble =
		flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptrvarble = &buffervarble[49];
	*ptrvarble = '\0';

	do	{
		*--ptrvarble = arrayvarble[nvarble % base];
		nvarble /= base;
	} while (nvarble != 0);

	if (signvarble)
		*--ptrvarble = signvarble;
	return (ptrvarble);
}

/**
 * remove_comments - This (function) replaces first instance of '#' with '\0'
 * @buf: (pointer) address of the string to modify
 * errors1.c file in the simple_shell task
 * Return: This Always Returns 0;
 */
void remove_comments(char *buf)
{
	int ivarble;

	for (ivarble = 0; buf[ivarble] != '\0'; ivarble++)
		if (buf[ivarble] == '#' && (!ivarble || buf[ivarble - 1] == ' '))
		{
			buf[ivarble] = '\0';
			break;
		}
}
