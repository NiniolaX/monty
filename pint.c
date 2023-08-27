#include "monty.h"
/* Standard header files used included in monty.h */

/**
 * pint - Prints the value at the top of the stack
 * @stack: Address of stack
 * @line_number: Line number of bytecode instruction
 * Return: void
 */
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr;

	/* Check if stack is empty */
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	for (ptr = *stack; ptr != NULL; ptr = ptr->next)
	{
		if (ptr->next == NULL)
		{
			printf("%d\n", ptr->n);
			return;
		}
	}
}
