#include "main.h"

/**
 * get_flags - Calculates active flags
 * @format: Formatted string in which to print the arguments
 * @i: Pointer to the current index in the format string
 * Return: Flags
 */
int get_flags(const char *format, int *i)
{
	/* Flags characters: - + 0 # ' ' */
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};

	/* Corresponding flag values: 1 2 4 8 16 */
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	int j, curr_i, flags = 0;

	/* Loop through the format string starting from the next character */
	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		/* Check if the current character is a flag character */
		for (j = 0; FLAGS_CH[j] != '\0'; j++)
		{
			if (format[curr_i] == FLAGS_CH[j])
			{
				/* If found, set the corresponding flag in the flags variable */
				flags |= FLAGS_ARR[j];
				break;
			}
		}

		/* If the current character is not a flag character, break out of the loop */
		if (FLAGS_CH[j] == '\0')
			break;
	}

	/* Update the index to the current position in the format string */
	*i = curr_i - 1;

	return (flags);
}

