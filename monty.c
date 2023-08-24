#include <stdlib.h>
#include <stdio.h>
#include "monty.h"
#include <string.h>

/**
 * read_file - Tokenies ByteCode instruction line
 * @line: ByteCode instruction line
 * Return: Array of instruction strings on success, NULL on fail
 */
char **tokenize_line(char *line)
{
	char *delim = " ";
	char *token;
	char **cmdarray;
	unsigned int i;

	cmdarray = malloc(sizeof(char *) * 3);
	if (cmdarray == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	/* Extract bytecode instruction from line */
	token = strtok(line, delim);
	for (i = 0; token != NULL && i < 2; i++)
	{
		cmdarray[i] = strdup(token);
		if (cmdarray[i] == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}
		token = strtok(NULL, delim);
	}
	cmdarray[i++] = NULL;

	return (cmdarray);
}

/**
 * main - Entry point of monty program
 * @argc: Number of arguments to program
 * @argv: Array of argument strings
 * Return: 0 on success, 1 on fail
 */
int main(int argc, char **argv)
{
	stack_t *stack;
	FILE *file;
	char *line;
	size_t linesize = 0;
	unsigned int linenumber = 1;
	char **cmd = NULL;

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
	/* Define stack */
	stack = malloc(sizeof(stack_t));
	if (stack == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	/* Initiate Monty program */
	while (getline(&line, &linesize, file) != -1)
	{
		cmd = tokenize_line(line);
		/* Perform operation */
		if (strcmp(cmd[0], "push") == 0)
		{
			printf("%s\n", cmd[0]);
			/* push(&stack, linenumber); */
		}
		else if (strcmp(cmd[0], "pall") == 0)
		{
			printf("%s\n", cmd[0]);
			/* pall(&stack, linenumber); */
		}
		else
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", linenumber, cmd[0]);
			exit(EXIT_FAILURE);
		}
		free_cmd(cmd);
		linenumber++;
	}

	free(line);
	fclose(file);

	return (0);
}
