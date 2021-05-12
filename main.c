#include "monty.h"

var_t svar;

void initialize_stack(void);

/**
 * main - entry point of the program
 *
 * @argc: argc
 * @argv: arguments
 * Return: Always EXIT_SUCCESS.
 */
int main(int argc, char **argv)
{
	ssize_t line_len;
	FILE *fd;
	char *buff, *line, *opcode, *number;
	size_t buff_size = 0;

	if (argc != 2)
	{
		write(2, "USAGE: monty file\n", 18);
		exit(EXIT_FAILURE);
	}
	/* fopen returns a FILE pointer */
	fd = fopen(argv[1], "r");
	if (!fd)
	{
		/* it is similar than write but in printf , fd = 2 because is an error */
		dprintf(2, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	initialize_stack();
	/*in case we can't use the getline line_size = read_line(fd, &buff);*/
	line_len = getline(&buff, &buff_size, fd);
	while (line_len >= 0)
	{
		svar.nodes_number++;
		/* line = strtok(buff, "\n"); */
		/* printf("line = %s\n", line); */
		line = strtok(buff, "#");
		opcode = strtok(buff, " \n");
		if (opcode)
		{

			number = strtok(NULL, " \n\0");
			if (!number)
			{
				pick_function(opcode, 0);
				return (0);
			}
			/* printf("hereee opcode = %s.\n", opcode); */
			pick_function(opcode, atoi(number));
		}
		/* we need to check if inside of the line, 
		there are an opcode and return it */
		line_len = getline(&buff, &buff_size, fd);
		line = NULL;
		number = NULL;
	}
	free(line);
	free(buff);
	return (0);
}

void initialize_stack(void)
{
	/* svar.type : 0 is stack ;  1 is queue */
	svar.type = 0;
	svar.head = NULL;
	svar.nodes_number = 0;
}
