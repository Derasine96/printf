#include "main.h"

/**
 * print_binary - to print an unsigned integer in binary
 * @args: variable arg
 * Return: (0)
 */
int print_binary(va_list args)
{
	unsigned int value =  va_arg(args, unsigned int);
	int binary[32];
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
	char buffer[32];
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
