#include "monty.h"
/* Standard header files used included in monty.h */

/**
 * pop - Removes the top element of the stack
 * @stack: Address of stack
 * @line_number: Line number of bytecode instruction
 * Return: void
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = NULL;

	if (stack == NULL)
		return;
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	for (ptr = *stack; ptr != NULL; ptr = ptr->next)
	{
		if (ptr->next == NULL)
		{
			if (ptr->prev != NULL)
				(ptr->prev)->next = ptr->next; /* ptr->next is NULL */
			else
				*stack = ptr->next;
			free(ptr);
			return;
		}
	}
}
