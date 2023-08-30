#include "main.h"

/**
 * print_binary - to print an unsigned integer in binary
 * @args: variable arg
 * @c: current char
 * @next: next char
 * @__attribute__((unused)): unused var
 * Return: Integer
 */
int print_binary(va_list args,
		char c __attribute__((unused)),
		__attribute__((unused)) char next)
{
	unsigned int value = va_arg(args, unsigned int);
	int binary[BUFF_SIZE];
	int index = 0, count = 0, i;

	if (value == 0)
	{
		_putchar('0');
		return (1);
	}
	while (value > 0)
	{
		binary[index++] = value % 2;
		value = value / 2;
	}
	for (i = index - 1; i >= 0; i--)
	{
		count += _putchar(binary[i] + '0');
	}
	return (count);
}
/**
 * print_unsigned - to print an unsigned integer in binary
 * @args: variable arg
 * @c: current char
 * @next: next char
 * @__attribute__((unused)): unused var
 * Return: Integer
 */
int print_unsigned(va_list args,
		char c __attribute__((unused)),
		__attribute__((unused)) char next)
{
	unsigned int result = va_arg(args, unsigned int);
	char buffer[BUFF_SIZE];
	int index = 0, count = 0, i;

	if (result == 0)
	{
		_putchar('0');
		return (1);
	}
	while (result > 0)
	{
		buffer[index++] = '0' + (result % 10);
		result = result / 10;
	}
	for (i = index - 1; i >= 0; i--)
	{
		count += _putchar(buffer[i]);
	}
	return (count);
}
/**
 * print_octal - to print an unsigned integer in octal
 * @args: variable arg
 * @c: current char
 * @next: next char
 * @__attribute__((unused)): unused var
 * Return: Integer
 */
int print_octal(va_list args,
		char c __attribute__((unused)),
		__attribute__((unused)) char next)
{
	unsigned int value = va_arg(args, unsigned int);
	int octal[BUFF_SIZE];
	int index = 0, count = 0, i;

	if (value == 0)
	{
		_putchar('0');
		return (1);
	}
	else
	{
		count += handle_custom_flags(c, next);
	}

	while (value > 0)
	{
		octal[index++] = value % 8;
		value = value / 8;
	}
	for (i = index - 1; i >= 0; i--)
	{
		count += _putchar(octal[i] + '0');
	}
	return (count);
}

/**
 * print_hex - prints the hexadecimal value
 * @args: variable argument
 * @c: current char
 * @next: next char
 * @__attribute__((unused)): unused var
 * Return: Integer
 */
int print_hex(va_list args,
		char c __attribute__((unused)),
		__attribute__((unused)) char next)
{
	unsigned int value = va_arg(args, unsigned int);
	char hexa[BUFF_SIZE];
	int index = 0, count = 0, i;

	char hex_digits[] = "0123456789abcdef";

	if (value == 0)
	{
		_putchar('0');
		return (1);
	}
	count += handle_custom_flags(c, next);

	while (value > 0)
	{
		hexa[index++] = hex_digits[value % 16];
		value = value / 16;
	}
	for (i = index - 1; i >= 0; i--)
	{
		count += _putchar(hexa[i]);
	}
	return (count);
}
/**
 * cap_hex - prints the hexadecimal value
 * @args: variable arg
 * @c: current char
 * @next: next char
 * @__attribute__((unused)): unused var
 * Return: Integer
 */
int cap_hex(va_list args,
		char c __attribute__((unused)),
		__attribute__((unused)) char next)
{
	unsigned int value = va_arg(args, unsigned int);
	char hexa[BUFF_SIZE];
	int index = 0, count = 0, i;

	char hex_digits[] = "0123456789ABCDEF";

	if (value == 0)
	{
		_putchar('0');
		return (1);
	}
	count += handle_custom_flags(c, next);

	while (value > 0)
	{
		hexa[index++] = hex_digits[value % 16];
		value = value / 16;
	}
	for (i = index - 1; i >= 0; i--)
	{
		count += _putchar(hexa[i]);
	}
	return (count);
}
