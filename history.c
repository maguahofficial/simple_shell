#include "shell.h"

/**
 * get_history_file - function gets the history file
 * @info: (pointer)parameter struct
 * history.c file in the simple_shell task
 * Return: returns allocated string containg history file
 */
char *get_history_file(info_t *info)
{
	char *bufcharvarible, *dircharvarible;

	dircharvarible = _getenv(info, "HOME=");

	if (!dircharvarible)
		return (NULL);

	bufcharvarible =
		malloc(sizeof(char) * (_strlen(dircharvarible) + _strlen(HIST_FILE) + 2));

	if (!bufcharvarible)
		return (NULL);

	bufcharvarible[0] = 0;
	_strcpy(bufcharvarible, dircharvarible);
	_strcat(bufcharvarible, "/");
	_strcat(bufcharvarible, HIST_FILE);

	return (bufcharvarible);
}
/**
 * write_history - function creates a file, or appends to an existing file
 * @info: (pointer)the parameter struct
 * history.c file simple_shell task
 * Return: 1 on success, else -1
 */
int write_history(info_t *info)
{
	ssize_t fdssze_tvarble;
	char *filenamecharvarble = get_history_file(info);
	list_t *nodevarble = NULL;

	if (!filenamecharvarble)
		return (-1);

	fdssze_tvarble = open(filenamecharvarble, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(filenamecharvarble);

	if (fdssze_tvarble == -1)
		return (-1);

	for (nodevarble = info->history; nodevarble; nodevarble = nodevarble->next)
	{
		_putsfd(nodevarble->str, fdssze_tvarble);
		_putfd('\n', fdssze_tvarble);
	}
	_putfd(BUF_FLUSH, fdssze_tvarble);
	close(fdssze_tvarble);

	return (1);
}
/**
 * read_history - function reads history from file
 * @info: (pointer)the parameter struct
 * history.c file simple_shell task
 * Return: function returns histcount on success, 0 otherwise
 */
int read_history(info_t *info)
{
	int iintvarble, lastintvarble = 0, linecountintvarble = 0;
	ssize_t fdsszevarble, rdlensszevarble, fsizesszevarble = 0;
	struct stat stvarble;
	char *bufvarble = NULL, *filenamevarble = get_history_file(info);

	if (!filenamevarble)
		return (0);
	fdsszevarble = open(filenamevarble, O_RDONLY);
	free(filenamevarble);
	if (fdsszevarble == -1)
		return (0);
	if (!fstat(fdsszevarble, &stvarble))
		fsizesszevarble = stvarble.st_size;
	if (fsizesszevarble < 2)
		return (0);
	bufvarble = malloc(sizeof(char) * (fsizesszevarble + 1));
	if (!bufvarble)
		return (0);
	rdlensszevarble = read(fdsszevarble, bufvarble, fsizesszevarble);
	bufvarble[fsizesszevarble] = 0;
	if (rdlensszevarble <= 0)
		return (free(bufvarble), 0);
	close(fdsszevarble);
	for (iintvarble = 0; iintvarble < fsizesszevarble; iintvarble++)
		if (bufvarble[iintvarble] == '\n')
		{
			bufvarble[iintvarble] = 0;
			build_history_list(info, bufvarble + lastintvarble, linecountintvarble++);
			lastintvarble = iintvarble + 1;
		}
	if (lastintvarble != iintvarble)
		build_history_list(info, bufvarble + lastintvarble, linecountintvarble++);
	free(bufvarble);
	info->histcount = linecountintvarble;
	while (info->histcount-- >= HIST_MAX)
		delete_node_at_index(&(info->history), 0);
	renumber_history(info);
	return (info->histcount);
}
/**
 * build_history_list - function adds entry to a history linked list
 * @info: (pointer)Structure containing potential arguments. Used to maintain
 * @buf: (char pointer)buffer
 * @linecount: (int variable)the history linecount, histcount
 * history.c file in simple_shell task
 * Return: function Always returns 0
 */
int build_history_list(info_t *info, char *buf, int linecount)
{
	list_t *nodelist_tvariable = NULL;

	if (info->history)
		nodelist_tvariable = info->history;

	add_node_end(&nodelist_tvariable, buf, linecount);

	if (!info->history)
		info->history = nodelist_tvariable;

	return (0);
}
/**
 * renumber_history - function renumbers the history linked list after changes
 * @info: (pointer)Structure containing potential arguments. Used to maintain
 * history.c file in simple_shell task
 * Return: returns the new histcount
 */
int renumber_history(info_t *info)
{
	list_t *nodelist_tvariable = info->history;
	int iintvarble = 0;

	while (nodelist_tvariable)
	{
		nodelist_tvariable->num = iintvarble++;
		nodelist_tvariable = nodelist_tvariable->next;
	}

	return (info->histcount = iintvarble);
}
