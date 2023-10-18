#include "headers.h"
/**
 * _myhistory - dihistory list, one command by line, preceded
 *              wibers, starting at 0.
 * @info: Structurg potential arguments. Used to maintain
 *        constantrototype.
 *  Return: Always
 */
int _myhistory(inf *f)
{
	print_list(f->history);
	return (0);
}
