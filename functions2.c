#include "monty.h"
/**
 * pop - this is the function pop
 * @stack: this is the stack
 * @line_number: the number of the line
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;

	if (node == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		*stack = node->next;
		free(node);
	}
}
/**
 * swap - this is the function that swaps between two stacks
 * @stack: the stack
 * @line_number: the number of the line
 */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;
	int temp;

	if (node->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		stack_t *swap = node;

		node = node->next;
		temp = swap->n;
		swap->n = node->n;
		node->n = temp;
	}
}
/**
 * add - function that adds the stacks
 * @stack: the stacks to be added
 * @line_number: the number of the lin
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *staackk = *stack;
	int sum = 0;

	if (!staackk || !staackk->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	sum = staackk->n + staackk->next->n;
	staackk->next->n = sum;
	pop(stack, line_number);
}
/**
 * nop - this is the function nope
 * @stack: the stack to be used
 * @line_number: the number of the line
 */
void nop(__attribute__((unused)) stack_t **stack,
	__attribute__((unused)) unsigned int line_number)
{
}
/**
 * _isdigit - this is a function to show whether a string is a digit
 * Return: void
 */
int _isdigit(void)
{
	int i = 0;
	size_t length = strlen(value);

	if (value == NULL)
		return (0);

	if (length == 0)
		return (0);

	if (value[0] == '-')
		i++;

	for (; i < length; i++)
	{
		if (value[i] < '0' || value[i] > '9')
			return (0);
	}

	return (1);
}
