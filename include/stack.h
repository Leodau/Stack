/*
** LEO Michele, 2017
** Utility Module
** File description:
** Stack Prototypes
*/

#ifndef STACK_H_
	#define STACK_H_

	typedef char* stack_element_t;

	typedef struct stack
	{
		stack_element_t *contents;
		int top;
		int max_size;
	} stack_t;

	stack_t *stack_init(int);
	int stack_is_empty(stack_t*);
	void stack_destroy(stack_t*);
	void stack_push(stack_t*, stack_element_t);
	stack_element_t stack_pop(stack_t*);
	stack_element_t stack_peek(stack_t*);
#endif