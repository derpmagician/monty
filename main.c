#include "monty.h"

int main(int argc, char **argv)
{
    int lines_counter = 0;
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

    /*in case we can't use the getline line_size = read_line(fd, &buff);*/
	line_len = getline(&buff, &buff_size, fd);
    while (line_len >= 0)
    {
        lines_counter++;
        line = strtok(buff, "\n");
        /* printf("line = %s\n", line); */
        line = strtok(buff, "#");
        opcode = strtok(buff, " ");
        number = strtok(NULL, "\n");
        /* printf("opcode = %s\n", opcode); */
        /* printf("number = %s\n\n", number); */
        pick_function(opcode, _atoi(number));

        /* we need to check if inside of the line, there are an opcode and return it */
        line_len = getline(&buff, &buff_size, fd);
        line = NULL;
    }
    free(line);
    free(buff);
    return (0);
}
