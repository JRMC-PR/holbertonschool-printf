#include "main.h"
#include <unistd.h>
#include <stdio.h>
#include <string.h>

/**
 * print_char - a function that prints a char
 * @args: argument of the list
 *
 */
int print_char(va_list args)
{
	/*variables*/
	int count = 0;

	_putchar(va_arg(args, int));
	count++;
	return (count);
}

/**
 * print_int - a function that prints an integer
 * @args: argument of the list
 */
int print_int(va_list args)
{
	/*Variables*/
	int num = va_arg(args, int), count = 0;
	char buffer[12]; /** store the int string, size of int buffer */
	int printed_chars = 0;
	int chars_written = sprintf(buffer, "%d", num);

	if (chars_written > 0)
	{
		printed_chars += write(STDOUT_FILENO, buffer, chars_written);
	}

	if (printed_chars <= 0)
	{
		write(STDOUT_FILENO, "Conversion error", 16);
	}
	return (count);
}

/**
 * print_mod - a function that prints a %
 * @args: argument of the list
 */
int print_mod(va_list args)
{
	/*Variables*/
	int count = 0;
	char character = '%';

	write(STDOUT_FILENO, &character, 1);
	count++;
	(void)args;
	return (count);
}

/**
 * print_string - a function that prints a string
 * @args: argument of the list
 */
int print_string(va_list args)
{
	/*Variales*/
	char *string = va_arg(args, char *);
	int count = 0;

	if (string == NULL)
		string = "(nil)";
	write(STDOUT_FILENO, string, strlen(string));
	count++;
	return (count);
}
