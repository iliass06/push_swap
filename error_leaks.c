/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_leaks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-fadi <iel-fadi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 23:55:10 by iel-fadi          #+#    #+#             */
/*   Updated: 2026/02/17 11:09:45 by iel-fadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_args(char *av[])
{
	int	i;

	if (!av)
		return ;
	i = 0;
	while (av[i])
	{
		free(av[i]);
		i++;
	}
	free(av);
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

void	error(t_stack **stack_a)
{
	write(2, "Error\n", 6);
	free_stack(stack_a);
	exit(1);
}
