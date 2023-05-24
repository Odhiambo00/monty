#include "monty.h"
/**
 *_get - function that gets the opcode
 *@line: the line that gets executed
 *@opcode: this is the opcode
 *@stack: this is the stack
 *@line_number: the number of the line
 */
void _get(char *line, char *opcode, stack_t **stack, unsigned int line_number)
{
	int a = 0;
	instruction_t table[] = {
		{"push", push},
		{"pint", pint},
		{"pall", pall},
		{"add", add},
		{"pop", pop},
		{"swap", swap},
		{"nop", nop},
		{NULL, NULL}
	};

	if (strcmp(opcode, "swap") == 0 && line_number == 1)
	{
		err_dir(opcode, line_number);
		exit(EXIT_FAILURE);
	}

	while (table[a].opcode)
	{
		if (strncmp(opcode, table[a].opcode) == 0)
		{
			table[a].f(stack, line_number);
			return;
		}
		a++;
	}

	err_dir(opcode, line_number);
	free(line);
	free_stack(*stack);
	exit(EXIT_FAILURE);
}
