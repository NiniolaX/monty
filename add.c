#include "monty.h"
/* Standard header files used included in monty.h */

size_t stack_size(stack_t **stack);
/**
 * add - Adds the top two elements of the stack
 * @stack: Address of stack
 * @line_number: Line number of bytecode instruction
 * Return: void
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr, *TOS, *TOS1;
	int sum;

	/* Check that stack contains more than two elements */
	if (stack_size(stack) < 2)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* Perform addition */
	for (ptr = *stack; ptr != NULL; ptr = ptr->next)
	{
		if (ptr->next == NULL)
		{
			TOS = ptr;
			TOS1 = ptr->prev;
			sum = TOS1->n + TOS->n;
			free(TOS);
			TOS1->n = sum;
			TOS1->next = NULL;
			return;
		}
	}
}
