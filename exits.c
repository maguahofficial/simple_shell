#include "shell.h"

/**
 **_strncpy - function copies a string
 *@dest: (pointer) the destination string to be copied to
 *@src: (pointer) the source string
 *@n: (int variable) the amount of characters to be copied
 *Return: This Returns the concatenated string
 *exits.c file in the simple_shell task
 */
char *_strncpy(char *dest, char *src, int n)
{
	int ivarble, jvarble;
	char *svarble = dest;

	ivarble = 0;
	while (src[ivarble] != '\0' && ivarble < n - 1)
	{
		dest[ivarble] = src[ivarble];
		ivarble++;
	}
	if (ivarble < n)
	{
		jvarble = ivarble;
		while (jvarble < n)
		{
			dest[jvarble] = '\0';
			jvarble++;
		}
	}
	return (svarble);
}

/**
 **_strncat - function concatenates two strings
 *@dest: (pointer) the first string
 *@src: (pointer) the second string
 *@n: (int variable) the amount of bytes to be maximally used
 *Return: This returns the concatenated string
 *exits.c file in the simple_shell task
 */
char *_strncat(char *dest, char *src, int n)
{
	int ivarble, jvarble;
	char *svarble = dest;

	ivarble = 0;
	jvarble = 0;
	while (dest[ivarble] != '\0')
		ivarble++;
	while (src[jvarble] != '\0' && jvarble < n)
	{
		dest[ivarble] = src[jvarble];
		ivarble++;
		jvarble++;
	}
	if (jvarble < n)
		dest[ivarble] = '\0';
	return (svarble);
}

/**
 **_strchr - function locates a character in a string
 *@s: (pointer) the string to be parsed
 *@c: (char variable) the character to look for
 *Return: This Returns (s) a pointer to the memory area s
 *exits.c file in the simple_shell task
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
