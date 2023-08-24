#include "monty.h"
#include <stdlib.h>

/**
 * free_cmd - Frees command array
 * Return: Void
 */
void free_cmd(char **cmd)
{
	int i = 0;

	while (cmd[i])
	{
		free(cmd[i]);
		cmd[i] = NULL;
		i++;
	}
	free(cmd);
	cmd = NULL;
}
