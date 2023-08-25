#include "monty.h"
#include <stdlib.h>

/**
 * _strdup - Allocates memory space for a new string and duplicates string
 *	given as parameter in new string
 * @str: Input string
 * Return: Pointer to duplicated string
 */

char *_strdup(char *str)
{
	int i, length = 0;
	char *new_str;

	/* Return NULL if no string is passed */
	if (str == NULL)
	{
		return (NULL);
	}

	/* Calculate length of string given as parameter */
	while (str[length] != '\0')
		length++;

	/* Allocate space in memory for new string */
	new_str = malloc(1 + length * sizeof(char));

	/* Return NULL if memory allocation fails */
	if (new_str == NULL)
		return (NULL);

	/* Store copy of parameter string in new string */
	for (i = 0; i < length; i++)
	{
		new_str[i] = str[i];
	}
	return (new_str);
}
