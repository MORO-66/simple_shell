#include "headers.h"
/**
 *_atoi - conveing to an integer
 *@s: the strinonverted
 *Return: 0 if s in string, converted number otherwise
 */

int _atoint(char *str)
{
	int it, si = 1, f = 0, out;
	unsigned int res = 0;

	for (it = 0;  str[it] != '\0' && f != 2; it++)
	{
		if (str[it] == '-')
			si *= -1;

		if (str[it] >= '0' && str[it] <= '9')
		{
			f = 1;
			res *= 10;
			res += (str[it] - '0');
		}
		else if (f == 1)
			f = 2;
	}

	if (si == -1)
		out = -res;
	else
		out = res;

	return (out);
}

