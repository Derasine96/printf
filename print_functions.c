#include "main.h"

/**
 * print_char - prints char
 * @args: variable arguments
 * Return: Integer
 */
int print_char(va_list args)
{
	char ch = va_arg(args, int);

	_putchar(ch);
	return (1);
}

/**
 * print_string - prints strings
 * @args: variable arguments
 * Return: integer
 */
int print_string(va_list args)
{
	char *s = va_arg(args, char *);
	int i = 0;

	if (s != NULL)
	{
		while (*s != '\0')
		{
			_putchar(*s);
			s++;
			i++;
		}
	} else
	{
		i += print_null();
	}
	return (i);
}

/**
 * print_percent - prints %
 * @args: variable arg
 * @_attribute_((unused): unused variables
 * Return: integer
 */
int print_percent(va_list args __attribute__((unused)))
{
	_putchar('%');
	return (1);
}

/**
 * check_integer - prints the intger
 * @res: number to print
 */
void check_integer(int res)
{
	if (res < 0)
	{
		_putchar('-');
		res = -res;
	}

	if (res / 10)
		check_integer(res / 10);
	_putchar(res % 10 + '0');
}

/**
 * print_integer - prints whole number
 * @args: variable arg
 * Return: (0)
 */
int print_integer(va_list args)
{
	int val = va_arg(args, int);

	check_integer(val);
	return (0);
}
