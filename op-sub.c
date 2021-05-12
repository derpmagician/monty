#include "monty.h"

/**
 * sub - subtracks the top element of the stack
 * from the second of the stack.
 * @stack: The head of the stack
 * @line_number: The line on which the error occurred
 *
 * Return: Nothing
 */
void sub(stack_t **stack, unsigned int line_number)
{
    stack_t *tmp = *stack;
    int result = 0, idx = 0;
    
    while(tmp->next)
    {
        tmp = tmp->next;
        idx++;
    }

    if (idx < 2)
        handle_error(ERR_SWAP_USG, NULL, line_number, NULL);

    result = (*stack)->n;
    delete_dnodeint_at_index(stack, 0);
    (*stack)->n = (*stack)->n - result;
    svar.nodes_number = svar.nodes_number - 1;
}
