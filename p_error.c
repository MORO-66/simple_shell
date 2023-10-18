#include "headers.h"
/**
 * print_error - prints an error message
 * @f: the parameter & return info struct
 * @e_string: string containing specified error type
 * Return: 0 if no numbers in string, converted number otherwise
 *        -1 on error
 */
void print_error(inf *f, char *e_string)
{
	_errorputs(f->filename);
	_errorputs(": ");
	print_d(f->line_c, STDERR_FILENO);
	_errorputs(": ");
	_errorputs(f->argv[0]);
	_errorputs(": ");
	_errorputs(e_string);
}
