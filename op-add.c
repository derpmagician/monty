#include "monty.h"

/**
 * add - adds the top two elements of the stack
 * starting from the top of the stack.
 * @stack: The head of the stack
 * @line_number: The line on which the error occurred
 *
 * Return: Nothing
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	unsigned int a = 0, b = 0, length = 0;
	(void) line_number;

	length = count_stack(*stack);

	if (length < 2)
		handle_error(ERR_ADD_USG);

	a = temp->n;
	b = temp->next->n;
	temp->next->n = a + b;
	*stack = temp->next;
	free(temp);
}
