#include "monty.h"

/**
 * check_args_num - Check the arguments passed on to the interpreter
 * @argn: Number of args
 * Return: Nothing
 */
void check_args_num(int argn)
{
	if (argn != MIN_ARGS)
		handle_error(ERR_ARG_USG, NULL, 0, NULL);
}

/**
 * check_access_rights - CChecks if the user has permissions to read the file
 * @filename: The pathname of the file
 * Return: Nothing
 */
void check_access_rights(char *filename)
{
	if (access(filename, R_OK) == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
}
