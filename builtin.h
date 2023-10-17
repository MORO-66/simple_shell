#ifndef BUILTIN_H
#define BUILTIN_H


/**
 *struct builtin - contains a builtin string and related function
 *@type: the builtin command flag
 *@func: the function
 */
typedef struct builtin
{
	char *type;
	int (*func)(info_t *);
} builtin_table;

int find_builtin(info_t *);
int _myenv(info_t *);
int _unsetenv(info_t *, char *);
int _setenv(info_t *, char *, char *);
int _myexit(info_t *);
int _mycd(info_t *);
int _myhelp(info_t *);
int _myhistory(info_t *);
int _myalias(info_t *);

#endif