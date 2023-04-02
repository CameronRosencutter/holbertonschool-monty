#include "monty.h"

/**
 * push_error - handle push error
 * @fd: File description
 * @line: buffer
 * @stack: stack queue
 * @count: line command
 */

void push_error(FILE *fd, char *line, stack_t *stack, int count)
{
	dprintf(STDERR_FILENO, "L%u: usage: push integer\n", count);
	fclose(fd);
	free(line);
	free_dlistint(stack);
	exit(EXIT_FAILURE);
}

/**
 * ins_error - Error
 * @fd: file decriptor
 * @line: is a buffer
 * @stack: is a stack
 * @count: is a line command
 * @item: number
 */

void ins_error(FILE *fd, char *line, stack_t *stack, char *count, int item)
{
	dprintf(STDERR_FILENO, "L%u: unknown instruction %s\n", item, count);
	fclose(fd);
	free(line);
	free_dlistint(stack);
	exit(EXIT_FAILURE);
}
