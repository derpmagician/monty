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
	new_node->next = *head;
		/* set the prev of last first node to the new_node */
		if (*head)
			(*head)->prev = new_node;
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

/**
 * delete_dnodeint_at_index - delete node at the index of DLL
 *
 * @head: double pointer to first node of DLL
 * @index: index where the node will be free
 * Return: if EXIT_SUCCESS:1 ; other -1
 */
int delete_dnodeint_at_index(stack_t **head, unsigned int index)
{
	unsigned int counter = 0;
	stack_t *head_tmp, *prev_node;

	if (!head || !(*head))
		return (-1);

	/*case1: first node*/
	if (index == 0)
	{
		prev_node = *head;
		*head = (*head)->next;
		free(prev_node);
		if (*head)
			(*head)->prev = NULL;
		return (1);
	}
	/*case2: middle*/
	head_tmp = *head;

	while (head_tmp)
	{
		if (counter == index)
		{
			/* if it is the last, the next is to NULL*/
			prev_node->next = (head_tmp->next);
			if (head_tmp->next)
				(head_tmp->next)->prev = prev_node;
			free(head_tmp);
			return (1);
		}
		prev_node = head_tmp;
		head_tmp = head_tmp->next;
		counter++;
	}
	/* if index >= counter because the while ends, the return is -1 */
	return (-1);
}
