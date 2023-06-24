#include "monty.h"
global_t data = {NULL, NULL, NULL};

/**
 * pall_func - prints all items in the list
 * @head: point to begining of the list
 * @lineNumber: line number of the file
 *
 */
void pall_func(stack_t **head, unsigned int lineNumber)
{
	stack_t *temp;

	if (lineNumber > 1)
	{
		;
	}

	temp = *head;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
/**
 * push_func - adds a node at bigining of list
 * @head: point to begining of the list
 * @lineNumber: line number of the file
 */
void push_func(stack_t **head, unsigned int lineNumber)
{
	int value;
	stack_t *newNode;

	if (data.opnum == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", lineNumber);
		exit(EXIT_FAILURE);

	}
	value = atoi(data.opnum);

	newNode = malloc(sizeof(stack_t));
	if (newNode == NULL)
	{
		fprintf(stderr, "Error: Failed to allocate memory\n");
		exit(EXIT_FAILURE);
	}

	newNode->n = value;
	newNode->prev = NULL;
	newNode->next = *head;

	if (*head != NULL)
		(*head)->prev = newNode;
	*head = newNode;
}
/**
 * pint_func - prints the value at top of stack
 * @head: point to begining of the list
 * @lineNumber: line number of the file
 */
void pint_func(stack_t **head, unsigned int lineNumber)
{
	if (*head != NULL)
		printf("%d\n", (*head)->n);
	else if (*head == NULL)
	{
		printf("L%u: can't pint, stack empty\n", lineNumber);
		exit(EXIT_FAILURE);
	}
}
/**
 *pop_func - the function that removes the top element of the stack
 *@head: Reference to the doubly linked list.
 *@lineNumber: The line number being evaluated.
 */
void pop_func(stack_t **head, unsigned int lineNumber)
{
	stack_t *temp;

	temp = *head;
	if (temp != NULL)
	{
		*head = (*head)->next;
		free(temp);
		if (*head != NULL)
			(*head)->prev = NULL;
		return;
	}
	printf("L%u: can't pop an empty stack\n", lineNumber);
	exit(EXIT_FAILURE);
}

/**
 *swap_func - Function that swaps the number of the top two doubly linked list.
 *@head: Reference to the doubly linked list.
 *@lineNumber: The line number being evaluated.
 */
void swap_func(stack_t **head, unsigned int lineNumber)
{
	stack_t *temp;
	int help;

	temp = *head;
	if (temp == NULL || temp->next == NULL)
	{
		printf("L%u: can't swap, stack too short\n", lineNumber);
		exit(EXIT_FAILURE);
	}
	else
	{
		help = temp->n;
		temp->n = temp->next->n;
		temp->next->n = help;
	}
}
