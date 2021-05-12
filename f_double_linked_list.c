#include "monty.h"

/**
 * add_dnodeint - add a node at the initial of the linked list
 *
 * @head: pointer to pointer to the first node of the double linked list
 * @n: value of the new_node
 * Return: Always EXIT_SUCCESS.
 */
stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *new_node;

	if (!head)
		return (NULL);

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
		return (NULL);

	/* initial value of new_node */
	new_node->n = n;
	new_node->prev = NULL;
	if (*head)
	{
		new_node->next = *head;
		/* set the prev of last first node to the new_node */
		if (*head)
			(*head)->prev = new_node;
	}
	/* change the head to the address of new_node */
	*head = new_node;
	return (*head);
}

/**
 * add_dnodeint_end - add a node at the end of the linked list
 *
 * @head: pointer to pointer to the first node of the double linked list
 * @n: value of the new_node
 * Return: Always EXIT_SUCCESS.
 */
stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *new_node, *last_node = *head;

	if (!head)
		return (NULL);

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
		return (NULL);

	/* initialize the new_node */
	new_node->n = n;
	new_node->next = NULL;
	/*we need the address of the last node to set in the new_node->prev */
	/* case1: empty DLL: address of first node is empty*/
	if (!*head)
	{
		new_node->prev = NULL;
		*head = new_node;
		return (new_node);
	}
	/* case2: searching the last address of the DLL */
	while (last_node->next)
		last_node = last_node->next;
	/* set the prev of new_node */
	new_node->prev = last_node;
	/* reset the next of the last_node */
	last_node->next = new_node;
	return (new_node);
}

/**
 * free_dlistint - function that frees a dlistint_t list
 * @head: head of DLL
 *
 * Return: void
 */
void free_dlistint(stack_t *head)
{
	stack_t *head_next;

	while (head)
	{
		head_next = head->next;
		free(head);
		head = head_next;
	}
}
