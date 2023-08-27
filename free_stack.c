#include "monty.h"

/**
 * free_stack - Frees the stack
 * Return: void
 */
void free_stack(void)
{
	stack_t *temp, *head = *(global.head);

	/* Free stack */
	while (head != NULL)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
	head = NULL;
}
