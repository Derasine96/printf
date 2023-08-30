#include "main.h"

/**
 * get_op - prints integer
 * @c: char to check
 * Return: pointer to a function
 */
int (*get_op(const char *c))(va_list, char, char)
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
 * handle_custom_flags - handle flag char
 * @c: char to check
 * @next: next char after c
 * Return: integer
 */
int handle_custom_flags(char c, char next)
{
	int i = 0, res = 0;

	char flag[] = {'+', ' ', '-', '#', '0', '\0'};

	while (flag[i] != '\0')
	{
		if (c == flag[i])
		{
			if (c == '+' && (next == 'd' || next == 'i' || next == 'p'))
			{
				_putchar('+');
				res++;
				break;
			}
			else if (c == '#')
			{
				if (next == 'x')
				{
					_putchar('0');
					_putchar('x');

					res += 2;
				}
				else if (next == 'X')
				{
					_putchar('0');
					_putchar('X');
					res += 2;
				}
				else if (next == 'o')
				{
					_putchar('0');
					res++;
				}
				break;
			}
			else if (c == ' ')
			{
				res++;
				break;
			}
		}
		i++;
	}

	return (res);
}

/**
 * check_custom_flags - handle flag char
 * @c: char to check
 * Return: int
 */
int check_custom_flags(const char c)
{
	int i = 0;

	char flag[] = {'+', ' ', '-', '#', '0', '\0'};

	while (flag[i] != '\0')
	{
		if (c == flag[i])
		{
			return (1);
		}
		i++;
	}
	return (0);
}

/**
 * _printf - a function that produces output according to a format
 * @format: character string
 * @...: Ellipsis
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	int (*func)(va_list, char, char);
	int i = 0;
	char c, next;
	int check_res;
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
				c = *format;
				check_res = check_custom_flags(c);

				if (check_res == 1)
				{
					format++;
				}
				next = *format;

				func = get_op(format);
				if (func == NULL)
				{
					_putchar('%');
					_putchar(*format);
					i += 2;
				}
				else
				{
					i += func(args, c, next);
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
