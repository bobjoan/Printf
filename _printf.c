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
	int i = 0, count = 0;

	va_start(args, format);

	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
			{
				putchar(va_arg(args, int));
				count++;
			}
			else if (format[i] == 's')
			{
				printf("%s", va_arg(args, char*));
				count++;
			}
		}
		else
		{
			putchar(format[i]);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}
