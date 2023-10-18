#include "headers.h"
/**
 * _getline - gets line of input from STDIN
 * @info: paramete
 * @ptr: address o to buffer, preallocated or NULL
 * @length: size ocated ptr buffer if not NULL
 *
 * Return: s
 */
int _getline(inf *f, char **ptr_s, size_t *len)
{
	static char buf[READ_BUF_SIZE];
	static size_t i, len;
	size_t n;
	ssize_t q = 0, m = 0;
	char *p = NULL, *new_p = NULL, *c;

	p = *ptr_s;
	if (p && len)
		m = *len;
	if (i == len)
		i = len = 0;

	q = _rd_buf(f, buf, &len);
	if (q == -1 || (q == 0 && len == 0))
		return (-1);

	c = _chr_search(buf + i, '\n');
	n = c ? 1 + (unsigned int)(c - buf) : len;
	new_p = _realloc(p, m, m ? m + n : n + 1);
	if (!new_p) /* MALLOC FAILURE! */
		return (p ? free(p), -1 : -1);

	if (m)
		_strncat(new_p, buf + i, n - i);
	else
		_strncpy(new_p, buf + i, n - i + 1);

	m += n - i;
	i = n;
	p = new_p;

	if (len)
		*len = m;
	*ptr_s = p;
	return (m);
}

