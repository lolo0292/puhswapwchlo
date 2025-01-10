/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleichtn <lleichtn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:31:40 by lleichtn          #+#    #+#             */
/*   Updated: 2025/01/07 16:31:41 by lleichtn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_three(t_stack *a, t_stack *b)
{
    (void)b;
    if (a->array[0] > a->array[1] && a->array[0] > a->array[2])
        ra(a, b);
    if (a->array[1] > a->array[2])
        sa(a, b);
    if (a->array[0] > a->array[1])
        sa(a, b);
}

void sort_five(t_stack *a, t_stack *b)
{
    while (a->size > 3)
        pb(a->array, &a->size, b->array, &b->size);
    sort_three(a, b);
    while (b->size > 0)
        pa(b->array, &b->size, a->array, &a->size);
}

void push_swap(t_stack *a, t_stack *b)
{
    if (a->size <= 1)
        return;
    if (a->size == 2 && a->array[0] > a->array[1])
        sa(a, b);
    else if (a->size == 3)
        sort_three(a, b);
    else if (a->size <= 5)
        sort_five(a, b);
    else
        radix_sort(a, b);
}
