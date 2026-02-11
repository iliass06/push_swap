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
	printf("%d", listsize(stack_a));
}
// 00000000 00001101
// 00000000 0000110
// 00000000 000011
// 00000000 00001
// 00000000 0000