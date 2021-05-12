#include "monty.h"

var_t svar;

void initialize_stack(void);
char *handle_comment(char *str_input);

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
	char *buff, *opcode;
	size_t buff_size = 0;

	if (argc != 2)
	{
		write(2, "USAGE: monty file\n", 18);
		exit(EXIT_FAILURE);
	}
	fd = fopen(argv[1], "r");
	check_access_rights(argv[1]);
	if (!fd)
	{
		dprintf(2, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	initialize_stack();
	/*in case we can't use the getline line_size = read_line(fd, &buff);*/
	line_len = getline(&buff, &buff_size, fd);
	svar.sbuff = buff;
	while (line_len >= 0)
	{
		svar.nodes_number++;
		buff = handle_comment(buff);
		/* line = strtok(buff, "#"); */
		opcode = strtok(buff, " \n\t");
		/*svar.opcode = opcode;*/
		if (opcode)
		{
			svar.after_opcode = strtok(NULL, " \n\t ");
			pick_function(opcode);
		}
		/*we need to check if inside of the line,*/
		/*there are an opcode and return it*/
		line_len = getline(&buff, &buff_size, fd);
		svar.after_opcode = NULL;
	}
	free(svar.buff);
	frees_stack();
	fclose(fd);
	return (0);
}

void initialize_stack(void)
{
	/* svar.type : 0 is stack ;  1 is queue */
	svar.type = 0;
	svar.head = NULL;
	svar.sbuff = NULL;
	svar.opcode = NULL;
	svar.after_opcode = NULL;
	svar.nodes_number = 0;
}

/**
 * handle_comment - deletes a comment from the buffer
 * @str_input: User's input
 *
 * Return: pointer to string
 */
char *handle_comment(char *str_input)
{
	char *without_comments = str_input;

	if (*str_input == '#')
	{
		*str_input = '\n';
		*(str_input + 1) = '\0';
	}
	while (str_input && *str_input)
	{
		if (*str_input == '#' && *(str_input - 1) == ' ')
		{
			*(str_input - 1) = '\n';
			*str_input = '\0';
			break;
		}
		str_input++;
	}
	return (without_comments);
}
