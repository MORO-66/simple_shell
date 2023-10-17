#include "headers.h"
/**
 * print_error - prints an error message
 * @info: the parameter & return info struct
 * @estr: string containing specified error type
 * Return: 0 if no numbers in string, converted number otherwise
 *        -1 on error
 */
void print_error(info_t *info, char *estr)
{
	_errorputs(info->fname);
	_errorputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	_errorputs(": ");
	_errorputs(info->argv[0]);
	_errorputs(": ");
	_errorputs(estr);
}
