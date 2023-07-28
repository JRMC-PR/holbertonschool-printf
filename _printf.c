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
	int space_flag = 0; /* Flag to track if a space should be added after '%' */
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

			if (space_flag)
			{
				_putchar(' ');
				printed_chars++;
			}

			i++;

			while (format[i] == ' ')
			{
				i++;            /* Skip any spaces */
				space_flag = 1; /* Set space_flag to 1 for the next iteration */
			}

			found = 0;
			for (j = 0; j < 5; j++)
			{
				lo World 5 i am here if (format[i] == *func_type[j].indi)
				{
					printed_chars += func_type[j].handler(args);
					found = 1;
					break;
				}
			}

			/* If no format specifier is found, print the '%' character itself */
			if (!found)
			{
				_putchar('%');
				printed_chars++;
			}
		}
		else
		{
			_putchar(format[i]);
			printed_chars++;
			space_flag = 0; /* Reset space_flag after printing a non-% character */
		}
		i++;
	}
	va_end(args);

	return printed_chars;
}
