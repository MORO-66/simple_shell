#include "headers.h"
/**
 * is_cmd - determile is an executable command
 * @info: the info 
 * @path: path to t
 *
 * Return: 1 if truise
 */
int cmd_sure(inf *info, char *path)
{
	struct stat st;

	(void)info;
	if (!path || stat(path, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}


/**
 * find_cmd - finand in PATH
 * @info: the parreturn info struct
 *
 * Return: void
 */
void find_cmd(inf *info)
{
	char *path = NULL;
	int i, k;

	info->path_ = info->argv[0];
	if (info->linecount_f == 1)
	{
		info->line_c++;
		info->linecount_f = 0;
	}
	for (i = 0, k = 0; info->arg[i]; i++)
		if (!is_delim(info->arg[i], " \t\n"))
			k++;
	if (!k)
		return;

	path = where_path(info, _getenv(info, "PATH="), info->argv[0]);
	if (path)
	{
		info->path_ = path;
		cmd_fork(info);
	}
	else
	{
		if ((interactive(info) || _getenv(info, "PATH=")
			|| info->argv[0][0] == '/') && cmd_sure(info, info->argv[0]))
			cmd_fork(info);
		else if (*(info->arg) != '\n')
		{
			info->status = 127;
			print_error(info, "not found\n");
		}
	}
}

/**
 * fork_cmd - forn exec thread to run cmd
 * @info: the par & return info struct
 *
 * Return: void
 */
void cmd_fork(inf *info)
{
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		/* TODO: PUT ERROR FUNCTION */
		perror("Error:");
		return;
	}
	if (child_pid == 0)
	{
		if (execve(info->path_, info->argv, take_environ(info)) == -1)
		{
			free_info(info, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
		/* TODO: PUT ERROR FUNCTION */
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
