#include "headers.h"
/**
 * _getline - gets line of input from STDIN
 * @f: paramete
 * @ptr_s: address o to buffer, preallocated or NULL
 * @lent: size ocated ptr buffer if not NULL
 *
 * Return: s
 */
int _getline(inf *f, char **ptr_s, size_t *lent)
{
	static char buf[1024];
	static size_t i, len;
	size_t n;
	ssize_t q = 0, m = 0;
	char *p = NULL, *new_p = NULL, *c;

	p = *ptr_s;
	if (p && lent)
		m = *lent;
	if (i == len)
		i = len = 0;

	q = _rd_buf(f, buf, &len);
	if (q == -1 || (q == 0 && len == 0))
		return (-1);

	c = _chr_search(buf + i, '\n');
	n = c ? 1 + (unsigned int)(c - buf) : len;
	new_p = _realloc(p, m, m ? m + n : n + 1);
	if (!new_p)
		return (p ? free(p), -1 : -1);

	if (m)
		_strncat(new_p, buf + i, n - i);
	else
		_strncpy(new_p, buf + i, n - i + 1);

	p = new_p;
	m += n - i;
	i = n;

	if (lent)
		*lent = m;
	*ptr_s = p;
	return (m);
}

