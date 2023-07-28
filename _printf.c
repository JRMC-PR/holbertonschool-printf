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
	int i = 0, j = 0;
	int printed_chars = 0;
	int found = 0;
	print func_type[] = {
		{"c", print_char},
		{"s", print_string},
		{"%", print_mod},
		{"d", print_int},
		{"i", print_int},
		{NULL, NULL}};
	va_list args;

	va_start(args, format);

	while (format != NULL && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			while (format[i] == ' ')
				i++;
			while (format[i + 1] == ' ')
			{
				i++; /* Skip any spaces */
			}
			found = 0;
			for (j = 0; j < 5; j++)
			{
				if (format[i] == *func_type[j].indi)
				{
					printed_chars += func_type[j].handler(args);
					found = 1;
					break;
				}
			}
			/* If no format specifier is found, print the '%' character itself */
			if (!found && format[i] != '\0')
			{
				_putchar('%');
				printed_chars++;
				i--;
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

	return printed_chars;
}
