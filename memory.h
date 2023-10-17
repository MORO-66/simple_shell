#ifndef MEMORY_H
#define MEMORY_H

char *_memset(char *, char, unsigned int);
void ffree(char **);
void *_realloc(void *, unsigned int, unsigned int);
void free_info(info_t *, int);
int bfree(void **);

#endif