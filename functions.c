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
