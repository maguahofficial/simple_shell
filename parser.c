#include "shell.h"

/**
 * is_cmd - function determines if a file is an executable command
 * @info: (pointer)the info struct
 * @path: (pointer) path to the file
 * parser.c file in simple_shell
 * Return: retun 1 if true, 0 otherwise
 */
int is_cmd(info_t *info, char *path)
{
	struct stat stvariable;

	(void)info;
	if (!path || stat(path, &stvariable))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}
/**
 * dup_chars - function duplicates characters
 * @pathstr: (pointer)the PATH string
 * @start: (int variable)starting index
 * @stop: (int variable)stopping index
 * parser.c file in simple_shell
 * Return: retuns pointer to new buffer
 */
char *dup_chars(char *pathstr, int start, int stop)
{
	static char bufvariable[1024];
	int iintvariable = 0, kintvariable = 0;

	for (kintvariable = 0, iintvariable = start;
			iintvariable < stop; iintvariable++)
		if (pathstr[iintvariable] != ':')
			bufvariable[kintvariable++] = pathstr[iintvariable];
	bufvariable[kintvariable] = 0;
	return (bufvariable);
}
/**
 * find_path - finds this cmd in the PATH string
 * @info: (pointer)the info struct
 * @pathstr: (pointer)the PATH string
 * @cmd: (pointer)the cmd to find
 * parser.c file in simple_shell
 * Return: retun full path of cmd if found or NULL
 */
char *find_path(info_t *info, char *pathstr, char *cmd)
{
	int iintvariable = 0, curr_posintvariable = 0;
	char *pathcharvarble;

	if (!pathstr)
		return (NULL);
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (is_cmd(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pathstr[iintvariable] || pathstr[iintvariable] == ':')
		{
			pathcharvarble = dup_chars(pathstr, curr_posintvariable, iintvariable);
			if (!*pathcharvarble)
				_strcat(pathcharvarble, cmd);
			else
			{
				_strcat(pathcharvarble, "/");
				_strcat(pathcharvarble, cmd);
			}
			if (is_cmd(info, pathcharvarble))
				return (pathcharvarble);
			if (!pathstr[iintvariable])
				break;
			curr_posintvariable = iintvariable;
		}
		iintvariable++;
	}
	return (NULL);
}
