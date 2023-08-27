#include "monty.h"

/**
 * free_stack - Frees the stack
 * Return: void
 */
void free_stack(void)
{
	stack_t *temp;

	/* Check if stack is empty */
	if (*(global.head) == NULL)
		return;

	/* Free stack */
	while (*(global.head) != NULL)
	{
		temp = (*(global.head))->next;
		free(*(global.head));
		*(global.head) = temp;
	}
}
