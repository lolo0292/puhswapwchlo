/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleichtn <lleichtn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 15:33:45 by lleichtn          #+#    #+#             */
/*   Updated: 2025/01/13 18:33:04 by lleichtn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_small(t_stack *a, t_stack *b)
{
    (void)b;
    if (!a || a->size < 2)
        return;
    if (a->size == 2 && a->array[0] > a->array[1])
        sa(a);
    else if (a->size == 3)
    {
        if (a->array[0] > a->array[1] && a->array[0] > a->array[2])
            ra(a);
        else if (a->array[1] > a->array[0] && a->array[1] > a->array[2])
            rra(a);
        if (a->array[0] > a->array[1])
            sa(a);
    }
}


void radix_sort(t_stack *a, t_stack *b)
{
    int max_num;
    int max_bits;
    int i;
    int j;
    int size;
    int offset;

    // Calculer l'offset pour rendre les nombres positifs
    offset = 0;
    for (i = 0; i < a->size; i++)
    {
        if (a->array[i] < offset)
            offset = a->array[i];
    }
    offset = -offset;

    // Appliquer l'offset à tous les éléments
    for (i = 0; i < a->size; i++)
    {
        a->array[i] += offset;
    }

    // Trouver le nombre maximal dans la pile a
    max_num = a->array[0];
    for (i = 1; i < a->size; i++)
    {
        if (a->array[i] > max_num)
            max_num = a->array[i];
    }

    // Calculer le nombre de bits nécessaires pour max_num
    max_bits = 0;
    while ((max_num >> max_bits) != 0)
        max_bits++;

    // Effectuer le tri par bits
    for (i = 0; i < max_bits; i++)
    {
        size = a->size;
        for (j = 0; j < size; j++)
        {
            if (((a->array[0] >> i) & 1) == 1)
                ra(a); // Rotation si le bit est 1
            else
                pb(a, b); // Pousser dans b si le bit est 0
        }

        // Remettre les éléments dans a
        while (b->size > 0)
            pa(a, b);
    }

    // Retirer l'offset pour restaurer les valeurs originales
    for (i = 0; i < a->size; i++)
    {
        a->array[i] -= offset;
    }
}
