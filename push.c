#include "monty.h"
/* Standard header files used included in monty.h */

/**
 * push - Pushes an object onto the stack
 * @stack: Address of stack
 * @line_number: Line number of bytecode instruction
 * Return: void
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = NULL, *new = NULL;
	char *numstr = (global.cmd)[1], *endptr;
	int num;

	/* Build new stack node */
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->prev = new->next = NULL;
		/* Convert integer string to integer */
	if (numstr)
		num = (int)strtol(numstr, &endptr, 10);
	if (numstr == NULL || (num == 0 && strcmp(numstr, "0") != 0)
		|| *endptr != '\0')
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free(new);
		exit(EXIT_FAILURE);
	}
	else
		new->n = num;

	/* Add new node to stack */
	if (*stack == NULL)
	{
		*stack = new;
		return;
	}
	for (ptr = *stack; ptr != NULL; ptr = ptr->next)
	{
		if (ptr->next == NULL)
		{
			new->prev = ptr;
			ptr->next = new;
			return;
		}
	}
}
