#include "shell.h"

/**
 * input_buf - function buffers chained commands
 * @info: (info_t pointer)parameter struct
 * @buf: (char double pointer)address of buffer
 * @len: (size_t pointer)address of len var
 * getLine.c file in the simple_shell task
 * Return: bytes read
 */
ssize_t input_buf(info_t *info, char **buf, size_t *len)
{
	ssize_t rssize_tvarble = 0;

	size_t len_psize_tvarble = 0;

	if (!*len)
	{
		free(*buf);
		*buf = NULL;
		signal(SIGINT, sigintHandler);
#if USE_GETLINE
		rssize_tvarble = getline(buf, &len_psize_tvarble, stdin);
#else
		rssize_tvarble = _getline(info, buf, &len_psize_tvarble);
#endif
		if (rssize_tvarble > 0)
		{
			if ((*buf)[rssize_tvarble - 1] == '\n')
			{
				(*buf)[rssize_tvarble - 1] = '\0';
				rssize_tvarble--;
			}
			info->linecount_flag = 1;
			remove_comments(*buf);
			build_history_list(info, *buf, info->histcount++);
			{
				*len = rssize_tvarble;
				info->cmd_buf = buf;
			}
		}
	}
	return (rssize_tvarble);
}
/**
 * get_input - function gets a line minus the newline
 * @info: (pointer)parameter struct
 * getLine.c file in the simple_shell task
 * Return: returns bytes read
 */
ssize_t get_input(info_t *info)
{
	static char *bufcharvariable;
	static size_t isze_tvariable, jsze_tvariable, lensze_tvariable;
	ssize_t rssze_tvariable = 0;
	char **buf_pcharvarble = &(info->arg), *pcharvarble;

	_putchar(BUF_FLUSH);
	rssze_tvariable = input_buf(info, &bufcharvariable, &lensze_tvariable);
	if (rssze_tvariable == -1)
		return (-1);
	if (lensze_tvariable)
	{
		jsze_tvariable = isze_tvariable;
		pcharvarble = bufcharvariable + isze_tvariable;

		check_chain(info, bufcharvariable,
				&jsze_tvariable, isze_tvariable, lensze_tvariable);
		while (jsze_tvariable < lensze_tvariable)
		{
			if (is_chain(info, bufcharvariable, &jsze_tvariable))
				break;
			jsze_tvariable++;
		}

		isze_tvariable = jsze_tvariable + 1;
		if (isze_tvariable >= lensze_tvariable)
		{
			isze_tvariable = lensze_tvariable = 0;
			info->cmd_buf_type = CMD_NORM;
		}

		*buf_pcharvarble = pcharvarble;
		return (_strlen(pcharvarble));
	}

	*buf_pcharvarble = bufcharvariable;
	return (rssze_tvariable);
}
/**
 * read_buf - function reads a buffer
 * @info: parameter struct
 * @buf: (char pointer)buffer
 * @i: (pointer)size
 * getLine.c file in the simple_shell task
 * Return: r
 */
ssize_t read_buf(info_t *info, char *buf, size_t *i)
{
	ssize_t rsszevarble = 0;

	if (*i)
		return (0);

	rsszevarble = read(info->readfd, buf, READ_BUF_SIZE);

	if (rsszevarble >= 0)
		*i = rsszevarble;

	return (rsszevarble);
}
/**
 * _getline - function gets the next line of input from STDIN
 * @info: parameter struct
 * @ptr: (double pointer)address of pointer to buffer, preallocated or NULL
 * @length: The size of preallocated ptr buffer if its not NULL
 * getLine.c file in the simple_shell task
 * Return: s
 */
int _getline(info_t *info, char **ptr, size_t *length)
{
	static char bufcharvarble[READ_BUF_SIZE];
	static size_t isze_tvarble, lensze_tvarble;
	size_t ksze_tvarble;
	ssize_t rssze_tvarble = 0, sssze_tvarble = 0;
	char *pcharvarble = NULL, *new_pcharvarble = NULL, *ccharvarble;

	pcharvarble = *ptr;

	if (pcharvarble && length)
		sssze_tvarble = *length;
	if (isze_tvarble == lensze_tvarble)
		isze_tvarble = lensze_tvarble = 0;
	rssze_tvarble = read_buf(info, bufcharvarble, &lensze_tvarble);
	if (rssze_tvarble == -1 || (rssze_tvarble == 0 && lensze_tvarble == 0))
		return (-1);
	ccharvarble = _strchr(bufcharvarble + isze_tvarble, '\n');
	ksze_tvarble = ccharvarble ? 1 +
		(unsigned int)(ccharvarble - bufcharvarble) : lensze_tvarble;
	new_pcharvarble =
		_realloc(pcharvarble, sssze_tvarble,
				sssze_tvarble ? sssze_tvarble + ksze_tvarble : ksze_tvarble + 1);
	if (!new_pcharvarble)
		return (pcharvarble ? free(pcharvarble), -1 : -1);

	if (sssze_tvarble)
		_strncat(new_pcharvarble, bufcharvarble +
				isze_tvarble, ksze_tvarble - isze_tvarble);
	else
		_strncpy(new_pcharvarble, bufcharvarble +
				isze_tvarble, ksze_tvarble - isze_tvarble + 1);
	sssze_tvarble += ksze_tvarble - isze_tvarble;
	isze_tvarble = ksze_tvarble;
	pcharvarble = new_pcharvarble;
	if (length)
		*length = sssze_tvarble;
	*ptr = pcharvarble;
	return (sssze_tvarble);
}
/**
 * sigintHandler - function blocks ctrl-C
 * @sig_num: (int variable)the signal number
 * getLine.c file in simple_shell task
 * Return: returns void
 */
void sigintHandler(__attribute__((unused))int sig_num)
{
	_puts("\n");
	_puts("$ ");
	_putchar(BUF_FLUSH);
}
