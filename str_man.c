#include "headers.h"
/**
 **_chr_search - locates a character in a string
 *@string: the string to be parsed
 *@cha: the character to look for
 *Return: (s) a pointer to the memory area s
 */
char *_chr_search(char *string, char cha)
{
	do {
		if (*string == cha)
			return (string);
	} while (*string++ != '\0');

	return (NULL);
}

/**
 * dup_chars - duplicates characters
 * @string_path: the PATH string
 * @sta: starting index
 * @sop: stopping index
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
