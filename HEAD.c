#include "headers.h"

/**
 * hsh - main shell loop
 * @info: the parameter & return info struct
 * @av: the argument vector from main()
 *
 * Return: 0 on success, 1 on error, or error code
 */
int head_shell(inf *f, char **argv)
{
	ssize_t r = 0;
	int builtin_ret = 0;

	while (r != -1 && builtin_ret != -2)
	{
		null_info(f);
		if (interactive(f))
			_puts("$ ");
		_eputchar(BUF_FLUSH);
		r = get_line(f);
		if (r != -1)
		{
			reset_info(f, argv);
			builtin_ret = which_cmd(f);
			if (builtin_ret == -1)
				find_cmd(f);
		}
		else if (interactive(f))
			_putchar('\n');
		free_info(f, 0);
	}
	enf_history(f);
	free_info(f, 1);
	if (!interactive(f) && f->status)
		exit(f->status);
	if (builtin_ret == -2)
	{
		if (f->error_num == -1)
			exit(f->status);
		exit(f->error_num);
	}
	return (builtin_ret);
}

/**
 * interactive - returns true if shell is interactive mode
 * @info: struct address
 *
 * Return: 1 if interactive mode, 0 otherwise
 */
int interactive(inf *f)
{
	return (isatty(STDIN_FILENO) && f->r_fd <= 2);
}
