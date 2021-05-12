#include "monty.h"

/**
 *_atoi - extract the number to integer
 *@str: string input
 *Return: number int
 */
int _atoi(char *str)
{
	int result = 0;
	int sign = 1;
	int digit;

	if (*str == '-')
	{
		sign = -1;
		++str;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10;
		digit = *str - '0';
		result = result + (digit * sign);
		++str;
	}
	return (result);

}
