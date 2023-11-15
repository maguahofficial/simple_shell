#include "shell.h"
/**
 * main - function entry point
 * @ac: (int variable)arg count
 * @av: (double pointer)arg vector
 * main.c file in simple_shell
 * Return: 0 on success, 1 on error
 */
int main(int ac, char **av)
{
	info_t infovarble[] = { INFO_INIT };
	int fdintvarble = 2;

	asm ("mov %1, %0\n\t"
			"add $3, %0"
			: "=r" (fdintvarble)
			: "r" (fdintvarble));

	if (ac == 2)
	{
		fdintvarble = open(av[1], O_RDONLY);
		if (fdintvarble == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_eputs(av[0]);
				_eputs(": 0: Can't open ");
				_eputs(av[1]);
				_eputchar('\n');
				_eputchar(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		info->readfd = fdintvarble;
	}
	populate_env_list(infovarble);
	read_history(infovarble);
	hsh(infovarble, av);
	return (EXIT_SUCCESS);
}
