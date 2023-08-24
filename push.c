#include "monty.h"
#include <stdio.h>
/**
 * push - Pushes an object onto the stack
 * @stack: Address of stack
 * @line_number: Line number of bytecode instruction
 * Return: void
 */
void push(stack_t **stack, unsigned int line_number)
{
	printf("L%u Push in push()\n", line_number);
}
