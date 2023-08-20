#include <stdarg.h>
#include "main.h"
/**
 * pointer - prints the hexadecimal value
 * @args: variable argument
 * Return: (0);
 */
int pointer(va_list args)
{
	char *value = va_arg(args, char *);

	_putchar('-');
	while (*value)
	{
		_putchar(*value);
		value++;
	}
	return (0);
}
