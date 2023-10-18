#include "headers.h"
/**
 * input_buf - bufchained commands
 * @info: parameteuct
 * @buf: address ofer
 * @len: address o var
 *
 * Return: bytes r
 */
ssize_t buf_in(inf *f, char **buff, size_t *lennn)
{
	ssize_t r = 0;
	size_t len_p = 0;

	if (!*lennn)
	{
		free(*buff);
		*buff = NULL;
		signal(2, Handler);
#if USE_GETLINE
		r = getline(buf, &len_p, stdin);
#else
		r = _getline(f, buff, &len_p);
#endif
		if (r > 0)
		{
			if ((*buff)[r - 1] == '\n')
			{
				(*buff)[r - 1] = '\0';
				r--;
			}
			f->linecount_f = 1;
			Creat_his_l(f, *buff, f->hist_c++);
			{
				*lennn = r;
			}
		}
	}
	return (r);
}

/**
 * get_input - gets  minus the newline
 * @info: parameter 
 *
 * Return: bytes rea
 */
ssize_t get_line(inf *f)
{
	static char *buf;
	static size_t i, j, len;
	ssize_t r = 0;
	char **buf_p = &(f->arg), *p;

	_putchar(BUF_FLUSH);
	r = buf_in(f, &buf, &len);
	if (r == -1)
		return (-1);
	if (len)
	{
		j = i;
		p = buf + i;

		j = len;
		i = j + 1;
		if (i >= len)
		{
			i = len = 0;
			f->cmd_buf = CMD_NORM;
		}

		*buf_p = p;
		return (_strlen(p));
	}

	*buf_p = buf;
	return (r);
}

/**
 * read_buf - reads a buffer
 * @info: parameter struct
 * @buf: buffer
 * @i: size
 *
 * Return: r
 */
ssize_t _rd_buf(inf *f, char *buff, size_t *it)
{
	ssize_t gang = 0;

	if (*it)
		return (0);
	gang = read(f->r_fd, buff, 1024);
	if (gang >= 0)
		*it = gang;
	return (gang);
}
