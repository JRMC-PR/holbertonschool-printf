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
	/*Verify that format is not NULL*/
	while (format != NULL && format[i])
	{
		/*check for th emod formater*/
		if (format[i] == '%')
		{
			j = 0;
			/*Move through the stuct indicators */
			while (j < 5)
			{
				/*compare where stand with the indicators*/
				if (format[i + 1] == *func_type[j].indi)
				{
					
					printed_chars += func_type[j].handler(args);
					i++; /* Skip the next character when % is found */
					break;
				} /*end if*/
				j++;
			} /*end inner while*/
		}
		else
		{
			_putchar(format[i]);
			printed_chars++;
		} /*end outer if else*/
		i++;
	} /*en douter while*/
	va_end(args);
	return (printed_chars);
} /*end function*/

