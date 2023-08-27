#include "monty.h"
/* Standard header files used included in monty.h */

void cleanup(void);
void tokenize_line(char *line);
global_t global = {
	NULL,
	NULL,
	NULL,
};

/**
 * main - Entry point of monty program
 * @argc: Number of arguments to program
 * @argv: Array of argument strings
 * Return: 0 on success, 1 on fail
 */
int main(int argc, char **argv)
{
	stack_t *stack = NULL;
	char fileline[200];
	unsigned int linenum = 1, i, status;
	/* Define opcode functions */
	instruction_t instruction[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{"pchar", pchar},
		{NULL, NULL},
	};

	atexit(cleanup);
	global.head = &stack;
	/* Check number of arguments to program */
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	/* Open file */
	global.file = fopen(argv[1], "r");
	if (global.file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	/* Initiate Monty program */
	while (fgets(fileline, sizeof(fileline), global.file) != NULL)
	{
		tokenize_line(fileline);
		/* Execute bytecode instruction */
		for (i = 0; instruction[i].opcode != NULL && (global.cmd)[0] != NULL; i++)
		{
			status = 0;
			/* Handle comments */
			if (*(global.cmd)[0] == '#')
			{
				nop(&stack, linenum);
				status = 1;
				continue;
			}
			else if (strcmp((global.cmd[0]), instruction[i].opcode) == 0)
			{
				instruction[i].f(&stack, linenum);
				status = 1;
				break;
			}
		}
		if (status != 1)
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", linenum, (global.cmd)[0]);
			exit(EXIT_FAILURE);
		}
		linenum++;
		free_cmd();
	}
	/* File closed in cleanup() */
	return (0);
}

/**
 * tokenize_line - Tokenizes ByteCode instruction line
 * @line: ByteCode instruction line
 * Return: Void
 */
void tokenize_line(char *line)
{
	char *token = NULL, *delim = " \n";
	unsigned int i;

	global.cmd = malloc(sizeof(char *) * 3);
	if (global.cmd == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	/* Extract bytecode instruction from line */
	token = strtok(line, delim);
	for (i = 0; token != NULL && i < 2; i++)
	{
		(global.cmd)[i] = malloc(strlen(token) + 1);
		if ((global.cmd)[i] == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}
		strcpy((global.cmd)[i], token);
		token = strtok(NULL, delim);
	}
	(global.cmd)[i++] = NULL;
}

/**
 * cleanup - Free all allocated memory before exit from program
 * Return: Void
 */
void cleanup(void)
{
	free_cmd();
	free_stack();

	/* Check if file is open before closing it */
	if (global.file != NULL)
		fclose(global.file);
}
