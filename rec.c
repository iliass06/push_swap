#include "push_swap.h"
#include "libft/libft.h"

// void push_to_stack(t_stack **src, t_stack **dest)
// {
//     t_stack *heads;

//     heads = *src;
//     *src = (*src)->next;
//     heads->next = *dest;
//     *dest = heads;

// }

// void ra(t_stack **stack_a)
// {
// 	t_stack *tmp;
// 	t_stack *tmp1;

// 	tmp = *stack_a;
// 	*stack_a = (*stack_a)->next;
// 	tmp1 = tmp;
// 	while(tmp->next)
// 		tmp = tmp->next;
// 	tmp->next = tmp1;
// 	tmp1->next = NULL;
// }

// void rra(t_stack **stack_a)
// {
// 	t_stack *tmp;
// 	t_stack *nhead;

// 	tmp = *stack_a;
// 	while(tmp->next->next)
// 		tmp = tmp->next;
// 	nhead = tmp->next;
// 	tmp->next->next = *stack_a;
// 	*stack_a = nhead;
// 	tmp->next = NULL;
// }

// void sa(t_stack **stack_a)
// {
// 	t_stack *second;

// 	second = (*stack_a)->next;
// 	(*stack_a)->next = second->next;
// 	second->next = *stack_a;
// 	*stack_a = second;
// }


void	display(t_stack *stack_a)
{
	t_stack *tmp;

	tmp = stack_a;
	while (tmp)
	{
		printf("%d->", tmp->value);
		tmp = tmp->next;
	}
	printf("NULL\n");
}
void add_node_back(t_stack **stack_a, int value)
{
	t_stack *new;
	t_stack *tmp;

	new = malloc(sizeof(t_stack));
	if(!new)
		return ;
	new->value = value;
	new->next = NULL;
	if(*stack_a == NULL)
	{	
		*stack_a = new;
		return ;
	}
	tmp = *stack_a;
	while(tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

// void indexer_stack(t_stack *stack_a)
// {
// 	t_stack *tmp1;
// 	t_stack *tmp2;
// 	int id;

// 	tmp1 = stack_a;
// 	while(tmp1)
// 	{
// 		tmp2 = stack_a;
// 		id = 0;
// 		while (tmp2)
// 		{
// 			if(tmp1->value > tmp2->value)
// 				id++;
// 			tmp2 = tmp2->next;
// 		}
// 		tmp1->index = id;
// 		tmp1 = tmp1->next;
// 	}
// }

// int get_max_bits(t_stack *stack_a)
// {
// 	int max_index;
// 	int max_bits;
	
// 	max_bits = 0;
// 	max_index = listsize(stack_a) - 1;
// 	while (max_index >> max_bits != 0)
// 		max_bits++;
// 	return (max_bits);
// }

// void radix_sort(t_stack **stack_a, t_stack **stack_b)
// {
// 	int i;
// 	int j;
// 	int size;
// 	int max_bits;
// 	t_stack *tmp;

// 	max_bits = get_max_bits(*stack_a);
// 	size = listsize(*stack_a);
// 	i = 0;
// 	while (i < max_bits)
// 	{
// 		j = 0;
// 		while (j < size)
// 		{
// 			tmp = *stack_a;
// 			if ((tmp->index >> i) & 1 == 1)
// 				ra(stack_a);
// 			else
// 				pb(stack_a, stack_b);
// 			j++;
// 		}
// 		while (*stack_b)
// 			pa(stack_a, stack_b);
// 		i++;
// 	}
// }
// void sort_three(t_stack **stack_a)
// {
// 	int max_index;
// 	t_stack *tmp;

// 	max_index = (*stack_a)->index;
// 	tmp = *stack_a;
// 	while (tmp)
// 	{
// 		if (tmp->index > max_index)
// 			max_index = tmp->index;
// 		tmp = tmp->next;
// 	}
// 	tmp = *stack_a;
// 	if (tmp->index == max_index)
// 		ra(stack_a);
// 	else if ((tmp->next)->index == max_index)
// 		rra(stack_a);
// 	if((*stack_a)->index > ((*stack_a)->next)->index)
// 		sa(stack_a);
// }

int args_not_integer(char *args)
{
	int i;

	i = 0;
	if (args[i] == '+' || args[i] == '-')
		i++;
	if(!args[i])
		return (0);
	while (args[i])
	{
		if (args[i] < '0' || args[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int is_duplicate(t_stack *stack_a, int  nb)
{
	while (stack_a)
	{
		if (stack_a->value == nb)
			return(0);
		stack_a = stack_a->next;
	}
	return (1);
}
void free_stack(t_stack **stack)
{
	t_stack *tmp;

	while(*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

void free_args(char **args)
{
	int i;

	i = 0;
	if(!args)
		return ;
	while(args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}
void error(t_stack **stack)
{
	write(2, "Error\n", 6);
	free_stack(stack);
	exit(1);
}

t_stack *parse_args(char **av, int ac)
{
	int i;
	int j;
	long nb;
	t_stack *stack_a;
	char **args;


	i = 1;
	while (i < ac)
	{
		args = ft_split(av[i], ' ');
		if(!args)
			error(&stack_a);
		if(!args[0])
		{
			free_args(args);
			error(&stack_a);
		}
		j = 0;
		while(args[j])
		{
			if(!args_not_integer(args[j]))
			{
				free_args(args);
				error(&stack_a);
			}
			nb = ft_atol(args[j]);
			if (nb > 2147483647 || nb < -2147483648 || !is_duplicate(stack_a, (int)nb))
			{
				free_args(args);
				error(&stack_a);
			}
			add_node_back(&stack_a, (int)nb);
			j++;
		}
		i++;
		free_args(args);
	}
}
// void sort_five(t_stack **stack_a, t_stack **stack_b)
// {
// 	int size;
	
// 	size = listsize(*stack_a);
// 	while (size > 3)
// 	{
// 		if ((*stack_a)->index == 0 || (*stack_a)->index == 1)
// 		{	
// 			pb(stack_a, stack_b);
// 			size--;
// 		}
// 		else
// 			ra(stack_a);
// 	}
// 	sort_three(stack_a);
// 	while (*stack_b)
// 		pa(stack_a, stack_b);
// 	if ((*stack_a)->index > ((*stack_a)->next)->index)
// 		sa(stack_a);
// }

int main(int ac, char *av[])
{
    t_stack *stack_a;
    t_stack *stack_b;
	
	
	if (ac < 2)
		return (0);
	stack_b = NULL;
	stack_a = parse_args(av, ac);
	if (stack_a == NULL || stack_a->next == NULL || is_sorted(stack_a))
	{
		free_stack(&stack_a);
		return (0);
	}
	index_stack(&stack_a);
	if(listsize(stack_a) == 2)
		sa(&stack_a);
	else if (listsize(stack_a) == 3)
		sort_three(&stack_a);
	else if (listsize(stack_a) <= 5)
		sort_five(&stack_a, &stack_b);
	else
		radix_sort(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
void				display_with_index(t_stack *stack_a);
void				display(t_stack *stack_a);