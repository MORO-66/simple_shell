#include "headers.h"
/**
 * write_history - creates a file, or appends to an existing file
 * @info: the parameter struct
 *
 * Return: 1 on success, else -1
 */
int enf_history(inf *f)
{
	ssize_t filedd;
	char *f_name = get_h_f(f);
	list *node = NULL;

	if (!f_name)
		return (-1);

	filedd = open(f_name, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(f_name);
	if (filedd == -1)
		return (-1);
	for (node = f->history; node; node = node->next)
	{
		_puts_as_fd(node->str, filedd);
		_put_as_fd('\n', filedd);
	}
	_put_as_fd(BUF_FLUSH, filedd);
	close(filedd);
	return (1);
}

/**
 * read_history - reads history from file
 * @info: the parameter struct
 *
 * Return: histcount on success, 0 otherwise
 */
/*
int _r_history(inf *f)
{
	int y, ls = 0, linecount = 0;
	ssize_t filed, read_len, filesize = 0;
	struct stat st;
	char *bufff = NULL, *f_name = get_h_f(f);

	if (!f_name)
		return (0);

	filed = open(f_name, O_RDONLY);
	free(f_name);
	if (filed == -1)
		return (0);
	if (!fstat(filed, &st))
		filesize = st.st_size;
	if (filesize < 2)
		return (0);
	bufff = malloc(sizeof(char) * (filesize + 1));
	if (!bufff)
		return (0);
	read_len = read(filed, bufff, filesize);
	bufff[filesize] = 0;
	if (read_len <= 0)
		return (free(bufff), 0);
	close(filed);
	for (y = 0; y < filesize; y++)
		if (bufff[y] == '\n')
		{
			bufff[y] = 0;
			Creat_his_l(f, bufff + ls, linecount++);
			ls = y + 1;
		}
	if (ls != y)
		Creat_his_l(f, bufff + ls, linecount++);
	free(bufff);
	f->hist_c = linecount;
	while (f->hist_c-- >= HIST_MAX)
		delete_node_at_index(&(f->history), 0);
	resum(f);
	return (f->hist_c);
}
*/