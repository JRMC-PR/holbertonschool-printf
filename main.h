#ifndef MAIN_H
#define MAIN_H
typedef struct print_struct{
  char *indi;
  void (*handler)(va_list agrs);
} print;
int _printf(const char *format, ...);
