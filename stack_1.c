#include "monty.h"


/**
 * add_to_stack - Adds a node to the stack.
 * @new_node: Pointer to the new node.
 * @ln: Interger representing the line number of of the opcode.
 */

void add_to_stack(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE); /* Exiting if the new node is not valid */

	if (head == NULL)
	{
		/* If the stack is empty, set the new node as the head */
		head = *new_node;
		return;
	}
	stack_t *tmp = head; /* Temporary pointer to the current head of the stack */
	head = *new_node; /* Set the new node as the new head of the stack */
	head->next = tmp; /* Link the new head to the previous head */
	tmp->prev = head; /* Update the previous head's previous pointer to the new head */
}


/**
 * print_stack - Adds a node to the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: line number of  the opcode.
 */

void print_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	(void) line_number;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * pop_top - A function that adds a node to the stack.
 * @stack: A pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */

void pop_top(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		more_err(7, line_number);
	
	stack_t *tmp = *stack;
	*stack = (*stack)->next;
	
	if (*stack != NULL)
		(*stack)->prev = NULL;
	
	free(tmp);
}

/**
 * print_top - A function that prints the top node of the stack.
 * @stack: A pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */

void print_top(stack_t **stack, unsigned int line_number)
{
	/* Check if the stack pointer is valid and stack is not empty */
	if (stack == NULL || *stack == NULL)
	{
        report_error(6, line_number);
	}
	else
	{
		printf("%d\n", (*stack)->n);
	}
}
