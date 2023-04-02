#include "monty.h"

/**
 * _isdigit - Checks for a digit
 * Return: 1
 * @c: variable
 */

int _isdigit(char *c)
{
	char *temp = c;


	if (c == NULL)
		return (0);
	if (*temp == '-')
		temp++;

	for (; *temp != '\0'; temp++)
	{
		if ((*temp < '0' || *temp > '9'))
		{
			return (0);
		}
	}
	return (1);
}
