#ifndef HEADER_H
#define HEADER_H

int _printf(const char *format, ...);
int print_char(va_list c);
int print_string(va_list s);
int print_decimal(va_list d);
int print_binary(va_list b);
int print_unsigned_int(va_list);
int print_int(va_list i);
int print_octal(va_list o);
int print_hexa(va_list x);
int print_hexa_dem(va_list X);
int print_percent(va_list p);
int print_reverse(va_list r);
int print_rot13string(va_list R);
int _putchar(char c);

#endif
