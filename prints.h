#ifndef PRINTS_H
#define PRINTS_H

void _eputs(char *);
int _eputchar(char);
int _putfd(char c, int fd);
int _putsfd(char *str, int fd);
void _puts(char *);
int _putchar(char);
void print_error(info_t *, char *);
int print_d(int, int);


#endif