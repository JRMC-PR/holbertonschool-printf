#include "main.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>

/**
 * _printf - a function that behaves like the stdio.h printf();
 * @format: points to a constant format list
 * Return: number of characters printed
 */

int _printf(const char *format, ...)
{
	/* Variables */
	unsigned int i = 0, j = 0;
	int printed_chars = 0; /** To keep track of the total characters printed */
	print func_type[] = {
		{"c", print_char},
		{"s", print_string},
		{"%", print_mod},
		{"d", print_int},
		{"i", print_int},
		{NULL, NULL}};
	va_list args;

	/* Start argument iteration */
	va_start(args, format);
	while (format != NULL && format[i])
	{
		if (format[i] == '%')
		{
			j = 0;
			while (j < 5)
			{
				if (format[i + 1] == *func_type[j].indi)
				{
					func_type[j].handler(args);
					i++; /* Skip the next character when % is found */
					break;
				}
				j++;
			}
		}
		else
		{
			_putchar(format[i]);
			printed_chars++;
		}
		i++;
	}
	va_end(args);
	return (printed_chars);
}

