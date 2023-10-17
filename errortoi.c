#include "headers.h"

/**
 * _erratoi - con a string to an integer
 * @s: the stringe converted
 * Return: 0 if nbers in string, converted number otherwise
 *       -1 on er
 */
int _error_atoi(char *s)
{
	int i = 0;
	unsigned long int result = 0;

	if (*s == '+')
		s++;  /* TODO: why does this make main return 255? */
	for (i = 0;  s[i] != '\0'; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			result *= 10;
			result += (s[i] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (result);
}
