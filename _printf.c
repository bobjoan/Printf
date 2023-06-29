#include <unistd.h>
#include "main.h"
#include <stdarg.h>

int _printf(const char *format, ...);
/**
 * _printf - produces output according to a format
 * @format: character string
 * Return: ...
 */

int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0, letter, strCount;
	char *str;

	if (format == NULL)
		return (-1);

	va_start(args, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
				return (-1);
			else if (format[i] == '%')
			{
				write(1, "%", 1);
				count++;
			}
			else if (format[i] == 'c')
			{
				letter = va_arg(args, int);
				write(1, &letter, 1);
				count++;
			}
			else if (format[i] == 's')
			{
				str = va_arg(args, char *);
				strCount = strings(str);
				count = count + strCount;
			}
			else
			{
				write(1, "%", 1);
				write(1, &format[i], 1);
				count = count + 2;
			}
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
	}
	va_end(args);
	return (count);
}
