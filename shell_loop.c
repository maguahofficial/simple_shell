#include "shell.h"

/**
 * hsh - function main shell loop
 * @info: (pointer)the parameter & return info struct
 * @av: (double pointer)the argument vector from main()
 * shell_loop.c file in simple_shell
 * Return: return 0 on success, 1 on error, or error code
 */
int hsh(info_t *info, char **av)
{
	ssize_t rsizevarble = 0;
	int builtin_retvariable = 0;

	while (rsizevarble != -1 && builtin_retvariable != -2)
	{
		clear_info(info);
		if (interactive(info))
			_puts("$ ");
		_eputchar(BUF_FLUSH);
		rsizevarble = get_input(info);
		if (rsizevarble != -1)
		{
			set_info(info, av);
			builtin_retvariable = find_builtin(info);
			if (builtin_retvariable == -1)
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
	if (builtin_retvariable == -2)
	{
		if (info->err_num == -1)
			exit(info->status);
		exit(info->err_num);
	}
	return (builtin_retvariable);
}
/**
 * find_builtin - function finds a builtin command
 * @info: (pointer) the parameter & return info struct
 * shell_loop.c file in simple_shell
 * Return: retuns -1 if builtin not found,
 * 0 if builtin executed successfully,
 * 1 if builtin found but not successful,
 * 2 if builtin signals exit()
 */
int find_builtin(info_t *info)
{
	int ivariable, built_in_retvariable = -1;
	builtin_table builtintblvariable[] = {
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
	for (ivariable = 0; builtintblvariable[ivariable].type; ivariable++)
		if (_strcmp(info->argv[0], builtintblvariable[i].type) == 0)
		{
			info->line_count++;
			built_in_retvariable = builtintblvariable[ivariable].func(info);
			break;
		}
	return (built_in_retvariable);
}
/**
 * find_cmd - function finds a command in PATH
 * @info: (pointer)the parameter & return info struct
 * shell_loop.c file in simple_shell
 * Return: retuns void
 */
void find_cmd(info_t *info)
{
	char *pathcharvarble = NULL;
	int ivariable, kvariable;

	info->pathcharvarble = info->argv[0];
	if (info->linecount_flag == 1)
	{
		info->line_count++;
		info->linecount_flag = 0;
	}
	for (ivariable = 0, kvariable = 0; info->arg[ivariable]; ivariable++)
		if (!is_delim(info->arg[ivariable], " \t\n"))
			kvariable++;
	if (!kvariable)
		return;
	pathcharvarble = find_path(info, _getenv(info, "PATH="), info->argv[0]);
	if (pathcharvarble)
	{
		info->pathcharvarble = pathcharvarble;
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
 * @info: (pointer)the parameter & return info struct
 * shell_loop.c file in simple_shell
 * Return: retuns void
 */
void fork_cmd(info_t *info)
{
	pid_t child_pidvariable;

	child_pidvariable = fork();

	if (child_pidvariable == -1)
	{
		perror("Error:");
		return;
	}
	if (child_pidvariable == 0)
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
