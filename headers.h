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
 * struct liststr - singly linked list
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
 *struct passinfo - contains pseudo-arguements to pass into a function,
 *		allowing uniform prototype for function pointer struct
 *@arg: a string generated from getline containing arguements
 *@argv: an array of strings generated from arg
 *@path: a string path for the current command
 *@argc: the argument count
 *@line_count: the error count
 *@err_num: the error code for exit()s
 *@linecount_flag: if on count this line of input
 *@fname: the program filename
 *@env: linked list local copy of environ
 *@environ: custom modified copy of environ from LL env
 *@history: the history node
 *@alias: the alias node
 *@env_changed: on if environ was changed
 *@status: the return status of the last exec'd command
 *@cmd_buf: address of pointer to cmd_buf, on if chaining
 *@cmd_buf_type: CMD_type ||, &&, ;
 *@readfd: the fd from which to read line input
 *@histcount: the history line number count
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

	char **cmd_buff; /* pointer to cmd ; chain buffer, for memory mangement */
	int hist_c;
	int r_fd;
	int cmd_buf; /* CMD_type ||, &&, ; */
} inf;

#define INFO \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}


/* toem_shloop.c */
int head_shell(inf *, char **);
/*int which_cmd(inf*);*/
void find_cmd(inf *);
void cmd_fork(inf *);

/* toem_parser.c */
int cmd_sure(inf *, char *);
char *dup_chars(char *, int, int);
char * where_path(inf *, char *, char *);

/* toem_errors.c */
void _errorputs(char *);
int _eputchar(char);
int _put_as_fd(char c, int fd);
int _puts_as_fd(char *str, int fd);

/* toem_string.c */
int _strlen(char *);
int _strcmp(char *, char *);
char * start(const char *, const char *);
char *_strcat(char *, char *);
ssize_t buf_in(inf* f, char** buff, size_t* lennn);
/* toem_string1.c */
char *_strcpy(char *, char *);
char *_strdup(const char *);
void _puts(char *);
int _putchar(char);

/* toem_exits.c */
char *_strncpy(char *, char *, int);
char *_strncat(char *, char *, int);
char * _chr_search(char *, char);

/* toem_tokenizer.c */
char** string_to_words(char*, char*);

/* toem_realloc.c */
char * _mem_set(char *, char, unsigned int);
void kno_free(char **);
void *_realloc(void *, unsigned int, unsigned int);


int is_delim(char, char *);

void print_error(inf *, char *);
int print_d(int, int);
/*char* convert_number(long int, int, int);*/

ssize_t _rd_buf(inf* info, char* buf, size_t* i);

/*int _myhelp(inf*);*/


ssize_t get_line(inf *);
int _getline(inf *, char **, size_t *);
void Handler(int);


void null_info(inf *);
void reset_info(inf *, char **);
void free_info(inf *, int);


char *_getenv(inf *, const char *);




char ** take_environ(inf *);


char * get_h_f(inf *info);
int enf_history(inf *info);
int _r_history(inf *info);
int Creat_his_l(inf *info, char *buf, int linecount);
int resum(inf *info);


list *add_node_end(list **, const char *, int);

int delete_node_at_index(list **, unsigned int);
void free_list(list **);


size_t len_of_list(const list *);
char **list_to_strings(list *);
size_t print_list(const list *);

int replace_string(char **, char *);

#endif
