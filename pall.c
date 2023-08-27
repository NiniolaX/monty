#include "monty.h"
/* Standard header files used included in monty.h */

/**
 * pall - Prints all objects currently on the stack
 * @stack: Address of stack
 * @line_number: Line number of bytecode instruction
 * Return: void
 */
void pall(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *ptr;

	/* Check if stack is empty */
	if (*stack == NULL)
		return;
	ptr = *stack;

	/* Traverse to top of stack */
	while (ptr->next != NULL)
		ptr = ptr->next;

	for (ptr = ptr; ptr != NULL; ptr = ptr->prev)
		printf("%d\n", ptr->n);
}
