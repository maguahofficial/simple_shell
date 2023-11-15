#include "shell.h"

/**
 **_strncpy - this function copies a string
 *@dest: (char variable)the destination string to be copied to
 *@src: (char variable)source string
 *@n: (int variable)amount of characters to be copied
 *Return: this returns the concatenated string
 */
char *_strncpy(char *dest, char *src, int n)
{
	int ivarble, jintvarble;
	char *s = dest;

	ivarble = 0;
	while (src[ivarble] != '\0' && ivarble < n - 1)
	{
		dest[ivarble] = src[ivarble];
		ivarble++;
	}
	if (ivarble < n)
	{
		jintvarble = ivarble;
		while (jintvarble < n)
		{
			dest[jintvarble] = '\0';
			jintvarble++;
		}
	}
	return (s);
}

/**
 **_strncat - function concatenates two strings
 *@dest: (char variable)the first string
 *@src: (char variable)the second string
 *@n: (int variable)amount of bytes to be maximally used
 *Return: this returns the concatenated string
 */
char *_strncat(char *dest, char *src, int n)
{
	int iintvariable, jintvariable;
	char *scharvariable = dest;

	iintvariable = 0;
	jintvariable = 0;
	while (dest[iintvariable] != '\0')
		iintvariable++;

	while (src[jintvariable] != '\0' && jintvariable < n)
	{
		dest[iintvariable] = src[jintvariable];
		iintvariable++;
		jintvariable++;
	}
	if (jintvariable < n)
		dest[iintvariable] = '\0';
	return (scharvariable);
}
/**
 **_strchr - function locates a character in a string
 *@s: (char array variable)the string to be parsed
 *@c: (char variable)the character to look for
 *Return: (s) pointer to the memory area s
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
