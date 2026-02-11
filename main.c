/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-fadi <iel-fadi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 16:37:36 by iel-fadi          #+#    #+#             */
/*   Updated: 2026/02/11 16:52:25 by iel-fadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
int	main(int ac, char *av[])
{
	stack	*stack_a;
	stack	*stack_b;
    int i;
    int nb;
    if (ac < 2)
        return (0);
    i = ac - 1;
    while (i > 0)
    {
        nb = ft_atoi(av[i]);
        add_node(&stack_a, nb);
        i--;
    }
    index_stack(stack_a);
    radix_sort(&stack_a, &stack_b);
    display(stack_a);
}