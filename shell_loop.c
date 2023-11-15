#include "shell.h"

/**
 * hsh - function main shell loop
 * @info: (pointer) the parameter & return info struct
 * @av: (double pointer) the argument vector from main()
 * shell_loop.c file in the simple_shel task
 * Return: This Returns 0 on success, 1 on error, or error code
 */
int hsh(info_t *info, char **av)
{
	ssize_t rvarble = 0;
	int builtin_retvarble = 0;

	while (rvarble != -1 && builtin_retvarble != -2)
	{
		clear_info(info);
		if (interactive(info))
			_puts("$ ");
		_eputchar(BUF_FLUSH);
		rvarble = get_input(info);
		if (rvarble != -1)
		{
			set_info(info, av);
			builtin_retvarble = find_builtin(info);
			if (builtin_retvarble == -1)
				find_cmd(info);
		}
		else if (interactive(info))
			_putchar('\n');
		free_info(info, 0);
	}
	write_history(info);
	free_info(info, 1);
	if (!interactive(info) && info->status)
		exit(info->status);
	if (builtin_retvarble == -2)
	{
		if (info->err_num == -1)
			exit(info->status);
		exit(info->err_num);
	}
	return (builtin_retvarble);
}

/**
 * find_builtin - function finds a builtin command
 * @info: (pointer) the parameter & return info struct
 * shell_loop.c file in the simple_shel task
 * Return: This Returns -1 if builtin not found,
 * 0 if builtin executed successfully,
 * 1 if builtin found but not successful,
 * -2 if builtin signals exit()
 */
int find_builtin(info_t *info)
{
	int ivarble, built_in_retvarble = -1;
	builtin_table builtintblvarble[] = {
		{"exit", _myexit},
		{"env", _myenv},
		{"help", _myhelp},
		{"history", _myhistory},
		{"setenv", _mysetenv},
		{"unsetenv", _myunsetenv},
		{"cd", _mycd},
		{"alias", _myalias},
		{NULL, NULL}
	};

	for (ivarble = 0; builtintblvarble[ivarble].type; ivarble++)
		if (_strcmp(info->argv[0], builtintblvarble[ivarble].type) == 0)
		{
			info->line_count++;
			built_in_retvarble = builtintblvarble[ivarble].func(info);
			break;
		}
	return (built_in_retvarble);
}

/**
 * find_cmd - function finds a command in PATH
 * @info: (pointer) the parameter & return info struct
 * shell_loop.c file in the simple_shel task
 * Return: This Return void
 */
void find_cmd(info_t *info)
{
	char *path = NULL;
	int ivarble, kvarble;

	info->path = info->argv[0];
	if (info->linecount_flag == 1)
	{
		info->line_count++;
		info->linecount_flag = 0;
	}
	for (ivarble = 0, kvarble = 0; info->arg[ivarble]; ivarble++)
		if (!is_delim(info->arg[ivarble], " \t\n"))
			kvarble++;
	if (!kvarble)
		return;

	path = find_path(info, _getenv(info, "PATH="), info->argv[0]);
	if (path)
	{
		info->path = path;
		fork_cmd(info);
	}
	else
	{
		if ((interactive(info) || _getenv(info, "PATH=")
			|| info->argv[0][0] == '/') && is_cmd(info, info->argv[0]))
			fork_cmd(info);
		else if (*(info->arg) != '\n')
		{
			info->status = 127;
			print_error(info, "not found\n");
		}
	}
}

/**
 * fork_cmd - function forks a an exec thread to run cmd
 * @info: (pointer) the parameter & return info struct
 * shell_loop.c file in the simple_shel task
 * Return: This Returns void
 */
void fork_cmd(info_t *info)
{
	pid_t child_pidvarble;

	child_pidvarble = fork();
	if (child_pidvarble == -1)
	{
		perror("Error:");
		return;
	}
	if (child_pidvarble == 0)
	{
		if (execve(info->path, info->argv, get_environ(info)) == -1)
		{
			free_info(info, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
	}
	else
	{
		wait(&(info->status));
		if (WIFEXITED(info->status))
		{
			info->status = WEXITSTATUS(info->status);
			if (info->status == 126)
				print_error(info, "Permission denied\n");
		}
	}
}
