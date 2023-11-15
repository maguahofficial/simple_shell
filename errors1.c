#include "shell.h"

/**
 * _erratoi - function converts string to an integer
 * @s: String to be converted
 * Return: return 0 if theres no numbers in string, converted number otherwise
 *       -1 on error
 * errors1.c file in the simple shell
 */

int _erratoi(char *s)
{
	int ivariable = 0;
	unsigned long int resultlnintvariable = 0;

	if (*s == '+')
		s++;

	for (ivariable = 0;  s[ivariable] != '\0'; ivariable++)
	{
		if (s[ivariable] >= '0' && s[ivariable] <= '9')
		{
			resultlnintvariable *= 10;
			resultlnintvariable += (s[ivariable] - '0');
			if (resultlnintvariable > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (resultlnintvariable);
}

/**
 * print_error - function prints an error message
 * @info: the parameter & return info struct
 * @estr: (char variable)string containing specified error type
 * Return: returns  0 if theres no numbers in string,
 * converted number otherwise
 * -1 on error
 * errors1.c file in the simple shell
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
 * print_d - this function prints a decimal (integer) numb (base 10)
 * @input: (variable )the input
 * @fd: Filedescriptor to write to
 *
 * Return: returns the number of characters printed
 */
int print_d(int input, int fd)
{
	int (*__putchar)(char) = _putchar;
	int iintvariable, countintvariable = 0;
	unsigned int _abs_unsvarble, currentunsvarble;

	if (fd == STDERR_FILENO)
		__putchar = _eputchar;

	if (input < 0)
	{
		_abs_unsvarble = -input;
		__putchar('-');
		countintvariable++;
	}
	else
		_abs_unsvarble = input;
	currentunsvarble = _abs_unsvarble;

	for (iintvariable = 1000000000; iintvariable > 1; iintvariable /= 10)
	{
		if (_abs_unsvarble / iintvariable)
		{
			__putchar('0' + current / iintvariable);
			countintvariable++;
		}
		currentunsvarble %= iintvariable;
	}
	__putchar('0' + currentunsvarble);
	countintvariable++;

	return (countintvariable);
}

/**
 * convert_number - function converter, a clone of itoa
 * @num: (variable) numbers
 * @base: (variable) base
 * @flags: the argument flags
 * errors1.c file in the simple shell
 * Return: this returns string
 */

char *convert_number(long int num, int base, int flags)
{
	static char *arraychvarble;
	static char buffer[50];
	char signcharvariable = 0;
	char *ptrvariable;
	unsigned long nlongvariable = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		nlongvariable = -num;
		signcharvariable = '-';
	}

	arraychvarble =
		flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptrvariable = &buffer[49];
	*ptrvariable = '\0';

	do {
		*--ptrvariable = array[nlongvariable % base];
		nlongvariable /= base;
	} while (nlongvariable != 0);

	if (signcharvariable)
		*--ptrvariable = signcharvariable;

	return (ptrvariable);
}

/**
 * remove_comments - this function replaces first instance of '#' with '\0'
 * @buf: the address of the string to modify
 * errors1.c file in simple shell
 * Return: this Always returns 0;
 */

void remove_comments(char *buf)
{
	int iintvariable;

	for (iintvariable = 0; buf[iintvariable] != '\0'; iintvariable++)
		if (buf[iintvariable] == '#' &&
				(!iintvariable || buf[iintvariable - 1] == ' '))
		{
			buf[iintvariable] = '\0';
			break;
		}
}
