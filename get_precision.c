#include "main.h"

/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: Pointer to the current index in the format string
 * @list: List of arguments
 *
 * Return: Precision value
 */
int get_precision(const char *format, int *i, va_list list)
{
	int curr_i = *i + 1;
	int precision = -1;

	/* Check if the next character is a period (.) indicating precision */
	if (format[curr_i] != '.')
		return (precision);

	precision = 0;

	/* Loop through the format string to find the precision value */
	for (curr_i += 1; format[curr_i] != '\0'; curr_i++)
	{
		if (is_digit(format[curr_i]))
		{
			/* Convert the digit characters to an integer precision value */
			precision *= 10;
			precision += format[curr_i] - '0';
		}
		else if (format[curr_i] == '*')
		{
			/* If the precision is specified using '*', get it from the arguments */
			curr_i++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	/* Update the index to the current position in the format string */
	*i = curr_i - 1;

	return (precision);
}