#include "main.h"

/**
 * print_null - prints (null)
 * Return: int
 */
int print_null(void)
{
	_putchar('(');
	_putchar('n');
	_putchar('u');
	_putchar('l');
	_putchar('l');
	_putchar(')');
	return (6);
}
/**
 * append_hexa_code - Append ascci in hexadecimal code to buffer
 * @ascii_code: ASSCI CODE.
 *
 * Return: Always 1
 */
int append_hexa_code(char ascii_code)
{
	char map_to[] = "0123456789ABCDEF";
	int i = 0, hex[BUFF_SIZE];
	/* The hexa format code is always 2 digits long */
	if (ascii_code < 0)
		ascii_code *= -1;

	_putchar('\\');
	_putchar('x');

	hex[i] = map_to[ascii_code / 16];
	hex[i + 1] = map_to[ascii_code % 16];

	i = 0;
	while (i < 2)
	{
		_putchar(hex[i]);
		i++;
	}
	return (4);
}
/**
 * print_plus_flag - handle plus flag
 * @args: Variable argument
 *
 * Return: Always 1 or 0
 */
int print_plus_flag(va_list args)
{
	int num = va_arg(args, int);

	if (num >= 0)
	{
		putchar('+');
		return (1);
	}
	else
		return (0);
}
/**
 * print_space_flag - handle space flag
 * @args: Variable argument
 *
 * Return: Always 1 or 0
 */
int print_space_flag(va_list args)
{
	int num = va_arg(args, int);

	if (num >= 0)
	{
		putchar(' ');
		return (1);
	}
	else
		return (0);
}
/**
 * print_hash_flag_hex - handle hash flag
 * @args: Variable argument
 *
 * Return: Always 1 or 0
 */
int print_hash_flag_hex(va_list args)
{
	int num = va_arg(args, int);

	if (num >= 0)
	{
		putchar('#');
		return (1);
	}
	else
		return (0);
}
