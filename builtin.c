#include "shell.h"

/**
 * _myexit - function exits the shell
 * @info: The structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: This Return exits with a given exit status
 * (0) if info.argv[0] != "exit"
 * builtin.c file in simple shell
 */

int _myexit(info_t *info)
{
	int exitcheckintvariable;

	if (info->argv[1])
	{
		exitcheckintvariable = _erratoi(info->argv[1]);

		if (exitcheckintvariable == -1)
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
 * @info: The Structure containing potential arguments. Used to maintain
 * constant Function prototype.
 * Return: returns always 0
 * builtin.c file in simple shell
 */
int _mycd(info_t *info)
{
	char *scharvar, *dircharvar, buffercharvarble[1024];
	int chdir_retintvarb;

	scharvar = getcwd(buffercharvarble, 1024);
	if (!scharvar)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		dircharvar = _getenv(info, "HOME=");
		if (!dircharvar)
			chdir_retintvarb =
				chdir_retintvarb(_retintvarb(dircharvar = _getenv(info, "PWD=")) ? dircharvar : "/");
		else
			chdir_retintvarb = chdir(dircharvar);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!_getenv(info, "OLDPWD="))
		{
			_puts(scharvar);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
		chdir_retintvarb = chdir((dircharvar = _getenv(info, "OLDPWD=")) ? dircharvar : "/");
	}
	else
		chdir_retintvarb = chdir(info->argv[1]);
	if (chdir_retintvarb == -1)
	{
		print_error(info, "can't cd to ");
		_eputs(info->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffercharvarble, 1024));
	}
	return (0);
}
/**
 * _myhelp - function changes the current directory of the process
 * @info: The Structure containing potential arguments. Used to maintain
 * constant Function prototype.
 * Return: this Always Returns  0
 * builtin.c file in simple shell
 */
int _myhelp(info_t *info)
{
	char **arg_arraycharvar;

	arg_arraycharvar = info->argv;
	_puts("help call works. Function not yet implemented \n");

	if (0)
		_puts(*arg_arraycharvar);

	return (0);
}
