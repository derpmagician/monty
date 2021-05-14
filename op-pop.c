#include "monty.h"

/**
 * pop - Removes the top element of the stack
 * @stack: The head of the stack
 * @line_number: The line on which the error occurred
 * Return: Nothing
 */
void pop(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		finalize_stack();
		handle_error(ERR_POP_USG);
	}

	delete_dnodeint_at_index(stack, 0);
}
