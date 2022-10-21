#include "main.h"
#include <limits.h>
#include <stdio.h>

/**
 * _print_unsigned_number - Prints an unsigned integer using recursion
 * @n: Integer to print
 * @print_counter: tracks the number of characters being printed
 * Return - void
 */
void _print_unsigned_number(unsigned int n, int *print_counter)
{
	unsigned int temp;

	temp = n;
	if (temp / 10) /* Captures the first digit */
	{
		_print_unsigned_number(temp / 10, print_counter);
		/* Recursively call function to print e.g 1024 - 102 - 10 - 1*/
	}
	_putchar((temp % 10) + '0');
	*print_counter += 1;
	/* grabs the first digit of a number */
}
