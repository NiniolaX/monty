#include "monty.h"
/* Standard header files used included in monty.h */

/**
 * nop - Doesn't do anything
 * @stack: Address of stack
 * @line_number: Line number of bytecode instruction
 * Return: void
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	/* This function does nothing */
}
