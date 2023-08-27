#include "monty.h"
/* Standard header files used included in monty.h */

/**
 * pchar - Prints the char at the top of the stack
 * @stack: Address of stack
 * @line_number: Line number of bytecode instruction
 * Return: void
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr;
	int TOS;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* Perform pchar operation */
	for (ptr = *stack; ptr != NULL; ptr = ptr->next)
	{
		if (ptr->next == NULL)
		{
			TOS = ptr->n;
			if (TOS >= 0 && TOS <= 127)
			{
				printf("%c\n", (char)TOS);
				return;
			}
			else
			{
				fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
				exit(EXIT_FAILURE);
			}
		}
	}
}
