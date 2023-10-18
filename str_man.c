#include "headers.h"
/**
 **_strchr - locates a character in a string
 *@s: the string to be parsed
 *@c: the character to look for
 *Return: (s) a pointer to the memory area s
 */
char * _chr_search(char *string, char cha)
{
	do {
		if (*string == cha)
			return (string);
	} while (*string++ != '\0');

	return (NULL);
}

/**
 * dup_chars - duplicates characters
 * @pathstr: the PATH string
 * @start: starting index
 * @stop: stopping index
 *
 * Return: pointer to new buffer
 */
char *dup_chars(char *string_path, int sta, int sop)
{
	static char buf[1024];
	int i = 0, k = 0;

	for (k = 0, i = sta; i < sop; i++)
		if (string_path[i] != ':')
			buf[k++] = string_path[i];
	buf[k] = 0;
	return (buf);
}
