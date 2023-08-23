#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFF_SIZE 1024

int print_null(void);
int _putchar(char c);
int _printf(const char *format, ...);
int print_char(va_list args, char c, char next);
int print_string(va_list args, char c, char next);
int print_percent(va_list args, char c, char next);
int print_integer(va_list args, char c, char next);
int print_binary(va_list args, char c, char next);
int print_unsigned(va_list args, char c, char next);
int print_octal(va_list args, char c, char next);
int print_hex(va_list args, char c, char next);
int cap_hex(va_list args, char c, char next);
int pointer(va_list args, char c, char next);
int append_hexa_code(char);
int print_string_reversed(va_list args, char c, char next);
int print_rot13(va_list args, char c, char next);
int handle_custom_flags(char c, char next);
/**
 * struct printf_flag - A struct op.
 * @c: The specifier.
 * @f: The associated function.
 */
typedef struct printf_flag
{
	char *c;
	int (*f)(va_list, char, char);
} flags;

#endif
