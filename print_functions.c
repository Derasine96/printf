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
			if ((*s > 0 && *s < 32) || *s >= 127)
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
 * @args: variable arg
 * Return: Integer
 */
int print_integer(va_list args)
{
	int res, val;

	val = va_arg(args, int);
	res = check_integer(val);
	return (res);
}
