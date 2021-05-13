#include "monty.h"
#include <stdio.h>

var_t svar;

/**
 * main - entry point of the program
 *
 * @argc: argc
 * @argv: arguments
 * Return: 0 or stderr
 */
int main(int argc, char **argv)
{
	size_t buff_size = 0;

	if (argc != 2)
	{
		write(2, "USAGE: monty file\n", 18);
		exit(EXIT_FAILURE);
	}
	initialize_stack();
	svar.sfd = fopen(argv[1], "r");
	check_access_rights(argv[1]);
	if (!svar.sfd)
	{
		dprintf(2, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&(svar.sbuff), &buff_size, svar.sfd) >= 0)
	{
		svar.nodes_number++;
		/* buff = handle_comment(buff); */
		/* line = strtok(buff, "#"); */
		svar.opcode = strtok(svar.sbuff, " \n\t");
		if (svar.opcode)
		{
			svar.after_opcode = strtok(NULL, " \n\t");
			pick_function(svar.opcode);
		}
		svar.opcode = NULL, svar.after_opcode = NULL;
	}
	finalize_stack();
	return (0);
}
