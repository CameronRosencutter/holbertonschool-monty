#include "monty.h"

/**
 * free_dlistint - frees a double linked list
 * @head: point to head
 * Return: void
 */

void free_dlistint(stack_t *head)
{
	stack_t *temp;

	while (head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
	free(head);
}
