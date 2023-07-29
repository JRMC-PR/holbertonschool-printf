#include "main.h"
#include <unistd.h>
#include <stdio.h>
#include <string.h>

/**
 * print_char - a function that prints a char
 * @args: argument of the list
 * Return: count
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
 * Return: count
 */
int print_int(va_list args)
{
	int n = va_arg(args, int);
	int num, last = n % 10, digit, exp = 1;
	int i = 1;

	n = n / 10;
	num = n;

	if (last < 0)
	{
		_putchar('-');
		num = -num;
		n = -n;
		last = -last;
		i++;
	}
	if (num > 0)
	{
		while (num / 10 != 0)
		{
			exp = exp * 10;
			num = num / 10;
		}
		num = n;
		while (exp > 0)
		{
			digit = num / exp;
			_putchar(digit + '0');
			num = num - (digit * exp);
			exp = exp / 10;
			i++;
		}
	}
	_putchar(last + '0');

	return (i);
}

/**
 * print_mod - a function that prints a %
 * @args: argument of the list
 * Return: count
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
 * print_string - a function that prints a %
 * @args: argument of the list
 * Return: count
 */
int print_string(va_list args)
{
	/*Variales*/
	char *string = va_arg(args, char *);
	int count = 0;
	int i = 0;

	if (string == NULL)
		string = "(null)";
	for (i = 0; string[i] != '\0'; i++)
	{
		_putchar(string[i]);
		count++;
	}
	return (count);
}
