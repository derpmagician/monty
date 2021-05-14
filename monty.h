#ifndef MONTY_H
#define MONTY_H

/* headers */
#include <unistd.h>
/* lib and handle errors */
#include <stdlib.h>
/* fd */
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
/* get line */
#include <stdio.h>
/* strtokn */
#include <string.h>
#include <ctype.h>

#define MIN_ARGS 2
/* Common Errors */
#define ERR_BAD_INST	100 /* "L%d: unknown instruction %s\n", line, opcode) */
#define ERR_BAD_MALL	101 /* "Error: malloc failed\n"); */

/* Usage Errors */
#define ERR_ARG_USG		200
#define ERR_PUSH_USG	201
#define ERR_PINT_USG	202
#define ERR_POP_USG		203
#define ERR_SWAP_USG	204
#define ERR_ADD_USG		205
#define ERR_SUB_USG		206
#define ERR_DIV_USG		207
#define ERR_DIV_ZRO		208
#define ERR_MUL_USG		209
#define ERR_MOD_USG		210
#define ERR_PCH_USG		211
#define ERR_PCH_EMP		212

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct variables_s - structure for data in the actual stack
 * @type: 0 if is a stack LIFO; 1 if is a queue FIFO
 * @head: head of the stack
 * @sbuff: buffer
 * @opcode: opcode
 * @after_opcode: number or whatever
 * @nodes_number: number of nodes
 * @sfd: fd
 *
 * Description: structure to handle easily the exercise and
 * do 1 function for stack, queues, LIFO, FIFO
 */
typedef struct variables_s
{
	int type;
	stack_t *head;
	char *sbuff;
	char *opcode;
	char *after_opcode;
	unsigned int current_line;
	FILE *sfd;
} var_t;

var_t svar;

/* manipulate stack memory */
void initialize_stack(void);
void finalize_stack(void);

void pick_function(char *opcode);
unsigned int count_stack(stack_t *stack);

void frees_stack(void);
void handle_error(int errno);
void handle_cerror(int errno, char *opcode, unsigned int line);
void handle_uerror(int errno, unsigned int line);
void handle_more_uerror(int errno, unsigned int line);
void check_access_rights(char *filename);

void push(stack_t **stack, unsigned int param);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void divide(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);
void queue(stack_t **stack, unsigned int line_number);
void stack(stack_t **stack, unsigned int line_number);

/* auxiliar functions of the library */
char *handle_comment(char *str_input);

/* double linked list functions */
stack_t *add_dnodeint(stack_t **head, const int n);
stack_t *add_dnodeint_end(stack_t **head, const int n);
void free_dlistint(stack_t *head);
int delete_dnodeint_at_index(stack_t **head, unsigned int index);

#endif
