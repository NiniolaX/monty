#include "monty.h"

/**
 * free_stack - Frees the stack
 * Return: void
 */
void free_stack(void)
{
	stack_t *temp = NULL;

	/* Check if stack is empty */
	if (*(global.head) == NULL) /* global.head is address of stack's head node */
		return;

	/* Free stack */
	while (*(global.head) != NULL)
	{
		temp = (*(global.head))->next;
		free(*(global.head));
		*(global.head) = temp;
	}
	*(global.head) = NULL;
}
