#include "monty.h"

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

	while (curr && stack)
	{
		if (curr->n <= 32 || curr->n > 127)
			break;

		printf("%c", curr->n);
		curr = curr->next;
	}
	printf("\n");
}
