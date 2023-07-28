# printf

### Description

------------


The printf function sends formatted output to stdout.
A custom _printf() for learning purposes was developed by cohort  #9 students Jimmer and Edward Ortiz.
_printf() function format string is a character string, beginning and ending in its initial shift state, if any. 
These arguments are placed using the percentage '%' operator

------------

#### Compilation

------------



The code must be compiled this way:

**$ gcc -Wall -Werror -Wextra -pedantic *.c**

As a consequence, be careful not to push any c file containing a main function in the root directory of your project (you could have a test folder containing all your tests files including main functions)

The main files will include your main header file (holberton.h): **#include holberton.h**

------------

#### Use & Examples


------------

**Prototype:** int _printf(const char *format, ...);
**Use - General:** _printf("format string", var1, var2, ...);

**Examples:**
 - Basic String: _printf("%s Holberton", "Hello");`
	 - Output: Hello Holberton

- Print integers: _printf("This is an array element: arr[%d]:%c", 32, arr[32]);`
	- Output: This is an array element arr[32]:A

Many other specifiers and flags were added and by combinig those the _printf() function generate a different ouput. The following list are the specifiers and flags allowed.

------------

###### Specifiers

Specifier                |Output                        |Examples |
|----------------|-------------------------------|-----------------------------|
| `c` | Character | y |
| `d` or `i` | Signed integer | 1024, -1024 |
| `s` | String of characters | Hello Holberton |


------------

|Name                |Information                        |Relevant Files                         |
|----------------|-------------------------------|-----------------------------|
|`manprintf.1|Man page of the _printf() function.| `None` |
|`main.h`	| Header file with the data type struct, standard libraries and custom prototypes.| `*.c compilation` |
|`_printf.c`|Main printf function file. Calls other functions.|`printf_(name of var).c file` |
|`printf_int.c` | Contains decimal and integer functions. | `None` | 
`printf_char.c` | Custom function for char data type. | `None`
|`printf_string.c` | Function that calls string type variable. | `None` |
`_putchar.c` | Custom putchar function. | `None` |


------------


