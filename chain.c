#include "headers.h"
/**
 * is_chain - teent chin buffer is a chain delimeter
 * @info: the paruct
 * @buf: the cha
 * @p: address opositiin buf
 *
 * Return: 1 if meter,otherwise
 */
int chain_sure(inf *info, char *buf, size_t *p)
{
	size_t j = *p;

	if (buf[j] == '|' && buf[j + 1] == '|')
	{
		buf[j] = 0;
		j++;
		info->cmd_buf = CMD_OR;
	}
	else if (buf[j] == '&' && buf[j + 1] == '&')
	{
		buf[j] = 0;
		j++;
		info->cmd_buf = CMD_AND;
	}
	else if (buf[j] == ';') /* found end of this command */
	{
		buf[j] = 0; /* replace semicolon with null */
		info->cmd_buf = CMD_CHAIN;
	}
	else
		return (0);
	*p = j;
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
void which_if_chain(inf *info, char *buf, size_t *p, size_t i, size_t len)
{
	size_t j = *p;

	if (info->cmd_buf == CMD_AND)
	{
		if (info->status)
		{
			buf[i] = 0;
			j = len;
		}
	}
	if (info->cmd_buf == CMD_OR)
	{
		if (!info->status)
		{
			buf[i] = 0;
			j = len;
		}
	}

	*p = j;
}
