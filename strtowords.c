#include "headers.h"

/**
 * **strtow - splits a st Repeat delimiters are ignored
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

/**
 * **strtow2 - splits ao words
 * @str: the input stri
 * @d: the delimeter
 * Return: a pointer tof strings, or NULL on failure
 */
/*
char **strtow2(char *str, char d)
{
	int i, j, k, m, numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (i = 0; str[i] != '\0'; i++)
		if ((str[i] != d && str[i + 1] == d) ||
		    (str[i] != d && !str[i + 1]) || str[i + 1] == d)
			numwords++;
	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (i = 0, j = 0; j < numwords; j++)
	{
		while (str[i] == d && str[i] != d)
			i++;
		k = 0;
		while (str[i + k] != d && str[i + k] && str[i + k] != d)
			k++;
		s[j] = malloc((k + 1) * sizeof(char));
		if (!s[j])
		{
			for (k = 0; k < j; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[j][m] = str[i++];
		s[j][m] = 0;
	}
	s[j] = NULL;
	return (s);
}
*/