#include "push_swap.h"

void	display_with_index(t_stack *stack_a)
{
	t_stack	*tmp;

	tmp = stack_a;
	while (tmp)
	{
		printf("value: %d ... index: %d->", tmp->value, tmp->index);
		tmp = tmp->next;
	}
	printf("NULL\n");
}

void	display(t_stack *stack_a)
{
	t_stack *tmp;

	tmp = stack_a;
	while (tmp)
	{
		printf("%d->", tmp->value);
		tmp = tmp->next;
	}
	printf("NULL\n");
}