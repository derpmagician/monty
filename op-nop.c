#include "monty.h"

/**
 * nop - nothing to do
 * @stack: The head of the stack
 * @line_number: The line on which the error occurred
 *
 * Return: Nothing
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}

/**
 * pstr - Prints the string starting at the top of the stack.
 * @stack: The head of the stack
 * @line_number: The line on which the error occurred
 *
 * Return: Nothing
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *curr = *stack;
	(void) line_number;

	while (curr != NULL)
	{
		if (curr->n == 0 || curr->n < 0 || curr->n > 127)
			break;

		printf("%c", curr->n);
		curr = curr->next;
	}

	printf("\n");
}
