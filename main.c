#include "monty.h"

/**
 * main - Entry point
 * @argv: argument arrays
 * @argc: the number of arguments
 * Return: 0 if successful
 */

int main(int argc, char *argv[])
{
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	stack_t *stack = NULL;
	char *filename;
	unsigned int line_number = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	filename = argv[1];
	fp = fopen(filename, "r");

	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		return (EXIT_FAILURE);
	}
	while ((read = getline(&line, &len, fp)) != -1)
	{
		line_number++;
		exe(line, &stack, line_number);
	}
	free(line);
	free_stack(stack);
	fclose(fp);

	return (EXIT_SUCCESS);
}
