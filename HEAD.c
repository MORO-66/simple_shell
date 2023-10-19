#include "headers.h"

/**
 * head_shell - main shell loop
 * @f: the parameter & return info struct
 * @argv: the argument vector from main()
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
		if (isatty(STDIN_FILENO) && f->r_fd <= 2)
			_puts("$ ");
		_eputchar(BUF_FLUSH);
		r = get_line(f);
		if (r != -1)
		{
			reset_info(f, argv);
			find_cmd(f);
		}
		else if (isatty(STDIN_FILENO) && f->r_fd <= 2)
			_putchar('\n');
		f_inf(f, 0);
	}
	enf_history(f);
	f_inf(f, 1);
	if (!(isatty(STDIN_FILENO) && f->r_fd <= 2) && f->status)
		exit(f->status);
	if (builtin_ret == -2)
	{
		if (f->error_num == -1)
			exit(f->status);
		exit(f->error_num);
	}
	return (builtin_ret);
}

