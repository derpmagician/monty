#include "monty.h"

/**
 * rotr - the last element of stack becomes the first
 * @stack: The head of the stack
 * @line_number: The line where the operator is
 *
 * Return: Nothing
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *last = NULL;
	(void) line_number;

	if (*stack && (*stack)->next)
	{
		last = *stack;

		while (last->next != NULL)
			last = last->next;

		last->prev->next = NULL;
		last->next = *stack;
		*stack = last;
	}
}
