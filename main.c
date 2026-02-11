#include "push_swap.h"

int main()
{
    stack  *stack_a;
    stack *stack_b;

    add_node(&stack_a, 8);
    add_node(&stack_a, 10);
    add_node(&stack_a, 20);
    add_node(&stack_a, 3);
    display(stack_a);
    index_stack(stack_a);
    printf("%d", max_bits(stack_a));

}
//00000000 00001101
//00000000 0000110
//00000000 000011
//00000000 00001
//00000000 0000