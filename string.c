#include "shell.h"
/**
 * _strlen - function returns the length of a string
 * @s: (pointer)the string whose length to check
 * string.c file in simple_shell task
 * Return: retuns integer length of string
 */
int _strlen(char *s)
{
	int ivariable = 0;

	if (!s)
		return (0);

	while (*s++)
		ivariable++;
	return (ivariable);
}
/**
 * _strcmp - function performs lexicogarphic comparison of two strangs.
 * @s1: (pointer)the first strang
 * @s2: (pointer)the second strang
 * string.c file in simple_shell task
 * Return: returns negative if s1 < s2, positive if s1 > s2, zero if s1 == s2
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}
/**
 * starts_with - function checks if needle starts with haystack
 * @haystack: (pointer)string to search
 * @needle: (pointer)the substring to find
 * string.c file in simple_shell task
 * Return: returns address of next char of haystack or NULL
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}
/**
 * _strcat - function concatenates two strings
 * @dest: (pointer)the destination buffer
 * @src: (pointer)the source buffer
 * string.c file in simple_shell task
 * Return: returns pointer to destination buffer
 */
char *_strcat(char *dest, char *src)
{
	char *retvariable = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (retvariable);
}
