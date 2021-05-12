#include "monty.h"

/**
 * swap - Swaps the top two elements of the stack
 * @stack: The head of the stack
 * @line_number: The line on which the error occurred
 *
 * Return: Nothing
 */
void swap(stack_t **stack, unsigned int line_number)
{
	unsigned int length = 0; /* temp = 0; */
	stack_t *tmp1, *tmp2;

	/* length = count_stack(*stack); */
	length = svar.nodes_number;

	if (length < 2)
		handle_error(ERR_SWAP_USG, NULL, line_number, NULL);

	/* the change in monty is always since the memory, not values
	if (*stack)
	{
		temp = (*stack)->n;
		(*stack)->n = (*stack)->next->n;
		(*stack)->next->n = temp;
	}
	*/
	tmp1 = tmp2 = *stack;
	tmp2 = tmp2->next;
	/* first, will change the tmp1 to second position */
	tmp1->next = tmp2->next;
	(tmp2->next)->prev = tmp1;
	tmp1->prev = tmp2;
	/* first node and connection with second */
	*stack = tmp2;
	tmp2->next = tmp1;
	tmp2->prev = NULL;
}
