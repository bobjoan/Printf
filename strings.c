#include "main.h"
#include <unistd.h>
/**
 * strings - strings to print
 * @str: ...
 * Return: ...
 */
int strings(char *str)
{
	int i;

	if (str == NULL)
	{
		i = write(1, "(null)", 6);
		return (i);
	}
	for (i = 0; str[i] != '\0'; i++)
	{
		write(1, &str[i], 1);
	}
	return (i);
}
