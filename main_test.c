#include "push_swap.h"

void sa(stack *stack_a)
{
	stack *first;
	stack *second;

	first = stack_a;
	second = first->next;
	first->next = second->next;
	second->next = first;
	stack_a = second;
	// printf("%d | %d", first->value, second->value);
}
int	main(void)
{
	stack	*stack_a = NULL;
	// stack	*stack_b;

	add_node_back(&stack_a, 8);
	add_node_back(&stack_a, 10);
	add_node_back(&stack_a, 20);
	add_node_back(&stack_a, 3);
	// display(stack_a);
	sa(stack_a);
	display(stack_a);
}
