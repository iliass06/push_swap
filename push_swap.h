/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-fadi <iel-fadi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 14:09:51 by iel-fadi          #+#    #+#             */
/*   Updated: 2026/02/14 23:56:48 by iel-fadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct stack
{
	int				value;
	int				index;
	struct stack	*next;
}					t_stack;

void				push_to_stack(t_stack **src, t_stack **dest);
void				pa(t_stack **stack_a, t_stack **stack_b);
void				pb(t_stack **stack_a, t_stack **stack_b);
void				ra(t_stack **stack_a);
void				add_node_back(t_stack **stack_a, int value);
void				display(t_stack *stack_a);
void				index_stack(t_stack *stack_a);
void				display_with_index(t_stack *stack_a);
int					get_max_bits(t_stack *stack_a);
void				radix_sort(t_stack **stack_a, t_stack **stack_b);
int					listsize(t_stack *stack_a);
void				rra(t_stack **stack_a);
void				sa(t_stack **stack_a);
void				sort_three(t_stack **stack_a);
void				sort_five(t_stack **stack_a, t_stack **stack_b);
int					is_sorted(t_stack *stack_a);
void				free_mem(char *av[]);
void				free_stack(t_stack **stack);
void				error(t_stack **stack_a);

#endif