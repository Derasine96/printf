#include "main.h"

/**
 * _putchar - writes the chararacter c to stdout
 * @c: The character to print
 *
 * Return: 1 (success)
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
