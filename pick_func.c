#include "monty.h"

/**
  * pick_function - Select the function that relates to the Monty instruction
  * @s: The instruction to be executed
  *
  * Return: A pointer to the function to be executed or
  * NULL if the function don't exists
  */
/* void (*pick_func(char *s))(stack_t **, unsigned int) */
void pick_function(char *s, int number)
{
	instruction_t insts[] = {
		{ "push", push },
		{ "push_queue", push_queue },
		{ "pall", pall },
		{ "pint", pint },
		{ "pop", pop },
		{ "swap", swap },
		{ "add", add },
		{ "nop", nop },
		{ "sub", sub },
		{ "div", divide },
		{ "mul", mul },
		{ "mod", mod },
		{ "pchar", pchar },
		{ "pstr", pstr },
		{ "rotl", rotl },
		{ "rotr", rotr },
		{ NULL, NULL }
	};
	int i = 0;

	while (insts[i].opcode)
	{
		if (strcmp(s, insts[i].opcode) == 0)
		/* in here is better to return the function or just execute it */
			return (insts[i].f(s, number));
		++i;
	}
}
