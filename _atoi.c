#include "shell.h"

/**
 * interactive - function that returns if shell is interactive mode
 * @info: struct address
 *_atoi.c file in 0x16 simple shell
 * Return: 1 if interactive mode, 0 otherwise
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - function checks if character is a delimeter
 * @c: The char to check
 * @delim: variable .the delimeter string
 * Return:  returns 1 if true, 0 if false
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);

	return (0);
}

/**
 * _isalpha - function checks for alphabetic character
 * @c: character to input
 * Return: return 1 if c is alphabetic, 0 otherwise
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - function converts a string to an integer
 * @s: string to be converted
 * Return: return 0 if no numbers in string, converted number otherwise
 */

int _atoi(char *s)
{
	int ivarble, signintvarble = 1, flagintvarble = 0, outputintvarble;
	unsigned int resultunintvarb = 0;

	for (ivarble = 0; s[ivarble] != '\0' && flagintvarble != 2; ivarble++)
	{
		if (s[ivarble] == '-')
			signintvarble *= -1;

		if (s[ivarble] >= '0' && s[ivarble] <= '9')
		{
			flagintvarble = 1;
			resultunintvarb *= 10;
			resultunintvarb += (s[ivarble] - '0');
		}
		else if (flagintvarble == 1)
			flagintvarble = 2;
	}

	if (signintvarble == -1)
		outputintvarble = -resultunintvarb;

	else
		outputintvarble = resultunintvarb;

	return (outputintvarble);
}
