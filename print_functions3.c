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
