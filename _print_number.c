#include "main.h"

/**
 * print_number - Prints an integer using recursion
 * @n: Integer to print
 * @print_counter: tracks the number of characters being printed
 * Return - void
 */
void _print_number(int n, int *print_counter)
{
	int temp;

	if (n < 0)
	{
		temp = -n;
		_putchar('-');
		*print_counter += 1;
	}
	else
	{
		temp = n;
	}
	if (temp / 10) /* Captures the first digit */
	{
		_print_number(temp / 10, print_counter);
		/* Recursively call function to print e.g 1024 - 102 - 10 - 1*/
	}
	_putchar((temp % 10) + '0');
	*print_counter += 1;
	/* grabs the first digit of a number */
}
