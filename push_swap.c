/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-fadi <iel-fadi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 00:42:51 by iel-fadi          #+#    #+#             */
/*   Updated: 2026/02/17 12:19:34 by iel-fadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_stack(t_stack *stack_a)
{
	t_stack	*tmp1;
	t_stack	*tmp2;
	int		ind;

	tmp1 = stack_a;
	while (tmp1)
	{
		ind = 0;
		tmp2 = stack_a;
		while (tmp2)
		{
			if (tmp1->value > tmp2->value)
				ind++;
			tmp2 = tmp2->next;
		}
		tmp1->index = ind;
		tmp1 = tmp1->next;
	}
}

static int	get_max_bits(t_stack *stack_a)
{
	t_stack	*head;
	int		max_bits;
	int		max_index;

	head = stack_a;
	if (!head)
		return (0);
	max_index = head->index;
	max_bits = 0;
	while (head)
	{
		if (max_index < head->index)
			max_index = head->index;
		head = head->next;
	}
	while (max_index >> max_bits != 0)
		max_bits++;
	return (max_bits);
}

int	listsize(t_stack *stack_a)
{
	int		size;
	
	size = 0;
	while (stack_a)
	{
		stack_a = stack_a->next;
		size++;
	}
	return (size);
}

void	radix_sort(t_stack **stack_a, t_stack **stack_b)
{
	int		max_bits;
	int		size;
	int		i;
	int		j;
	t_stack	*head;

	max_bits = get_max_bits(*stack_a);
	size = listsize(*stack_a);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			head = *stack_a;
			if (((head->index >> i) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
			j++;
		}
		while (*stack_b)
			pa(stack_a, stack_b);
		i++;
	}
}
