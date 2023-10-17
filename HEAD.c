#include "headers.h"

/**
 * hsh - main shell loop
 * @info: the parameter & return info struct
 * @av: the argument vector from main()
 *
 * Return: 0 on success, 1 on error, or error code
 */
int head_shell(inf *info, char **av)
{
	ssize_t r = 0;
	int builtin_ret = 0;

	while (r != -1 && builtin_ret != -2)
	{
		null_info(info);
		if (interactive(info))
			_puts("$ ");
		_eputchar(BUF_FLUSH);
		r = get_line(info);
		if (r != -1)
		{
			reset_info(info, av);
			builtin_ret = which_cmd(info);
			if (builtin_ret == -1)
				find_cmd(info);
		}
		else if (interactive(info))
			_putchar('\n');
		free_info(info, 0);
	}
	enf_history(info);
	free_info(info, 1);
	if (!interactive(info) && info->status)
		exit(info->status);
	if (builtin_ret == -2)
	{
		if (info->error_num == -1)
			exit(info->status);
		exit(info->error_num);
	}
	return (builtin_ret);
}

/**
 * interactive - returns true if shell is interactive mode
 * @info: struct address
 *
 * Return: 1 if interactive mode, 0 otherwise
 */
int interactive(inf *info)
{
	return (isatty(STDIN_FILENO) && info->r_fd <= 2);
}
