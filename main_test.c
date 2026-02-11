#include "push_swap.h"

int	main(void)
{
	stack	*stack_a;
	stack	*stack_b;

	add_node(&stack_a, 8);
	add_node(&stack_a, 10);
	add_node(&stack_a, 20);
	add_node(&stack_a, 3);
	display(stack_a);
	printf("------------------------------\n");
	index_stack(stack_a);
	radix_sort(&stack_a, &stack_b);
	display(stack_a);
}
