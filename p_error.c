#include "headers.h"
/**
 * print_error - prints an error message
 * @info: the parameter & return info struct
 * @estr: string containing specified error type
 * Return: 0 if no numbers in string, converted number otherwise
 *        -1 on error
 */
void print_error(inf *info, char *estr)
{
	_errorputs(info->filename);
	_errorputs(": ");
	print_d(info->line_c, STDERR_FILENO);
	_errorputs(": ");
	_errorputs(info->argv[0]);
	_errorputs(": ");
	_errorputs(estr);
}