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

/**
 * print_cap_string - prints strings
 * @args: variable arguments
 * Return: integer
 */
int print_cap_string(va_list args)
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
