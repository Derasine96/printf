#include "main.h"
/**
 * pointer - prints the hexadecimal value
 * @args: variable argument
 * Return: (0);
 */
int pointer(va_list args)
{
	void *addr = va_arg(args, void *);
	unsigned long num_addr;
	char map_to[] = "0123456789abcdef";
	int i = 0, count = 0, values[BUFF_SIZE];

	if (addr == NULL)
		return (write(1, "(nil)", 5));

	num_addr = (unsigned long) addr;
	_putchar('0');
	_putchar('x');
	count += 2;

	while (num_addr > 0)
	{
		values[i] = map_to[num_addr % 16];
		num_addr /= 16;
		i++;
	}

	while (i > 0)
	{
		count += _putchar(values[i - 1]);
		i--;
	}
	return (count);
}
/**
 * print_string_reversed - prints strings reverse
 * @args: variable arguments
 * Return: integer
 */
int print_string_reversed(va_list args)
{
	char *s = va_arg(args, char *);

	int i = 0, count = 0;

	if (s == NULL)
	{
		s = ")null(";
	}

	while (s[i])
	{
		i++;
	}
	while (i > 0)
	{
		count += _putchar(s[i - 1]);
		i--;
	}
	return (count);
}
/**
 * print_rot13 - print 13th char from a chae.
 * @args: variable arguments
 * Return: integer
 */
int print_rot13(va_list args)
{
	char *y = va_arg(args, char *);

	int n, i = 0, count = 0;
	char s[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char t[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";

	if (y == NULL)
	{
		y = "(null)";
	}

	while (y[i] != '\0')
	{
		char ch = y[i];

		for (n = 0; s[n] != '\0'; n++)
		{
			if (s[n] == y[i])
			{
				ch = t[n];
				break;
			}
		}
		count += _putchar(ch);
		i++;
	}
	return (count);
}
