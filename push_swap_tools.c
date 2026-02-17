/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-fadi <iel-fadi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 00:43:00 by iel-fadi          #+#    #+#             */
/*   Updated: 2026/02/16 21:40:44 by iel-fadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	add_node_back(t_stack **stack_a, int value)
{
	t_stack	*new_node;
	t_stack	*tmp;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return ;
	new_node->value = value;
	new_node->next = NULL;
	if (*stack_a == NULL)
	{
		*stack_a = new_node;
		return ;
	}
	tmp = *stack_a;
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	tmp->next = new_node;
}

void	push_to_stack(t_stack **src, t_stack **dest)
{
	t_stack	*node_to_move;

	node_to_move = *src;
	*src = (*src)->next;
	node_to_move->next = *dest;
	*dest = node_to_move;
}

void	sort_three(t_stack **stack_a)
{
	t_stack	*head;
	int		max_index;

	max_index = listsize(*stack_a) - 1;
	head = *stack_a;
	if (head->index == max_index)
		ra(stack_a);
	else if ((head->next)->index == max_index)
		rra(stack_a);
	if ((*stack_a)->index > ((*stack_a)->next)->index)
		sa(stack_a);
}

void	sort_five(t_stack **stack_a, t_stack **stack_b)
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

int	is_sorted(t_stack *stack_a)
{
	while (stack_a && stack_a->next)
	{
		if (stack_a->value > stack_a->next->value)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}
