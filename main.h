#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

#define BUFF_SIZE 1024

int _putchar(char c);
int _printf(const char *format, ...);
int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);
int print_integer(va_list args);
int print_binary(va_list args);
int print_unsigned(va_list args);
int print_octal(va_list args);
int print_hex(va_list args);
int cap_hex(va_list args);
/**
 * struct printf_flag - A struct op.
 * @c: The specifier.
 * @f: The associated function.
 */
typedef struct printf_flag
{
	char *c;
	int (*f)(va_list);
} flags;

#endif
