#include "monty.h"

/**
 * rotl - the top element of stack becomes the last
 * @stack: The head of the stack
 * @line_number: The line where the operator is
 *
 * Return: Nothing
 */
void rotl(stack_t **stack, unsigned int line_number)
{
    stack_t *last_node, *tmp = *stack, *second_node;

    while (last_node->next)
        last_node = last_node->next;

    /* set the new top node of stack */
    second_node = (*stack)->next;
    second_node->prev = (*stack)->prev;
    *stack = second_node;
    /* becoming the first node (tmp), the last*/
    tmp->next = last_node->next;
    last_node->next = tmp;
    tmp->prev = last_node;
}
