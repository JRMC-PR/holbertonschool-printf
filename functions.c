#include "main.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>


/**
 * print_char - a function that prints a char
 * @args: argument of the list
 */
void print_char(va_list args)
{
	_putchar(va_arg(args, int));
}


/**
 * print_int - a function that prints an integer
 * @args: argument of the list
 */
void print_int(va_list args)
{
	int num = va_arg(args, int);
	char buffer[12]; /** store the int string, size of int buffer */
	int printed_chars = 0;

	int chars_written = sprintf(buffer, "%d", num);
	if (chars_written > 0)
	{
		printed_chars = write(STDOUT_FILENO, buffer, chars_written);
	}

	if (printed_chars <= 0)
	{
		write(STDOUT_FILENO, "Conversion error", 16);
	}
}

/**
 * print_string - a function that prints a string
 * @args: argument of the list
 */
void print_string(va_list args)
{
	char *string = va_arg(args, char *);
	if (string == NULL)
		string = "(nil)";
	write(STDOUT_FILENO, string, strlen(string));
}

/**
 * print_mod - a function that prints a %
 * @args: argument of the list
 */
void print_mod(va_list args)
{

	char character = '%';
	write(STDOUT_FILENO, &character, 1);
	(void)args;
}
