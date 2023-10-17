#include "headers.h"
/**
 * sigintHandler - bloctrl-C
 * @sig_num: the signalber
 *
 * Return: void
 */
void Handler(__attribute__((unused))int sig_num)
{
	_puts("\n");
	_puts("$ ");
	_putchar(BUF_FLUSH);
}
