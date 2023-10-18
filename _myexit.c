#include "headers.h"
/**
 * _myexit - exits t
 * @info: Structure potential arguments. Used to maintain
 *          constantrototype.
 *  Return: exits wiexit status
 *         (0) if in!= "exit"
 */
int _myexit(inf *f)
{
	/*int check_status;*/

	if (f->argv[1])  /* If there is an exit arguement */
	{
		/*check_status = _error_atoi(f->argv[1]);
		if (check_status == -1)
		{
			f->status = 2;
			print_error(f, "Illegal number: ");
			_errorputs(f->argv[1]);
			_eputchar('\n');
			return (1);
		}*/
		f->error_num = _error_atoi(f->argv[1]);
		return (-2);
	}
	f->error_num = -1;
	return (-2);
}

