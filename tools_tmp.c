#include "push_swap.h"

void	add_node(stack **stack_a, int value)
{
	stack	*new_node;

	new_node = malloc(sizeof(stack));
	new_node->value = value;
	new_node->next = *stack_a;
	*stack_a = new_node;
}

void	display_with_index(stack *stack_a)
{
	stack	*tmp;

	tmp = stack_a;
	while (tmp)
	{
		printf("value: %d ... index: %d->", tmp->value, tmp->index);
		tmp = tmp->next;
	}
	printf("NULL\n");
}

void	display(stack *stack_a)
{
	stack	*tmp;

	tmp = stack_a;
	while (tmp)
	{
		printf("%d->", tmp->value);
		tmp = tmp->next;
	}
	printf("NULL\n");
}