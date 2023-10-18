#include "headers.h"

/**
 * main - entry point
 * @argc: arg count
 * @argv: arg vector
 *
 * Return: 0 on success, 1 on error
 */
int main(int argc, char **argv)
{
	inf info[] = { INFO };
	int fd = 2;
	list* node = NULL;
	size_t iter;

	asm ("mov %1, %0\n\t"
		"add $3, %0"
		: "=r" (fd)
		: "r" (fd));

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_errorputs(argv[0]);
				_errorputs(": 0: Can't open ");
				_errorputs(argv[1]);
				_eputchar('\n');
				_eputchar(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		info->r_fd = fd;
	}

	for (iter = 0; environ[iter]; iter++)
		add_node_end(&node, environ[iter], 0);
	info->enviro = node;

	_r_history(info);
	head_shell(info, argv);
	return (EXIT_SUCCESS);
}
