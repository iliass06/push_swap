#include "push_swap.h"

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