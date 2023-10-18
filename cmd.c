#include "headers.h"
/**
 * cmd_sure - determile is an executable command
 * @f: the info
 * @path_s: path to t
 *
 * Return: 1 if truise
 */
int cmd_sure(inf *f, char *path_s)
{
	struct stat st;

	(void)f;
	if (!path_s || stat(path_s, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}


/**
 * find_cmd - finand in PATH
 * @f: the parreturn info struct
 *
 * Return: void
 */
void find_cmd(inf *f)
{
	char *path_s = NULL;
	int y, s;

	f->path_ = f->argv[0];
	if (f->linecount_f == 1)
	{
		f->line_c++;
		f->linecount_f = 0;
	}
	for (y = 0, s = 0; f->arg[y]; y++)
		if (!is_delim(f->arg[y], " \t\n"))
			s++;
	if (!s)
		return;

	path_s = where_path(f, _getenv(f, "PATH="), f->argv[0]);
	if (path_s)
	{
		f->path_ = path_s;
		cmd_fork(f);
	}
	else
	{
		if (((isatty(STDIN_FILENO) && f->r_fd <= 2)
			|| _getenv(f, "PATH=")
			|| f->argv[0][0] == '/') && cmd_sure(f, f->argv[0]))
			cmd_fork(f);
		else if (*(f->arg) != '\n')
		{
			f->status = 127;
			print_error(f, "not found\n");
		}
	}
}

/**
 * cmd_fork - forn exec thread to run cmd
 * @info: the par & return info struct
 *
 * Return: void
 */
void cmd_fork(inf *f)
{
	pid_t pid_ch;

	pid_ch = fork();
	if (pid_ch == -1)
	{
		perror("Error:");
		return;
	}
	if (pid_ch == 0)
	{
		if (execve(f->path_, f->argv, take_environ(f)) == -1)
		{
			free_info(f, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
	}
	else
	{
		wait(&(f->status));
		if (WIFEXITED(f->status))
		{
			f->status = WEXITSTATUS(f->status);
			if (f->status == 126)
				print_error(f, "Permission denied\n");
		}
	}
}
