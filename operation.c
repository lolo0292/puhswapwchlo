/* operations.c */
#include "push_swap.h"

void swap(t_stack *stack)
{
    int temp;

    if (stack->size < 2)
        return;
    temp = stack->array[0];
    stack->array[0] = stack->array[1];
    stack->array[1] = temp;
}

void push(t_stack *src, t_stack *dest)
{
    int i;

    if (src->size == 0)
        return;
    i = dest->size;
    while (i > 0)
    {
        dest->array[i] = dest->array[i - 1];
        i--;
    }
    dest->array[0] = src->array[0];
    i = 0;
    while (i < src->size - 1)
    {
        src->array[i] = src->array[i + 1];
        i++;
    }
    src->size--;
    dest->size++;
}

void rotate(t_stack *stack)
{
    int temp;
    int i;

    if (stack->size < 2)
        return;
    temp = stack->array[0];
    i = 0;
    while (i < stack->size - 1)
    {
        stack->array[i] = stack->array[i + 1];
        i++;
    }
    stack->array[stack->size - 1] = temp;
}

void reverse_rotate(t_stack *stack)
{
    int temp;
    int i;

    if (stack->size < 2)
        return;
    temp = stack->array[stack->size - 1];
    i = stack->size - 1;
    while (i > 0)
    {
        stack->array[i] = stack->array[i - 1];
        i--;
    }
    stack->array[0] = temp;
}

void sa(t_stack *a) 
{ 
	swap(a); 
}
void sb(t_stack *b) 
{ 
	swap(b); 
}
void ss(t_stack *a, t_stack *b)
{
    swap(a);
    swap(b);
}

void pa(t_stack *a, t_stack *b) 
{ push(b, a); 
}
void pb(t_stack *a, t_stack *b) 
{ push(a, b); 
}

void ra(t_stack *a) 
{ 
	rotate(a); 
}
void rb(t_stack *b) 
{ rotate(b); 
}
void rr(t_stack *a, t_stack *b)
{
    rotate(a);
    rotate(b);
}

void rra(t_stack *a) 
{ reverse_rotate(a); }
void rrb(t_stack *b) 
{ reverse_rotate(b); }
void rrr(t_stack *a, t_stack *b)
{
    reverse_rotate(a);
    reverse_rotate(b);
}
