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
		{"S", print_string},
		{"%", print_percent},
		{"d", print_integer},
		{"i", print_integer},
		{"b", print_binary},
		{"u", print_unsigned},
		{"o", print_octal},
		{"x", print_hex},
		{"X", cap_hex},
		{"p", pointer},
		{"r", print_string_reversed},
		{"R", print_rot13},
		{"+", print_plus_flag},
		{" ", print_space_flag},
		{"#", print_hash_flag_hex},
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

			if (*format != '\0')
			{
				func = get_op(format);
				if (func == NULL)
				{
					_putchar('%');
					_putchar(*format);
					i += 2;
				}
				else
				{
					i += func(args);
				}
			}
			else
			{
				return (-1);
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
