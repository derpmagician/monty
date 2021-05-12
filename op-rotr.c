#include "monty.h"

/**
 * rotr - the last element of stack becomes the first
 * @stack: The head of the stack
 * @line_number: The line where the operator is
 *
 * Return: Nothing
 */
void rotr(stack_t **stack, unsigned int line_number)
{
    stack_t *last_node, *tmp = *stack, *new_last;
    (void) line_number;

    while (last_node->next)
        last_node = last_node->next;

    /* set the new last node */
    new_last = last_node->prev;
    new_last->next = last_node->next;
    /* becoming the last node, first */
    last_node->prev = tmp->prev;
    last_node->next = tmp;
    tmp->prev = last_node;
    /* changing the stack header */
    *stack = last_node;
}
