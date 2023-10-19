#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <stddef.h>

#define BUF_FLUSH -1


/* 1 if using system getline() */
#define USE_GETLINE 0

#define HIST_FILE	".simple_shell_history"

extern char **environ;


/**
 * struct li - singly linked list
 * @num: the number field
 * @str: a string
 * @next: points to the next node
 */
typedef struct li
{
	int num;
	char *str;
	struct li *next;
} list;

/**
 *struct info - contains pseudo-arguements to pass into a function,
 *		allowing uniform prototype for function pointer struct
 *@arg: a string generated from getline containing arguements
 *@argv: an array of strings generated from arg
 *@path_: a string path for the current command
 *@argc: the argument count
 *@line_c: the error count
 *@error_num: the error code for exit()s
 *@linecount_f: if on count this line of input
 *@filename: the program filename
 *@enviro: linked list local copy of environ
 *@environ: custom modified copy of environ from LL env
 *@history: the history node
 *@env_ch: on if environ was changed
 *@status: the return status of the last exec'd command
 *@cmd_buf: address of pointer to cmd_buf, on if chaining
 *@cmd_buf: CMD_type ||, &&, ;
 *@r_fd: the fd from which to read line input
 *@hist_c: the history line number count
 */
typedef struct info
{
	char *path_;
	char **argv;
	char *arg;
	unsigned int line_c;
	int linecount_f;
	int error_num;
	int argc;
	list *enviro;
	list *history;
	char **environ;
	char *filename;
	int status;
	int env_ch;
	int hist_c;
	int r_fd;
	int cmd_buf;
} inf;

#define INFO \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, 0, 0, \
	0, 0, 0}


int head_shell(inf *, char **);
void find_cmd(inf *);
void cmd_fork(inf *);
void null_info(inf *info);
int cmd_sure(inf *, char *);
char *dup_chars(char *, int, int);
char *where_path(inf *, char *, char *);
void _errorputs(char *);
int _eputchar(char);
int _put_as_fd(char c, int fd);
int _puts_as_fd(char *str, int fd);

int _strlen(char *);
int _strcmp(char *, char *);
char *start(const char *, const char *);
char *_strcat(char *, char *);
ssize_t buf_in(inf *f, char **buff, size_t *lennn);
char *_strcpy(char *, char *);
char *_strdup(const char *);
void _puts(char *);
int _putchar(char);

char *_strncpy(char *, char *, int);
char *_strncat(char *, char *, int);
char *_chr_search(char *, char);
char **string_to_words(char *, char *);
char *_mem_set(char *, char, unsigned int);
void kno_free(char **);
void *_realloc(void *, unsigned int, unsigned int);
int is_delim(char, char *);
void print_error(inf *, char *);
int print_d(int, int);
ssize_t _rd_buf(inf *info, char *buf, size_t *i);
ssize_t get_line(inf *);
int _getline(inf *, char **, size_t *);
void Handler(int);
void reset_info(inf *, char **);
void f_inf(inf *, int);
char *_getenv(inf *, const char *);
char **take_environ(inf *);
char *get_h_f(inf *info);
int enf_history(inf *info);
int _r_history(inf *info);
int Creat_his_l(inf *info, char *buf, int linecount);
int resum(inf *info);

list *add_node_end(list **, const char *, int);
int delete_node_at_index(list **, unsigned int);
void f_li(list **);

size_t len_of_list(const list *);
char **list_to_strings(list *);


#endif
