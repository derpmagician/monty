#include "monty.h"

/**
 * handle_error - Manages the printing of interpreter errors
 * @errno: The error code to manage
 * @opcode: The operation code to manage
 * @line: The line on which the error occurred
 * @buff: The reserved error line buffer
 *
 * Return: Nothing
 */
void handle_error(int errno, char *opcode, unsigned int line, char *buff)
{
	if (errno >= 100 && errno < 200)
		handle_cerror(errno, opcode, line);
	else if (errno >= 200 && errno <= 210)
		handle_uerror(errno, line);
	else if (errno >= 211 && errno <= 220)
		handle_more_uerror(errno, line);
	else
		return;

	frees_stack();

	if (buff)
		free(buff);

	exit(EXIT_FAILURE);
}

/**
 * handle_cerror - Manages common interpreter errors
 * @errno: The error code to manage
 * @opcode: The operation code to manage
 * @line: The line on which the error occurred
 *
 * Return: Nothing
 */
void handle_cerror(int errno, char *opcode, unsigned int line)
{
	switch (errno)
	{
		case ERR_BAD_INST:
			fprintf(stderr, "L%u: unknown instruction %s\n", line, opcode);
			break;
		case ERR_BAD_MALL:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		default:
			break;
	}
}

/**
 * handle_uerror - Manages interpreter usage errors
 * @errno: The error code to manage
 * @line: The line on which the error occurred
 *
 * Return: Nothing
 */
void handle_uerror(int errno, unsigned int line)
{
	switch (errno)
	{
		case ERR_ARG_USG:
			dprintf(2, "USAGE: monty file\n");
			break;
		case ERR_PUSH_USG:
			dprintf(2, "L%u: usage: push integer\n", line);
			break;
		case ERR_PINT_USG:
			dprintf(2, "L%u: can't pint, stack empty\n", line);
			break;
		case ERR_POP_USG:
			dprintf(2, "L%u: can't pop an empty stack\n", line);
			break;
		case ERR_SWAP_USG:
			dprintf(2, "L%u: can't swap, stack too short\n", line);
			break;
		case ERR_ADD_USG:
			dprintf(2, "L%u: can't add, stack too short\n", line);
			break;
		case ERR_SUB_USG:
			dprintf(2, "L%u: can't sub, stack too short\n", line);
			break;
		case ERR_DIV_USG:
			dprintf(2, "L%u: can't div, stack too short\n", line);
			break;
		case ERR_DIV_ZRO:
			dprintf(2, "L%u: division by zero\n", line);
			break;
		case ERR_MUL_USG:
			dprintf(2, "L%u: can't mul, stack too short\n", line);
			break;
		case ERR_MOD_USG:
			dprintf(2, "L%u: can't mod, stack too short\n", line);
			break;
		default:
			break;
	}
}

/**
 * handle_more_uerror - Manages interpreter usage errors
 * @errno: The error code to manage
 * @line: The line on which the error occurred
 *
 * Return: Nothing
 */
void handle_more_uerror(int errno, unsigned int line)
{
	switch (errno)
	{
		case ERR_PCH_USG:
			dprintf(2, "L%u: can't pchar, value out of range\n", line);
			break;
		case ERR_PCH_EMP:
			dprintf(2, "L%u: can't pchar, stack empty\n", line);
			break;
		default:
			break;
	}
}
