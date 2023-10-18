#include "headers.h"
/**
 * is_chain - teent chin buffer is a chain delimeter
 * @info: the paruct
 * @buf: the cha
 * @p: address opositiin buf
 *
 * Return: 1 if meter,otherwise
 */
int chain_sure(inf *f, char *buff, size_t *ptr_si)
{
	size_t jaafer = *ptr_si;

	if (buff[jaafer] == '|' && buff[jaafer + 1] == '|')
	{
		buff[jaafer] = 0;
		jaafer++;
		f->cmd_buf = CMD_OR;
	}
	else if (buff[jaafer] == '&' && buff[jaafer + 1] == '&')
	{
		buff[jaafer] = 0;
		jaafer++;
		f->cmd_buf = CMD_AND;
	}
	else if (buff[jaafer] == ';') /* found end of this command */
	{
		buff[jaafer] = 0; /* replace semicolon with null */
		f->cmd_buf = CMD_CHAIN;
	}
	else
		return (0);
	*ptr_si = jaafer;
	return (1);
}

/**
 * check_chain - ches we chaining based on last status
 * @info: the paramer s
 * @buf: the char buer
 * @p: address of cuent
 * @i: starting posion 
 * @len: length of b
 *
 * Return: Void
 */
void which_if_chain(inf *f, char *buff, size_t *ptr_si, size_t it, size_t lenth)
{
	size_t jafer = *ptr_si;

	if (f->cmd_buf == CMD_AND)
	{
		if (f->status)
		{
			buff[it] = 0;
			jafer = lenth;
		}
	}
	if (f->cmd_buf == CMD_OR)
	{
		if (!f->status)
		{
			buff[it] = 0;
			jafer = lenth;
		}
	}

	*ptr_si = jafer;
}
