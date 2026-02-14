/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_add_tools.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-fadi <iel-fadi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 00:38:43 by iel-fadi          #+#    #+#             */
/*   Updated: 2026/02/14 22:02:12 by iel-fadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_b == NULL)
		return ;
	push_to_stack(stack_b, stack_a);
	write(1, "pa\n", 3);
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_a == NULL)
		return ;
	push_to_stack(stack_a, stack_b);
	write(1, "pb\n", 3);
}

void	ra(t_stack **stack_a)
{
	t_stack	*tmp;
	t_stack	*head;

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

void	sa(t_stack **stack_a)
{
	t_stack	*first;
	t_stack	*second;

	first = *stack_a;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack_a = second;
	write(1, "sa\n", 3);
}

void	rra(t_stack **stack_a)
{
	t_stack	*last;
	t_stack	*b_last;

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
