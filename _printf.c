#include <stdio.h>
#include <stdarg.h>
#include "main.h"
/**
 * _printf - produces output according to a format
 * @format: character string
 * Return: number of characters printed
 */

int _printf(const char *format, ...)
{

	va_list(args);
	int i = 0, count = 0;

	va_start(args, format);

	while (format[i])
	{
		for (i = 0; format[i] != '\0'; i++)
		{
			if (format[i] == '%')
			{
				putchar('%');
				i++;
			}
			else
			{
				if (format[i] == 'c')
				{
					printf("%c", va_arg(args, int));
					count++;
				}
				else
				{
					if (format[i] == 's')
					{
						printf("%s", va_arg(args, char*));
						count++;
					}
				}
				putchar(*format);

				count++;
			}
			format++;
		}
		va_end(args);
		return (count);
	}
