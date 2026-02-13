/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-fadi <iel-fadi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 16:37:36 by iel-fadi          #+#    #+#             */
/*   Updated: 2026/02/14 00:38:26 by iel-fadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

static void	error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

static int	arg_not_integer(char *arg)
{
	int	i;

	i = 0;
	if (arg[i] == '+' || arg[i] == '-')
		i++;
	if (!arg[i])
		return (0);
	while (arg[i])
	{
		if (arg[i] < '0' || arg[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static int	is_duplicate(stack *stack_a, int nb)
{
	stack	*tmp;

	tmp = stack_a;
	while (tmp)
	{
		if (tmp->value == nb)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

static stack	*parse_args(int ac, char *av[])
{
	stack	*stack_a;
	char	**args;
	int		i;
	long	nb;
	int		j;

	i = 1;
	while (i < ac)
	{
		args = ft_split(av[i], ' ');
		j = 0;
		while (args[j])
		{
			if (!arg_not_integer(args[j]))
				error();
			nb = ft_atol(args[j]);
			if (nb > 2147483647 || nb < -2147483648 || !is_duplicate(stack_a,
					(int)nb))
				error();
			add_node_back(&stack_a, (int)nb);
			j++;
		}
		i++;
	}
	return (stack_a);
}

int	main(int ac, char *av[])
{
	stack	*stack_a;
	stack	*stack_b;

	if (ac < 2)
		return (0);
	stack_a = parse_args(ac, av);
	stack_b = NULL;
	if (stack_a == NULL || stack_a->next == NULL)
		return (0);
	if (is_sorted(stack_a))
		return (0);
	index_stack(stack_a);
	if (listsize(stack_a) == 2)
		sa(&stack_a);
	else if (listsize(stack_a) == 3)
		sort_three(&stack_a);
	else if (listsize(stack_a) <= 5)
		sort_five(&stack_a, &stack_b);
	else
		radix_sort(&stack_a, &stack_b);
	return (0);
}
