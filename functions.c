#include "monty.h"
void pall_func(stack_t **stack, unsigned int num)
{
	if (stack != NULL && num)
	{
		printf("%d\n",num);
	}
	if (stack != NULL)
		free(stack);
}
void push_func(stack_t **stack, unsigned int num)
{
	if (stack != NULL && num)
	{
		printf("%d\n",num);
	}
	if (stack != NULL)
		free(stack);
}
