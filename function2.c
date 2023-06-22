#include "monty.h"

/**
 *add_func - Function that adds 2 top elements
 *@head: Reference to the doubly linked list.
 *@lineNumber: The line number being evaluated.
 */
void add_func(stack_t **head, unsigned int lineNumber)
{
	stack_t *temp;

	if (head == NULL)
		head = malloc(sizeof(stack_t));
	temp = *head;
	if (temp == NULL || temp->next == NULL)
	{
		printf("L%u: can't add, stack too short\n", lineNumber);
		exit(EXIT_FAILURE);
	}
	else
	{
		temp->next->n = temp->next->n + temp->n;
		*head = (*head)->next;
		free(temp);
		(*head)->prev = NULL;
	}
}
/**
 *sub_func - Function that subs 2 top elements
 *@head: Reference to the doubly linked list.
 *@lineNumber: The line number being evaluated.
 */
void sub_func(stack_t **head, unsigned int lineNumber)
{
	stack_t *temp;

	if (head == NULL)
		head = malloc(sizeof(stack_t));
	temp = *head;
	if (temp == NULL || temp->next == NULL)
	{
		printf("L%u: can't sub, stack too short\n", lineNumber);
		exit(EXIT_FAILURE);
	}
	else
	{
		temp->next->n = temp->next->n - temp->n;
		*head = (*head)->next;
		free(temp);
		(*head)->prev = NULL;
	}
}
/**
 *nop_func - nothing
 *@head: Reference to the doubly linked list.
 *@lineNumber: The line number being evaluated.
 */
void nop_func(stack_t **head, unsigned int lineNumber)
{
	if (head == NULL && lineNumber > 1)
	{
		;
	}
}
