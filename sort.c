/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleichtn <lleichtn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 15:33:45 by lleichtn          #+#    #+#             */
/*   Updated: 2025/01/13 15:00:29 by lleichtn         ###   ########.fr       */
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

    // Trouver le nombre maximal dans la pile a
    max_num = 0;
    i = 0;
    while (i < a->size)
    {
        if (a->array[i] > max_num)
            max_num = a->array[i];
        i++;
    }

    // Calculer le nombre de bits nécessaires pour max_num
    max_bits = 0;
    while ((max_num >> max_bits) != 0)
        max_bits++;

    // Effectuer le tri par bits
    i = 0;
    while (i < max_bits)
    {
        size = a->size; // Capturer la taille initiale de a
        j = 0;
        while (j < size)
        {
            // Vérifier le i-ème bit du premier élément
            if (((a->array[0] >> i) & 1) == 1)
                ra(a); // Rotation si le bit est 1
            else
                pb(a, b); // Pousser dans b si le bit est 0
            j++;
        }

        // Remettre les éléments dans a
        while (b->size > 0)
            pa(a, b);

        i++;
    }
}


// void sort(int argc, char **argv)
// {
//     int array[1024];
//     int size = 0;

//     if (!parse_arguments(argc, argv, array, &size))
//     {
//         write(2, "Error in parsing arguments\n", 27);
//         exit(EXIT_FAILURE);
//     }
//     t_stack a;
//     t_stack b;
//     if (size <= 3)
//         sort_small(&a, &b);
//     else
//         radix_sort(&a, &b);
// }