#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list 
 * @n: integer
 * @prev: previous
 * @next: next
 * Description: doubly linked list
 */

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function
 * Description: opcode and its function
 */

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct buffer - structure
 * @fd: file desctiption
 * @line: line to getline
 * Description: To handle the file and getline
 */
typedef struct buffer
{
	FILE *fd;
	char *line;
} buffer_t;

extern buffer_t buffer;
extern int value;

void execute_cmd(char *argv);

int get_opc(stack_t **stack, char *arg, char *item, int count);

void _push(stack_t **stack, unsigned int line_number);
void _pall(stack_t **stack, unsigned int line_number);
void _pint(stack_t **stack, unsigned int line_number);
void _swap(stack_t **stack, unsigned int line_number);
void _pop(stack_t **stack, unsigned int line_number);
void _add(stack_t **stack, unsigned int line_number);
void _nop(stack_t **stack, unsigned int line_number);
void free_dlistint(stack_t *stack);

int _isdigit(char *c);
stack_t *new_Node(int n);

void push_error(FILE *fd, char *line, stack_t *stack, int count);
void ins_error(FILE *fd, char *line, stack_t *stack, char *count, int item);

#endif
