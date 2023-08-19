#include "main.h"
#include <stdarg.h>
#include <stdio.h>
/**
 * print_char - Function to handle %c formatting
 * @args: argument list
 */
void print_char(va_list args)
{
	char ch = va_arg(args, int);

	_putchar(ch);
}
/**
 * print_string - Function to handle %s formatting
 * @args: argument list
 */
void print_string(va_list args)
{
	char *s = va_arg(args, char *);

	while (*s != '\0')
	{
		_putchar(*s);
		s++;
	}
}
/**
 * print_percent - Function to handle %% formatting
 */
void print_percent(void)
{
	_putchar('%');
}
/**
 * _printf - a function that produces output according to a format
 * @format: character string
 * @...: Ellipsis
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	int i = 0;
	va_list args;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					print_char(args);
					break;
				case 's':
					print_string(args);
					break;
				case '%':
					print_percent();
					break;
				default:
					_putchar('%');
					_putchar(*format);
			}
		}
		else
		{
			_putchar(*format);
		}
		i++;
		format++;
	}
	va_end(args);
	return (i);
}
