#include "main.h"
#include <stdarg.h>
#include <stdio.h>
/**
 * main - a function that produces output according to a format
 * @format: character string
 * @...: Ellipsis
 * Return:  the number of characters printed 
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
			if (*format == 'c')
			{
				int ch = va_arg(args, int);
				_putchar(ch);
				i++;
			}
			else if (*format == 's')
			{
				char *s = va_arg(args, char *);
				while (*s != '\0')
				{
					_putchar(*s);
					s++;
					i++;
				}
			}
			else if (*format == '%')
			{
				_putchar('%');
				i++;
			}
			else
			{
				_putchar('%');
				_putchar(*format);
				i++;
			}
		}
		else
		{
			_putchar(*format);
			i++;
		}
		format++;
	}
	va_end(args);
	return (i);
}

