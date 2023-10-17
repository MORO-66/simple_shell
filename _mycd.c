#include "headers.h"
/**
 * _mycd - chactory of the process
 * @info: Struntial arguments. Used to maintain
 *          cotype.
 *  Return: Al
 */
int _mycd(inf *f)
{
	char *str, *direction, buff[1024];
	int chdir_;

	str = getcwd(buff, 1024);
	if (!str)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!f->argv[1])
	{
		direction = _getenv(f, "HOME=");
		if (!direction)
			chdir_ = /* TODO: what should this be? */
				chdir((direction = _getenv(f, "PWD=")) ? direction : "/");
		else
			chdir_ = chdir(direction);
	}
	else if (_strcmp(f->argv[1], "-") == 0)
	{
		if (!_getenv(f, "OLDPWD="))
		{
			_puts(str);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(f, "OLDPWD=")), _putchar('\n');
		chdir_ = /* TODO: what should this be? */
			chdir((direction = _getenv(f, "OLDPWD=")) ? direction : "/");
	}
	else
		chdir_ = chdir(f->argv[1]);
	if (chdir_ == -1)
	{
		print_error(f, "can't cd to ");
		_errorputs(f->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(f, "OLDPWD", _getenv(f, "PWD="));
		_setenv(f, "PWD", getcwd(buff, 1024));
	}
	return (0);
}
