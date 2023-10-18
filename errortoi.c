#include "headers.h"

/**
 * _erratoi - con a string to an integer
 * @s: the stringe converted
 * Return: 0 if nbers in string, converted number otherwise
 *       -1 on er
 */
int _error_atoi(char *str)
{
	int y = 0;
	unsigned long int sult = 0;

	if (*str == '+')
		str++;  /* TODO: why does this make main return 255? */
	for (y = 0;  str[y] != '\0'; y++)
	{
		if (str[y] >= '0' && str[y] <= '9')
		{
			sult *= 10;
			sult += (str[y] - '0');
			if (sult > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (sult);
}
