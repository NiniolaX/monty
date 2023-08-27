#include "monty.h"
/* Standard header files used included in monty.h */

size_t stack_size(stack_t **stack);
/**
 * swap - Swaps the top two elements of the stack
 * @stack: Address of stack
 * @line_number: Line number of bytecode instruction
 * Return: void
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = NULL, *TOS = NULL, *TOS1 = NULL;

	/* Check that stack contains more than two elements */
	if (stack_size(stack) < 2)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* Perform swap */
	for (ptr = *stack; ptr != NULL; ptr = ptr->next)
	{
		if (ptr->next == NULL)
		{
			TOS = ptr;
			TOS1 = ptr->prev;
			/* Link TOS with node before TOS1 */
			if (TOS1->prev != NULL)
				(TOS1->prev)->next = TOS;
			else
				*stack = TOS;
			TOS->prev = TOS1->prev;
			/* Link TOS1 with TOS */
			TOS->next = TOS1;
			TOS1->prev = TOS;
			TOS1->next = NULL;
			return;
		}
	}
}

/**
 * stack_size - Returns the number of elements on the stack
 * @stack: Address of stack
 * Return: Number of elements on stack
 */
size_t stack_size(stack_t **stack)
{
	size_t n = 0;
	stack_t *ptr = *stack;

	while (ptr != NULL)
	{
		n++;
		ptr = ptr->next;
	}

	return (n);
}
