#include "push_swap.h"

void	sa(stack **stack_a)
{
	stack	*first;
	stack	*second;

	first = *stack_a;
	second = first->next;
	if (first->value > second->value)
	{
		first->next = second->next;
		second->next = first;
		*stack_a = second;
	}
	else
		return ;
	write(1, "sa\n", 3);
}

void	rra(stack **stack_a)
{
	stack	*last;
	stack	*b_last;

	b_last = *stack_a;
	while (b_last->next->next)
	{
		b_last = b_last->next;
	}
	last = b_last->next;
	last->next = *stack_a;
	b_last->next = NULL;
	*stack_a = last;
	write(1, "rra\n", 4);
}

void	sort_three(stack **stack_a)
{
	stack	*head;
	int		max_index;

	head = *stack_a;
	max_index = head->index;
	while (head)
	{
		if (max_index < head->index)
			max_index = head->index;
		head = head->next;
	}
	head = *stack_a;
	if (head->index == max_index)
		ra(stack_a);
	else if (head->next->index == max_index)
	{
		rra(stack_a);
	}
	if ((*stack_a)->index > ((*stack_a)->next)->index)
		sa(stack_a);
}

void	sort_five(stack **stack_a, stack **stack_b)
{
	int	size;

	size = listsize(*stack_a);
	while (size > 3)
	{
		if ((*stack_a)->index == 0 || (*stack_a)->index == 1)
		{
			pb(stack_a, stack_b);
			size--;
		}
		else
			ra(stack_a);
	}
	sort_three(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
	if ((*stack_a)->index > ((*stack_a)->next)->index)
		sa(stack_a);
}
int	main(void)
{
	stack	*stack_a;
	stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	add_node_back(&stack_a, 2);
	add_node_back(&stack_a, 1);
	add_node_back(&stack_a, 0);
	// add_node_back(&stack_a, 3);
	index_stack(stack_a);
	display(stack_a);
	sort_three(&stack_a);
	display(stack_a);
}
