#include <stdarg.h>
#include "main.h"


/**
 * _printf- prints a formatted string
 * @fmt: string to print
 *
 * Description- outputs a formatted string and
 * returns the number of characters printed
 *
 * Return: integer value
 */
int _printf(char *fmt, ...)
{
	/*
	* todo: If the %s is not at index zero
	* use a flag that will skip it over but save the index of the
	* foreseen position so that when that position is reached
	* alter the strchr function to stop and return from
	* that position.
	* the check the returned string position from strchr and
	* compare with foreseen positon
	* if the two match process the format specifier then and then
	*/
	/* initialize stdarg generator macro function */
	va_list ap;

	/*start va_arg Value holders */
	int __attribute__((unused)) i;
	unsigned int __attribute__((unused)) ui;
	double __attribute__((unused)) d;
	float __attribute__((unused)) f;
	char __attribute__((unused)) c;
	char __attribute__((unused)) *str;
	char __attribute__((unused)) *datatype;
	char __attribute__((unused)) *pre_fstring;
	char __attribute__((unused)) *post_fstring;
	int __attribute__((unused)) end_replace_index;
	short int flipswitch_percentagesign;
	int __attribute__((unused)) process_string;
	int stringlen;

	/*End of va_arg Value holders */

	int curr_str_index = 0;
	int pos_percent_sign = 0;

	int percent_sign_track_index = 0;
	int process_string_track_index = 0;
	int character_counter = 0;



	/* Initialize scan flags */
	flipswitch_percentagesign = 1;


	/* check and ensure input string is not NULL*/
	if (!fmt)
	{
		exit(0);
	}

	/* initialize va_arg with va_start */
	va_start(ap, fmt);

	/* Below section should be in a While loop */

	stringlen = _strlen_recursion(fmt);

	/* initialize datatype pointer to NULL*/
	datatype = NULL;
	pre_fstring = NULL;
	post_fstring = NULL;

	while (stringlen)
	/* iterate through the string until you hit the null String*/
	{
		if (flipswitch_percentagesign)
		{
			scan_symbol_strchr(fmt, &percent_sign_track_index, '%', &pos_percent_sign);
		}
		/* switch of scanning for percentagesign if percent_sign_track_index is -1*/
		pos_percent_sign < 0 ? switch_off(&flipswitch_percentagesign) : switch_on(&flipswitch_percentagesign);

		/* Check which occurred first whether a back slash or a percentage symbol */
		/*Handle case where percentage sign appears first*/
		if (pos_percent_sign >= 0)
		{
			if (pos_percent_sign > curr_str_index)
			{
				process_string = _strchr(fmt, &process_string_track_index, '%', &curr_str_index, &character_counter);
				if (process_string < 0)
				{
					stringlen = 0;
					continue;

				}
			}
			/**
			 * call formatter identifier function
			 * this function will
			 * 1. scan string from format specifiers i.e %d, %i, %f, %s
			 * 2. return the expected datatype so that we can expand va_arg(ap, datatype);
			 * 3. if no match return false and print as is and increment pointer index
			 * 4. return datatype as NULL
			 */
			datatype = _identify_datatype(fmt, percent_sign_track_index, datatype, &end_replace_index, pre_fstring, post_fstring);
			if (datatype != NULL)
			{
				/*integer*/
				if (_strcmp(datatype, "integer") == 0)
				{
					i = va_arg(ap, int);
					_print_number(i, &character_counter);
					pos_percent_sign += 2;
					process_string_track_index = pos_percent_sign;
				}
				/*float*/
				else if (_strcmp(datatype, "float") == 0)
				{
					f = (float) va_arg(ap, double);
					_print_floats(f, &character_counter);
					pos_percent_sign += 2;
					process_string_track_index = pos_percent_sign;
				}
				/*character*/
				else if (_strcmp(datatype, "character") == 0)
				{
					c = (char) va_arg(ap, int);
					_putchar(c);
					character_counter += 1;
					pos_percent_sign += 2;
					process_string_track_index = pos_percent_sign;
				}
				/*string*/
				else if (_strcmp(datatype, "string") == 0)
				{
					/*
					* todo: Modify strchr so that you can pass in
					* the index of the pos_sign_index
					* Strchr will then compare to check if
					*
					*/
					str = va_arg(ap, char *);
					_puts_recursion(str, &character_counter);
					pos_percent_sign += 2;
					process_string_track_index = pos_percent_sign;
				}
				/*double*/
				else if (_strcmp(datatype, "double") == 0)
				{
					d = va_arg(ap, double);
					_print_floats(f, &character_counter);
					pos_percent_sign += 2;
					process_string_track_index = pos_percent_sign;
				}
				/*unsigned integer*/
				if (_strcmp(datatype, "unsigned") == 0)
				{
					ui = va_arg(ap, unsigned int);
					_print_number(ui, &character_counter);
					pos_percent_sign += 2;
					process_string_track_index = pos_percent_sign;
				}
		}
		else
		/* No valid datatype found just print as is*/
		{
			_puts_recursion("%", &character_counter);
			if ('%' == fmt[pos_percent_sign + 1])
			{
				/* Skip a %% and only print a single 1*/
				pos_percent_sign += 2;
				process_string_track_index = pos_percent_sign;

			}
			else
			{
				_putchar(fmt[pos_percent_sign + 1]);
				character_counter++;
				pos_percent_sign += 2;
				process_string_track_index = pos_percent_sign;
			}
		}


		/**
		 * if success in getting and expanding the datatype
		 * call the formatter class that will
		 * 1. take in the current_index of %
		 * 2. the specific variable after expansion of va_arg(ap, datatype)
		 * 3. It will then return a formatted string that will be output here
		 * or the function can output it itself
		 */

	}

	if (percent_sign_track_index < 0)
	{
		/* no backslash or % signs found just process the string as is*/
		process_string = _strchr(fmt, &process_string_track_index, '%', &curr_str_index, &character_counter);
		if (process_string < 0)
		{
			stringlen = 0;

		}

	}

	}

	va_end(ap);
	return (character_counter);
}
/**
 * switch_on- sets a value to 1
 * @scan_flag: pointer to a flag
 *
 * Description- sets the value of a variable to 1
 *
 * Return: void
 */
void switch_on(short int *scan_flag)
{
	*scan_flag = 1;
}
/**
 * switch_off- sets a value to 0
 * @scan_flag: pointer to a flag
 *
 * Description- sets the value of a variable to 0
 *
 * Return: void
 */
void switch_off(short int *scan_flag)
{
	*scan_flag = 0;
}
