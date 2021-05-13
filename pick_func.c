#include "monty.h"

/**
  * pick_function - Select the function that relates to the Monty instruction
  * @opcode: The instruction to be execute
  *
  * Return: A pointer to the function to be executed or
  * NULL if the function don't exists
  */
void pick_function(char *opcode)
{
	instruction_t opcode_structure[] = {
		{ "push", push },
		{ "pall", pall },
		{ "pint", pint },
		{ "pop", pop },
		{ "swap", swap },
		{ "add", add },
		{ "nop", nop },
		{ "sub", sub },
	/*	{ "div", divide }, */
	/*	{ "mul", mul }, */
	/*	{ "mod", mod }, */
	/*	{ "pchar", pchar }, */
	/*	{ "pstr", pstr }, */
	/*	{ "rotl", rotl }, */
	/*	{ "rotr", rotr }, */
		{ "stack", stack },
		{ "queue", queue },
		{ NULL, NULL }
	};
	int i = 0;

	while (opcode_structure[i].opcode && opcode)
	{
		if (strcmp(opcode, opcode_structure[i].opcode) == 0)
		{
		/* in here is better to return the function or just execute it */
			/* printf("opcode tpok = %s\n", opcode); */
			/* printf("number = %d\n", number); */
			opcode_structure[i].f(&(svar.head), svar.nodes_number);
			return;
		}
		++i;
	}
	dprintf(2, "Line %d: Unknow instruction %s\n", svar.nodes_number, opcode);
	exit(EXIT_FAILURE);
}
