#include "monty.h"

/**
 * pchar - Prints the char at the top of the stack,
 * followed by a new line
 * @stack: The head of the stack
 * @line_number: The line on which the error occurred
 *
 * Return: Nothing
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	stack_t *tmp = NULL;

	if (*stack == NULL)
		handle_error(ERR_PCH_EMP);

	tmp = *stack;
	if (tmp->n >= 0 && tmp->n <= 127)
		printf("%c\n", tmp->n);
	else
		handle_error(ERR_PCH_USG);
}
