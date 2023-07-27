#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h> /* Include the va_list type for variable arguments */

/**
 * struct print_struct - ...
 * @indi: ...
 * @handler: ...
 */
typedef struct print_struct
{
char *indi;
int (*handler)(va_list agrs);
} print;

/* Function prototypes for _printf and additional functions */
int _printf(const char *format, ...);
int print_char(va_list args);
int print_string(va_list args);
int print_mod(va_list args);
int print_int(va_list args);
int _putchar(char c);
#endif

