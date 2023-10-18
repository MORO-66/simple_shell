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

	if (!*lennn) /* if nothing left in the buffer, fill it */
	{
		/*bfree((void **)info->cmd_buf);*/
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
				(*buff)[r - 1] = '\0'; /* remove trailing newline */
				r--;
			}
			f->linecount_f = 1;
			Creat_his_l(f, *buff, f->hist_c++);
			/* if (_strchr(*buf, ';')) is this a command chain? */
			{
				*lennn = r;
				/*info->cmd_buf = (int)buf;*/
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
	static char *buf; /* the ';' command chain buffer */
	static size_t i, j, len;
	ssize_t r = 0;
	char **buf_p = &(f->arg), *p;

	_putchar(BUF_FLUSH);
	r = buf_in(f, &buf, &len);
	if (r == -1) /* EOF */
		return (-1);
	if (len)	/* we have commands left in the chain buffer */
	{
		j = i; /* init new iterator to current buf position */
		p = buf + i; /* get pointer for return */

		which_if_chain(f, buf, &j, i, len);
		while (j < len) /* iterate to semicolon or end */
		{
			if (chain_sure(f, buf, &j))
				break;
			j++;
		}

		i = j + 1; /* increment past nulled ';'' */
		if (i >= len) /* reached end of buffer? */
		{
			i = len = 0; /* reset position and length */
			f->cmd_buf = CMD_NORM;
		}

		*buf_p = p; /* pass back pointer to current command position */
		return (_strlen(p)); /* return length of current command */
	}

	*buf_p = buf; /* else not a chain, pass back buffer from _getline() */
	return (r); /* return length of buffer from _getline() */
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
	gang = read(f->r_fd, buff, READ_BUF_SIZE);
	if (gang >= 0)
		*it = gang;
	return (gang);
}
