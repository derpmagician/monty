#include "monty.h"

/**
 * initialize_stack - initialize the stack with a global variable
 * svar.type : 0 is stack ;  1 is queue
 * Return: void
 */
void initialize_stack(void)
{
	svar.type = 0;
	svar.head = NULL;
	svar.sbuff = NULL;
	svar.opcode = NULL;
	svar.after_opcode = NULL;
	svar.current_line = 0;
}

/**
 * finalize_stack - free memmory of the stack
 *
 * Return: void
 */
void finalize_stack(void)
{
	free(svar.sbuff);
	frees_stack();
	fclose(svar.sfd);
}
