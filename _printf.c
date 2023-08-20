#include "main.h"

/**
 * get_op - prints integer
 * @c: char to check
 * Return: pointer to a function
 */
int (*get_op(const char *c))(va_list)
{
	int i = 0;

	flags fg[] = {
		{"c", print_char},
		{"s", print_string},
		{"%", print_percent},
		{"d", print_integer},
		{"i", print_integer},
		{"b", print_binary},
		{"u", print_unsigned},
		{"o", print_octal},
		{"x", print_hex},
		{"X", print_hex},
		{NULL, NULL}};

	while (fg[i].c != NULL)
	{
		if (*c == fg[i].c[0])
		{
			return (fg[i].f);
		}
		i++;
	}
	return (NULL);
}

/**
 * _printf - a function that produces output according to a format
 * @format: character string
 * @...: Ellipsis
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	int (*func)(va_list);
	int i = 0;
	va_list args;

	if (!format || (format[0] == '%' && format[1] == '\0'))
		return (-1);

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			func = get_op(format);
			if (func == NULL)
			{
				_putchar('%');
				_putchar(*format);
			}
			else
				func(args);
		}
		else
			_putchar(*format);
		i++;
		format++;
	}
	va_end(args);
	return (i);
}
