#include "main.h"

/**
 * print_char - prints char
 * @args: variable arguments
 * @c: current char
 * @next: next char
 * @__attribute__((unused)): unused var
 * Return: Integer
 */
int print_char(va_list args,
		char c __attribute__((unused)),
		__attribute__((unused)) char next)
{
	char ch = va_arg(args, int);

	_putchar(ch);
	return (1);
}

/**
 * print_string - prints strings
 * @args: variable arguments
 * @c: current char
 * @next: next char
 * @__attribute__((unused)): unused var
 * Return: Integer
 */
int print_string(va_list args,
		char c __attribute__((unused)),
		__attribute__((unused)) char next)
{
	char *s = va_arg(args, char *);

	int i = 0;

	if (s != NULL)
	{

		i += handle_custom_flags(c, next);
		while (*s != '\0')
		{
			if (*s == '\n')
			{
				_putchar('\n');
				s++;
				i++;
			}
			else if ((*s > 0 && *s < 32) || *s >= 127)
			{
				i += append_hexa_code(*s);
				s++;
			}
			else
			{
				_putchar(*s);
				s++;
				i++;
			}
		}
	}
	else
	{
		i += print_null();
	}
	return (i);
}

/**
 * print_percent - prints %
 * @args: variable arg
 * @c: current char
 * @next: next char
 * @__attribute__((unused)): unused var
 * Return: Integer
 */
int print_percent(va_list args __attribute__((unused)),
		char c __attribute__((unused)),
		__attribute__((unused)) char next)
{
	_putchar('%');
	return (1);
}

/**
 * check_integer - prints the intger
 * @res: number to print
 * Return: Integer
 */
int check_integer(int res)
{
	unsigned int val;
	int i = 0;

	val = res;

	if (res < 0)
	{
		_putchar('-');
		val = -val;
		i++;
	}

	if (val <= 9)
	{
		i += _putchar(val + '0');
		return (i);
	}
	i++;

	if (val / 10)
	{
		i += check_integer(val / 10);
		_putchar((val % 10) + '0');
		return (i);
	}
	return (0);
}

/**
 * print_integer - prints whole number
 * @args: variable arguments
 * @c: current char
 * @next: next char
 * @__attribute__((unused)): unused var
 * Return: Integer
 */
int print_integer(va_list args,
		char c __attribute__((unused)),
		__attribute__((unused)) char next)
{
	int res = 0, val;

	val = va_arg(args, int);

	if (val >= 0)
	{
		res += handle_custom_flags(c, next);
	}
	res += check_integer(val);
	return (res);
}
