#include "main.h"

/**
 * print_binary - to print an unsigned integer in binary
 * @args: variable arg
 * Return: (0)
 */
int print_binary(va_list args)
{
	unsigned int value =  va_arg(args, unsigned int);
	int binary[BUFF_SIZE];
	int index = 0, i;

	if (value == 0)
	{
		_putchar('0');
		return (0);
	}
	while (value > 0)
	{
		binary[index++] = value % 2;
		value = value / 2;
	}
	for (i = index - 1; i >= 0; i--)
	{
		_putchar(binary[i] + '0');
	}
	return (0);
}
/**
 * print_unsigned - to print an unsigned integer in binary
 * @args: variable arg
 * Return: (0)
 */
int print_unsigned(va_list args)
{
	unsigned int result =  va_arg(args, unsigned int);
	char buffer[BUFF_SIZE];
	int index = 0, i;

	if (result == 0)
	{
		_putchar('0');
		return (0);
	}
	while (result > 0)
	{
		buffer[index++] = '0' + (result % 10);
		result = result / 10;
	}
	for (i = index - 1; i >= 0; i--)
	{
		_putchar(buffer[i]);
	}
	return (0);
}
/**
 * print_octal - to print an unsigned integer in octal
 * @args: variable arg
 * Return: (0)
 */
int print_octal(va_list args)
{
	unsigned int value =  va_arg(args, unsigned int);
	int octal[BUFF_SIZE];
	int index = 0, i;

	if (value == 0)
	{
		_putchar('0');
		return (0);
	}
	while (value > 0)
	{
		octal[index++] = value % 8;
		value = value / 8;
	}
	for (i = index - 1; i >= 0; i--)
	{
		_putchar(octal[i] + '0');
	}
	return (0);
}

/**
 * print_hex - prints the hexadecimal value
 * @args: variable argument
 * Return: (0);
 */
int print_hex(va_list args)
{
	unsigned int value = va_arg(args, unsigned int);
	char hexa[BUFF_SIZE];
	int index = 0, i;

	char hex_digits[] = "0123456789abcdef";

	if (value == 0)
	{
		_putchar('0');
		return (0);
	}
	while (value > 0)
	{
		hexa[index++] = hex_digits[value % 16];
		value = value / 16;
	}
	for (i = index - 1; i >= 0; i--)
	{
		_putchar(hexa[i]);
	}
	return (0);
}
