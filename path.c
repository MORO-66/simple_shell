#include "headers.h"
/**
 * where_path - finds the PATH string
 * @f: the info s
 * @string_path: the PAT
 * @command: the cmd to
 *
 * Return: full pathound or NULL
 */
char *where_path(inf *f, char *string_path, char *command)
{
	int y = 0, now_pos = 0;
	char *strpath;

	if (!string_path)
		return (NULL);
	if ((_strlen(command) > 2) && start(command, "./"))
	{
		if (cmd_sure(f, command))
			return (command);
	}
	while (1)
	{
		if (!string_path[y] || string_path[y] == ':')
		{
			strpath = dup_chars(string_path, now_pos, y);
			if (!*strpath)
				_strcat(strpath, command);
			else
			{
				_strcat(strpath, "/");
				_strcat(strpath, command);
			}
			if (cmd_sure(f, strpath))
				return (strpath);
			if (!string_path[y])
				break;
			now_pos = y;
		}
		y++;
	}
	return (NULL);
}
