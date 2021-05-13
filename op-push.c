#include "monty.h"

/**
 * verify_number - verify if it is a number or not
 *
 * @number: number
 * Return: Always EXIT_SUCCESS.
 */
int verify_number(char *number)
{
	if (!number)
		return (0);
	if (*number == '-')
		number++;

	while (*number)
	{
		if (!isdigit(*number))
			return (0);
		number++;
	}
	return (1);
}

/**
 * push - Adds a new node at the beginning of the stack or queue
 * @stack: head of stack or queue
 * @line_number: The head of the stack
 *
 * Return: Nothing
 */
void push(stack_t **stack, unsigned int line_number)
{
	int param;

	if (!verify_number(svar.after_opcode))
	{
		dprintf(2, "L%u: usage: push integer\n", line_number);
		finalize_stack();
		exit(EXIT_FAILURE);
	}

	/* maybe in the future, we will need an strtok */
	if (svar.after_opcode[0] == '-')
		param = -1 * atoi(svar.after_opcode);
	else
		param = atoi(svar.after_opcode);

	/* if is a stack or else: is a queue*/
	if (svar.type == 0)
		add_dnodeint(stack, param);
	else
		add_dnodeint_end(stack, param);

	/**
	* if (*stack)
	*{
	*	new_node->next = *stack;
	*	new_node->prev = (*stack)->prev;
	*	(*stack)->prev = new_node;
	*	*stack = new_node;
	*	return;
	*}
	* new_node->next = *stack;
	* new_node->prev = NULL;
	* stack = new_node;
	*/
}

/**
* void push_queue(stack_t **stack, unsigned int param)
* {
*	stack_t *current = NULL, *new_node = NULL;
*
*	new_node = malloc(sizeof(stack_t));
*	if (new_node == NULL)
*		handle_error(ERR_BAD_MALL, NULL, 0, NULL);
*
*	new_node->n = param;
*	if (*stack)
*	{
*		current = *stack;
*		while (current->next != NULL)
*			current = current->next;
*
*		new_node->next = NULL;
*		new_node->prev = current;
*		current->next = new_node;
*		return;
*	}
*
*	new_node->next = *stack;
*	new_node->prev = NULL;
*	*stack = new_node;
*}
*/
