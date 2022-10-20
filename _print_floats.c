#include "main.h"
#include <stdlib.h>

/**
 * _print_floats- prints a float as a string
 * @val: float value to print
 *
 * Description- outputs a float as a string
 * to function _puts_recursion(s)
 *
 * Return: void
 */
void _print_floats(float val)
{
	char buffer[11];

	gcvt(val, 6, buffer);
	buffer[10] = 0;
	write(1, buffer, _strlen_recursion(buffer) + 1);
}
