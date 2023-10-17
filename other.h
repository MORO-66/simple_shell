#ifndef OTHER_H
#define OTHER_H

int loophsh(char **);

int interactive(info_t *);
int is_delim(char, char *);
int _isalpha(int);
int _atoi(char *);

int _erratoi(char *);
char *convert_number(long int, int, int);
void remove_comments(char *);

void clear_info(info_t *);
void set_info(info_t *, char **);


int populate_env_list(info_t *);

int replace_alias(info_t *);
int replace_vars(info_t *);
int replace_string(char **, char *);

#endif