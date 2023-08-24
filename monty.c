#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "monty.h"

void cleanup(void);
void tokenize_line(char *line);
global_t global = {
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
	FILE *file;
	char line[200], linecp[200];
	unsigned int linenumber = 1, i, status;

	/* Define opcode functions */
	instruction_t instruction[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL},
	};
	atexit(cleanup);

	/* Check number of arguments to program */
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	/* Open file */
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	/* Initiate Monty program */
	while (fgets(line, sizeof(line), file) != NULL)
	{
		strcpy(linecp, line);
		tokenize_line(linecp);
		status = 0;
		/* Perform operation */
		for (i = 0; instruction[i].opcode != NULL; i++)
		{
			if (strcmp((global.cmd[0]), instruction[i].opcode) == 0)
			{
				instruction[i].f(&stack, linenumber);
				/* printf("%s\n", instruction[i].opcode); */
				status = 1;
				break;
			}
		}
		if (status != 1)
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", linenumber, (global.cmd)[0]);
			exit(EXIT_FAILURE);
		}
		linenumber++;
		free_cmd();
	}
	fclose(file);

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
		(global.cmd)[i] = _strdup(token);
		if ((global.cmd)[i] == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}
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
}
