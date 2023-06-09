#include "monty.h"

buffer_t buffer = {NULL, NULL};

/**
 * main - entry
 * @argc: number
 * @argv: pointers
 * Return: 0
 */

int main(int argc, char *argv[])
{
	if (argc == 2)
		execute_cmd(argv[1]);
	else
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	return (0);
}

/**
 * execute_cmd - executes
 * @argv: user input
 * Return: void
 */

void execute_cmd(char *argv)
{
	int linecount = 0, result = 0;
	size_t bufsize = 0;
	char *arguments = NULL, *data = NULL;
	stack_t *stack = NULL;

	buffer.fd = fopen(argv, "r");
	if (buffer.fd)
	{
		while (getline(&buffer.line, &bufsize, buffer.fd) != -1)
		{
			linecount++;
			arguments = strtok(buffer.line, " \n\t\r");
			if (arguments == NULL)
			{
				free(arguments);
				continue;
			}
			data = strtok(NULL, " \n\t\r");
			result = get_opc(&stack, arguments, data, linecount);
			if (result == 1)
				push_error(buffer.fd, buffer.line, stack, linecount);
			else if (result == 2)
				ins_error(buffer.fd, buffer.line, stack, arguments, linecount);
		}
		free(buffer.line);
		free_dlistint(stack);
		fclose(buffer.fd);
	}
	else
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv);
		exit(EXIT_FAILURE);
	}
}

/**
 * get_opc - function
 * @stack: is a stack
 * @arg: command entered
 * @data: value enterd by user
 * @linecount: line
 * Return: nothing
 */

int get_opc(stack_t **stack, char *arg, char *data, int linecount)
{
	int i = 0;

	instruction_t op[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{NULL, NULL}
	};

	while (op[i].opcode)
	{
		if (!strcmp(arg, op[i].opcode))
		{
			if (!strcmp(arg, "push"))
			{
				if (_isdigit(data) == 1)
					value = atoi(data);
				else
					return (1);
			}
			op[i].f(stack, (unsigned int)linecount);
			break;
		}
		i++;
	}
	if (!op[i].opcode)
		return (2);

	return (0);
}
