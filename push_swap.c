#include "push_swap.h"

void	index_stack(stack *stack_a)
{
	stack	*tmp1;
	stack	*tmp2;
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

int	get_max_bits(stack *stack_a)
{
	stack	*head;
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

int listsize(stack *stack_a)
{
    stack *tmp;
    int size;

    size = 0;
    tmp = stack_a;
    while (tmp)
    {
        tmp = tmp->next;
        size++;
    }
    return (size);
}

void	radix_sort(stack **stack_a, stack **stack_b)
{
    int max_bits;
    int size;
    int i;
    int j;
    stack *head;

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
