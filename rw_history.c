#include "headers.h"
/**
 * write_history - creates a file, or appends to an existing file
 * @info: the parameter struct
 *
 * Return: 1 on success, else -1
 */
int enf_history(inf *info)
{
	ssize_t fd;
	char *filename = get_h_f(info);
	list *node = NULL;

	if (!filename)
		return (-1);

	fd = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(filename);
	if (fd == -1)
		return (-1);
	for (node = info->history; node; node = node->next)
	{
		_puts_as_fd(node->str, fd);
		_put_as_fd('\n', fd);
	}
	_put_as_fd(BUF_FLUSH, fd);
	close(fd);
	return (1);
}

/**
 * read_history - reads history from file
 * @info: the parameter struct
 *
 * Return: histcount on success, 0 otherwise
 */
int _r_history(inf *info)
{
	int i, last = 0, linecount = 0;
	ssize_t fd, rdlen, fsize = 0;
	struct stat st;
	char *buf = NULL, *filename = get_h_f(info);

	if (!filename)
		return (0);

	fd = open(filename, O_RDONLY);
	free(filename);
	if (fd == -1)
		return (0);
	if (!fstat(fd, &st))
		fsize = st.st_size;
	if (fsize < 2)
		return (0);
	buf = malloc(sizeof(char) * (fsize + 1));
	if (!buf)
		return (0);
	rdlen = read(fd, buf, fsize);
	buf[fsize] = 0;
	if (rdlen <= 0)
		return (free(buf), 0);
	close(fd);
	for (i = 0; i < fsize; i++)
		if (buf[i] == '\n')
		{
			buf[i] = 0;
			Creat_his_l(info, buf + last, linecount++);
			last = i + 1;
		}
	if (last != i)
		Creat_his_l(info, buf + last, linecount++);
	free(buf);
	info->hist_c = linecount;
	while (info->hist_c-- >= HIST_MAX)
		delete_node_at_index(&(info->history), 0);
	resum(info);
	return (info->hist_c);
}
