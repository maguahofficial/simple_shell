#include "shell.h"

/**
 * interactive - function returns true if shell is interactive mode
 * @info: (pointer) struct address
 * _atoi.c file in simple shell
 * Return: 1 if interactive mode, 0 otherwise
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - function checks if character is a delimeter
 * @c: (char variable) the char to check
 * @delim: (pointer) the delimeter string
 * Return: returnns 1 if true, 0 if false
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 *_isalpha - function checks for alphabetic character
 *@c: (int variable) The character to input
 *Return: returns 1 if c is alphabetic, 0 otherwise
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 *_atoi - function converts a string to an integer
 *@s: (pointer) the string to be converted
 *Return:returns  0 if no numbers in string, converted number otherwise
 */

int _atoi(char *s)
{
	int ivariable, signvariable = 1, flagvariable = 0, outputvariable;
	unsigned int resultvariable = 0;

	for (ivariable = 0;  s[ivariable] != '\0' && flagvariable != 2; ivariable++)
	{
		if (s[ivariable] == '-')
			signvariable *= -1;

		if (s[ivariable] >= '0' && s[ivariable] <= '9')
		{
			flagvariable = 1;
			resultvariable *= 10;
			resultvariable += (s[ivariable] - '0');
		}
		else if (flagvariable == 1)
			flagvariable = 2;
	}

	if (signvariable == -1)
		outputvariable = -resultvariable;
	else
		outputvariable = resultvariable;

	return (outputvariable);
}
