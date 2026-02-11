/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-fadi <iel-fadi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 14:09:51 by iel-fadi          #+#    #+#             */
/*   Updated: 2026/02/11 15:37:19 by iel-fadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

typedef struct stack
{
    int value;
    int index;
    struct stack *next;
}   stack;

void push_to_stack(stack **src, stack **dest);
void pa(stack **stack_a, stack **stack_b);
void pb(stack **stack_a, stack **stack_b);
void ra(stack **stack_a);
void add_node(stack **stack_a, int value);
void display(stack *stack_a);
void index_stack(stack *stack_a);
void display_with_index(stack *stack_a);
int get_max_bits(stack *stack_a);
void radix_sort(stack **stack_a, stack **stack_b);
int listsize(stack *stack_a);

#endif