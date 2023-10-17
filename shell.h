#ifndef SHELL_H
#define SHELL_H

char **get_environ(info_t *);
int hsh(info_t *, char **);
void find_cmd(info_t *);
int is_cmd(info_t *, char *);
char *find_path(info_t *, char *, char *);
void fork_cmd(info_t *);
ssize_t get_input(info_t *);
int _getline(info_t *, char **, size_t *);
void sigintHandler(int);
char *_getenv(info_t *, const char *);
int is_chain(info_t *, char *, size_t *);
void check_chain(info_t *, char *, size_t *, size_t, size_t);
#endif