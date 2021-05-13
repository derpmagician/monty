#include "monty.h"

/**
 * pop - Removes the top element of the stack
 * @stack: The head of the stack
 * @line_number: The line on which the error occurred
 *
 * Return: Nothing
 */
void pop(stack_t **stack, unsigned int line_number)
{
	/* stack_t *current = *stack, *temp = NULL; */

	if (*stack == NULL)
	{
		finalize_stack();
		handle_error(ERR_POP_USG, NULL, line_number, NULL);
	}

	delete_dnodeint_at_index(stack, 0);
/*
	temp = current;
	if (current->next)
	{
		current = current->next;
		current->prev = temp->prev;
		*stack = current;
	}
	else
		*stack = NULL;

	free(temp);
	svar.nodes_number = svar.nodes_number - 1; */
}
