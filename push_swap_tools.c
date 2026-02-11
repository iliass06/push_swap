#include "push_swap.h"

void	push_to_stack(stack **src, stack **dest)
{
	stack	*node_to_move;

	node_to_move = *src;
	*src = (*src)->next;
	node_to_move->next = *dest;
	*dest = node_to_move;
}

void	pa(stack **stack_a, stack **stack_b)
{
	if (*stack_b == NULL)
		return ;
	push_to_stack(stack_b, stack_a);
	write(1, "pa\n", 3);
}

void	pb(stack **stack_a, stack **stack_b)
{
	if (*stack_a == NULL)
		return ;
	push_to_stack(stack_a, stack_b);
	write(1, "pb\n", 3);
}

void	ra(stack **stack_a)
{
	stack	*tmp;
	stack	*head;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	head = *stack_a;
	*stack_a = (*stack_a)->next;
	tmp = *stack_a;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = head;
	head->next = NULL;
	write(1, "ra\n", 3);
}