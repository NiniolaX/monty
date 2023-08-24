#include "monty.h"
#include <stdlib.h>

/**
 * free_cmd - Frees command array
 * Return: Void
 */
void free_cmd(void)
{
	int i = 0;

	if (global.cmd == NULL)
		return;

	while ((global.cmd)[i] != NULL)
	{
		free((global.cmd)[i]);
		(global.cmd)[i] = NULL;
		i++;
	}
	free(global.cmd);
	global.cmd = NULL;
}
