#include "monty.h"
#include <stdio.h>
/**
 * pall - Prints all objects currently on the stack
 * @stack: Address of stack
 * @line_number: Line number of bytecode instruction
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_number)
{
	printf("L%u Pall in pall()\n", line_number);
}
