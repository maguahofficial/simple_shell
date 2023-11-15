#include "shell.h"

/**
 * _myexit - function exits the shell
 * @info: (pointer) Structure containing potential arguments.Used to maintain
 * constant function prototype.
 * builtin.c file in simpleshell
 * Return: returns exits with a given exit status
 * (0) if info.argv[0] != "exit"
 */
int _myexit(info_t *info)
{
	int exitcheckvarble;

	if (info->argv[1])
	{
		exitcheckvarble = _erratoi(info->argv[1]);
		if (exitcheckvarble == -1)
		{
			info->status = 2;
			print_error(info, "Illegal number: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		info->err_num = _erratoi(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}

/**
 * _mycd - function changes the current directory of the process
 * @info: (pointer) Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * builtin.c file in the simple_shell task
 *  Return: returns Always 0
 */
int _mycd(info_t *info)
{
	char *svarble, *dirvarble, buffervarble[1024];
	int chdir_retvarble;

	svarble = getcwd(buffervarble, 1024);
	if (!svarble)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		dirvarble = _getenv(info, "HOME=");
		if (!dirvarble)
			chdir_retvarble =
				chdir((dirvarble = _getenv(info, "PWD=")) ? dirvarble : "/");
		else
			chdir_retvarble = chdir(dirvarble);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!_getenv(info, "OLDPWD="))
		{
			_puts(svarble);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
		chdir_retvarble =
			chdir((dirvarble = _getenv(info, "OLDPWD=")) ? dirvarble : "/");
	}
	else
		chdir_retvarble = chdir(info->argv[1]);
	if (chdir_retvarble == -1)
	{
		print_error(info, "can't cd to ");
		_eputs(info->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffervarble, 1024));
	}
	return (0);
}

/**
 * _myhelp - function changes the current directory of the process
 * @info: (pointer) Structure containing potential arguments. Used to maintain
 * constant function prototype.
 *  Return: this returns Always 0
 *  builtin.c file in the simple_shell task
 */
int _myhelp(info_t *info)
{
	char **arg_arrayvarble;

	arg_arrayvarble = info->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*arg_arrayvarble);
	return (0);
}
