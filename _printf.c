#include <stdio.h>
#include <stdarg.h>
#include "main.h"
/**
 *  _printf - produces output according to a format.
 *  @format: character string
 *  Return: number of characters printed
 */

int _printf(const char *format, ...)
{
	int i = 0, count = 0;

	va_list(args);
	va_start(args, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
		}
		if (format[i] == 'c')
		{
			char c = (char) va_arg(args, int);

			putchar(c);
			count++;
		}
		else if (format[i] == 's')

		{
			char *s = va_arg(args, char *);
			printf("%s", s);

			count++;
		}
		else if (format[i] == '%')
		{
			putchar('%');
			count++;
		}
		else
		{
			putchar(format[i]);
			count++;
		}
	}
	va_end(args);
	return (count);
}

int main()
{
	char c = 'A';
	char *s = "Hello, world!";
	int count = _printf("A char: %c\nA string: %s\nA percent sign: %%\n", c, s);
	printf("Printed %d characters in total.\n", count);
	return (0);
}
