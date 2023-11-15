#include "shell.h"

/**
 * **strtow - function splits a string into words.
 * Repeat delimiters are ignored
 * @str: (pointer) the input string
 * @d: (pointer) the delimeter string
 * tokenizer.c file in the simple_shell task
 * Return: returns a pointer to an array of strings, or NULL on failure
 */

char **strtow(char *str, char *d)
{
	int ivariable, jvariable, kvariable, mvariable, numwordsvariable = 0;
	char **svariable;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (ivariable = 0; str[ivariable] != '\0'; ivariable++)
		if (!is_delim(str[ivariable], d)
				&& (is_delim(str[ivariable + 1], d) || !str[ivariable + 1]))
			numwordsvariable++;
	if (numwordsvariable == 0)
		return (NULL);
	svariable = malloc((1 + numwordsvariable) * sizeof(char *));
	if (!svariable)
		return (NULL);
	for (ivariable = 0, jvariable = 0; jvariable < numwordsvariable; jvariable++)
	{
		while (is_delim(str[ivariable], d))
			ivariable++;
		kvariable = 0;
		while (!is_delim(str[ivariable + kvariable], d) &&
				str[ivariable + kvariable])
			kvariable++;
		svariable[jvariable] = malloc((kvariable + 1) * sizeof(char));
		if (!svariable[jvariable])
		{
			for (kvariable = 0; kvariable < jvariable; kvariable++)
				free(svariable[kvariable]);
			free(svariable);
			return (NULL);
		}
		for (mvariable = 0; mvariable < kvariable; mvariable++)
			svariable[jvariable][mvariable] = str[ivariable++];
		svariable[jvariable][mvariable] = 0;
	}
	svariable[jvariable] = NULL;
	return (svariable);
}
/**
 * **strtow2 - function splits a string into words
 * @str: (pointer) the input string
 * @d: (char variable) the delimeter
 * tokenizer.c file in the simple_shell task
 * Return: returns a pointer to an array of strings, or NULL on failure
 */
char **strtow2(char *str, char d)
{
	int ivarble, jvarble, kvarble, mvarble, numwordsvarble = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (ivarble = 0; str[ivarble] != '\0'; ivarble++)
		if ((str[ivarble] != d && str[ivarble + 1] == d) ||
				(str[ivarble] != d && !str[ivarble + 1]) || str[ivarble + 1] == d)
			numwordsvarble++;
	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwordsvarble) * sizeof(char *));
	if (!s)
		return (NULL);
	for (ivarble = 0, jvarble = 0; jvarble < numwordsvarble; jvarble++)
	{
		while (str[ivarble] == d && str[ivarble] != d)
			ivarble++;
		kvarble = 0;
		while (str[ivarble + kvarble] != d && str[ivarble + kvarble] &&
				str[ivarble + kvarble] != d)
			kvarble++;
		s[jvarble] = malloc((kvarble + 1) * sizeof(char));
		if (!s[jvarble])
		{
			for (kvarble = 0; kvarble < jvarble; kvarble++)
				free(s[kvarble]);
			free(s);
			return (NULL);
		}
		for (mvarble = 0; mvarble < kvarble; mvarble++)
			s[jvarble][mvarble] = str[ivarble++];
		s[jvarble][mvarble] = 0;
	}
	s[jvarble] = NULL;
	return (s);
}
