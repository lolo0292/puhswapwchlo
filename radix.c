/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleichtn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 11:45:03 by lleichtn          #+#    #+#             */
/*   Updated: 2025/01/10 11:45:09 by lleichtn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Fonction pour obtenir le bit d'un entier à une position donnée
int get_bit(int num, int pos)
{
    return ((num >> pos) & 1);
}

// Fonction pour trouver le nombre maximal dans une pile
int find_max(t_stack *stack)
{
    int max;
    t_stack *current;

    if (!stack)
        return (0);
    max = stack->value;
    current = stack->next;
    while (current)
    {
        if (current->value > max)
            max = current->value;
        current = current->next;
    }
    return (max);
}

// Fonction pour compter le nombre de bits nécessaires pour le tri
int count_bits(int max)
{
    int bits = 0;

    while (max > 0)
    {
        max >>= 1;
        bits++;
    }
    return (bits);
}

// Fonction principale pour le tri radix
void radix_sort(t_stack **stack_a, t_stack **stack_b)
{
    int max;
    int bits;
    int i;
    int size;
    int j;

    max = find_max(*stack_a);
    bits = count_bits(max);
    i = 0;
    while (i < bits)
    {
        j = 0;
        size = stack_size(*stack_a);
        while (j < size)
        {
            if (get_bit((*stack_a)->value, i) == 0)
                push(stack_a, stack_b, 'b', i);
            else
                rotate(stack_a, 'a');
            j++;
        }
        while (*stack_b)
            push(stack_b, stack_a, 'a', i);
        i++;
    }
}
