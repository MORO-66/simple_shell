#include "headers.h"

/**
 * **string_to_words - splits a st Repeat delimiters are ignored
 * @str: the input string
 * @d: the delimeter stri
 * Return: a pointer to ags, or NULL on failure
 */

char **string_to_words(char *string, char *is)
{
	int a, b, c, d, words_numbers = 0;
	char **tring;

	if (string == NULL || string[0] == 0)
		return (NULL);
	if (!is)
		is = " ";
	for (a = 0; string[a] != '\0'; a++)
		if (!is_delim(string[a], is) && (is_delim(string[a + 1], is) || !string[a + 1]))
			words_numbers++;

	if (words_numbers == 0)
		return (NULL);
	tring = malloc((1 + words_numbers) * sizeof(char *));
	if (!tring)
		return (NULL);
	for (a = 0, b = 0; b < words_numbers; b++)
	{
		while (is_delim(string[a], is))
			a++;
		c = 0;
		while (!is_delim(string[a + c], is) && string[a + c])
			c++;
		tring[b] = malloc((c + 1) * sizeof(char));
		if (!tring[b])
		{
			for (c = 0; c < b; c++)
				free(tring[c]);
			free(tring);
			return (NULL);
		}
		for (d = 0; d < c; d++)
			tring[b][d] = string[a++];
		tring[b][d] = 0;
	}
	tring[b] = NULL;
	return (tring);
}
