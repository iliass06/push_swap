#include "push_swap.h"

void push_to_stack(stack **src, stack **dest)
{
    stack *node_to_move;

    node_to_move = *src;
    *src = (*src)->next;
    node_to_move->next = *dest;
    *dest = node_to_move;   
}

void pa(stack **stack_a, stack **stack_b)
{
    if(*stack_b == NULL)
        return;
    push_to_stack(stack_b, stack_a);
    write(1, "pa\n", 3);
}

void pb(stack **stack_a, stack **stack_b)
{
    if(*stack_a == NULL)
        return;
    push_to_stack(stack_a, stack_b);
    write(1, "pb\n", 3);
}

void ra(stack **stack_a)
{
    stack *tmp;
    stack *head;

    if (*stack_a == NULL || (*stack_a)->next == NULL)
        return;
    head = *stack_a;
    *stack_a = (*stack_a)->next;
    tmp = *stack_a;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    tmp->next = head;
    head->next = NULL;
    write(1, "ra\n", 3);

}

void add_node(stack **stack_a, int value)
{
    stack *new_node = malloc(sizeof(stack));

    new_node->value = value;
    new_node->next = *stack_a;
    *stack_a = new_node;
}

void display_with_index(stack *stack_a)
 {  
    stack *tmp = stack_a;
    while (tmp)
    {
        printf("value: %d ... index: %d->", tmp->value, tmp->index);
        tmp = tmp->next;
    }
    printf("NULL\n");
}

void display(stack *stack_a)
 {  
    stack *tmp = stack_a;
    while (tmp)
    {
        printf("%d->", tmp->value);
        tmp = tmp->next;
    }
    printf("NULL\n");
}

void index_stack(stack *stack_a)
{
    stack *tmp1;
    stack *tmp2;
    int ind;

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

int max_bits(stack *stack_a)
{
     stack *head;
     int max_bits;
     int max_index;

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
     while(max_index >> max_bits != 0)
        max_bits++;
    return (max_bits);
}