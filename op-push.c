#include "monty.h"

/**
 * verify_number - verify if it is a number or not
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
 * Return: Nothing
 */
void push(stack_t **stack, unsigned int line_number)
{
	int param;
	(void) line_number;

	if (!verify_number(svar.after_opcode))
		handle_error(ERR_PUSH_USG);

	/* maybe in the future, we will need an strtok */
	if (svar.after_opcode[0] == '-')
		param = -1 * atoi(svar.after_opcode);
	else
		param = atoi(svar.after_opcode);

	/* if is a stack or else: is a queue*/
	if (svar.type == 0)
	{
		if (!add_dnodeint(stack, param))
			handle_error(ERR_BAD_MALL);
	}
	else
	{
		if (!add_dnodeint_end(stack, param))
			handle_error(ERR_BAD_MALL);
	}
}
