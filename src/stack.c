/*
** LEO Michele, 2017
** Utility Module
** File description:
** Stack Core
*/

#include <stdlib.h>
#include "stack.h"

stack_t *stack_init(int size)
{
	stack_t *stack = malloc(sizeof(stack_t));
	stack_element_t *contents;

	contents = (stack_element_t*) malloc(sizeof(stack_element_t) * size);
	if (!contents || !stack)
		exit (EXIT_FAILURE);
	stack->contents = contents;
	stack->top = -1;
	stack->max_size = size;
	return (stack);
}

void stack_destroy(stack_t *stack)
{
	free(stack->contents);
	stack->contents = NULL;
	stack->top = -1;
	stack->max_size = 0;
}

stack_element_t stack_peek(stack_t *stack)
{
	if (stack->top < 0)
		exit (EXIT_FAILURE);
	return (stack->contents[stack->top]);
}

void stack_push(stack_t *stack, stack_element_t element)
{
	if (stack->top >= stack->max_size - 1)
		exit (EXIT_FAILURE);
	stack->top++;
	stack->contents[stack->top] = element;
}

stack_element_t stack_pop(stack_t *stack)
{
	stack_element_t element;

	if (stack->top < 0)
		exit (EXIT_FAILURE);
	element = stack->contents[stack->top];
	stack->contents[stack->top] = '\0';
	stack->top--;
	return (element);
}