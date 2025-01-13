/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleichtn <lleichtn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:31:40 by lleichtn          #+#    #+#             */
/*   Updated: 2025/01/13 15:39:03 by lleichtn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void error_exit(void)
{
    write(2, "Error\n", 6);
    exit(EXIT_FAILURE);
}

t_stack init_stack(int size)
{
    t_stack stack;

    stack.array = malloc(size * sizeof(int));
    if (!stack.array)
        error_exit();
    stack.size = 0;
    return stack;
}

void free_stack(t_stack *stack)
{
    if (stack->array)
        free(stack->array);
    stack->array = NULL;
    stack->size = 0;
}

int is_sorted(t_stack *stack)
{
    int i;

    i = 0;
    while (i < stack->size - 1)
    {
        if (stack->array[i] > stack->array[i + 1])
            return 0;
        i++;
    }
    return 1;
}

void push_swap(t_stack *a, t_stack *b)
{
    if (is_sorted(a))
        return;
    if (a->size <= 3)
        sort_small(a, b);
    else
        radix_sort(a, b);
}

void print_stack(t_stack *stack)
{
    int i;

    i = 0;
    while (i < stack->size)
    {
        printf("%d ", stack->array[i]);
        i++;
    }
}

// int main(int argc, char **argv)
// {
//     t_stack a;
//     t_stack b;
//     int i;

//     if (argc < 2)
//         return 0;

//     a = init_stack(argc - 1);
//     b = init_stack(argc - 1);

//     if (!parse_arguments(argc, argv, a.array, &a.size))
//     {
//         write(2, "Error\n", 15);
//         free_stack(&a);
//         free_stack(&b);
//         return EXIT_FAILURE;
//     }

//     push_swap(&a, &b);
//     print_stack(&a);

//     free_stack(&a);
//     free_stack(&b);
//     return 0;
// }

int count_steps(t_stack *a, t_stack *b)
{
    int step_count = 0;
    int max_num;
    int max_bits;
    int i;
    int j;

    max_num = 0;
    i = 0;
    while (i < a->size)
    {
        if (a->array[i] > max_num)
            max_num = a->array[i];
        i++;
    }

    max_bits = 0;
    while ((max_num >> max_bits) != 0)
        max_bits++;

    i = 0;
    while (i < max_bits)
    {
        j = 0;
        while (j < a->size)
        {
            if (((a->array[0] >> i) & 1) == 1)
            {
                ra(a);
                step_count++;
            }
            else
            {
                pb(a, b);
                step_count++;
            }
            j++;
        }
        while (b->size > 0)
        {
            pa(a, b);
            step_count++;
        }
        i++;
    }
    return step_count;
}


int main(int argc, char **argv)
{
    t_stack a;
    t_stack b;

    // if (argc < 2)
    //     return 0;

    a = init_stack(argc - 1);
    b = init_stack(argc - 1);

    if (!parse_arguments(argc, argv, a.array, &a.size))
    {
        write(2, "Error in parsing arguments\n", 27);
        free_stack(&a);
        free_stack(&b);
        return EXIT_FAILURE;
    }

    push_swap(&a, &b);
    print_stack(&a);
    int steps = count_steps(&a, &b);
    ft_printf("\nTotal steps: %d\n", steps);

    free_stack(&a);
    free_stack(&b);
    return 0;
}
