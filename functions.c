#include "monty.h"

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

	if (head == NULL)
		head = malloc(sizeof(stack_t));
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
	stack_t *newNode = (stack_t *)malloc(sizeof(stack_t));

	if (lineNumber > 1)
	{
		;
	}
	if (head == NULL)
		head = malloc(sizeof(stack_t));
	/*Create a new node*/
	if (newNode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	/*Set the node's data*/
	newNode->n = gbopnum;
	/*Set the next pointer of the new node*/
	newNode->next = *head;
	/*Set the previous pointer of the new node*/
	newNode->prev = NULL;
	/*Update the previous pointer of the previous head, if it exists*/
	if (*head != NULL)
	{
		(*head)->prev = newNode;
	}
	/*Update the head pointer*/
	*head = newNode;
}
/**
 * pint_func - prints the value at top of stack
 * @head: point to begining of the list
 * @lineNumber: line number of the file
 */
void pint_func(stack_t **head, unsigned int lineNumber)
{
	if (head == NULL)
		head = malloc(sizeof(stack_t));
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

	if (head == NULL)
		head = malloc(sizeof(stack_t));
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
