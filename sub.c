#include "monty.h"
/* Standard header files used included in monty.h */

size_t stack_size(stack_t **stack);
/**
 * sub - Subtracts the top element of the stack from the second top
 *	element of the stack
 * @stack: Address of stack
 * @line_number: Line number of bytecode instruction
 * Return: void
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr, *TOS, *TOS1;
	int diff;

	/* Check that stack contains more than two elements */
	if (stack_size(stack) < 2)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* Perform subtraction */
	for (ptr = *stack; ptr != NULL; ptr = ptr->next)
	{
		if (ptr->next == NULL)
		{
			TOS = ptr;
			TOS1 = ptr->prev;
			diff = TOS1->n - TOS->n;
			free(TOS);
			TOS1->n = diff;
			TOS1->next = NULL;
			return;
		}
	}
}
