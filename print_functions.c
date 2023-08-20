#include "main.h"

/**
 * print_char - prints char
 * @args: variable arguments
 * Return: (0)
 */
int print_char(va_list args)
{
	char ch = va_arg(args, int);

	_putchar(ch);
	return (0);
}


/**
 * print_string - prints strings
 * @args: variable arguments
 * Return: integer
 */
int print_string(va_list args)
{
	char *s = va_arg(args, char *);

	while (*s != '\0')
	{
		_putchar(*s);
		s++;
	}
	return (0);
}

/**
 * print_percent - prints %
 * @args: variable arg
 * Return: integer
 */
int print_percent(va_list __attribute__((unused)) args)
{
	_putchar('%');
	return (0);
}
