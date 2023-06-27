#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include "main.h"
/**
 * _printf -  produces output according to a format
 * @format: character string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0, letter = 0;

	va_start(args, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
			{
				letter = va_arg(args, int);
				write(1, &letter, 1);
				count++;
			}
			else if (format[i] == 's')
			{
				write(1,va_arg(args, char*), 1);
				count++;
			}
		}
		else
		{
			write(1, &format[i],1);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}
