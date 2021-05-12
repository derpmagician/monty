#include "monty.h"

/**
  * frees_stack - Releases all elements in the stack
  *
  * Return: Nothing
  */
void frees_stack(void)
{
	if (svar.head)
		free_dlistint(svar.head);
}
