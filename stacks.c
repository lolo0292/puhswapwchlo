/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleichtn <lleichtn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:32:04 by lleichtn          #+#    #+#             */
/*   Updated: 2025/01/09 14:48:01 by lleichtn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Calculer la taille de la pile à partir de la liste chaînée
int sizeoflist(t_node *list)
{
    int size = 0;
    while (list)
    {
        size++;
        list = list->next;
    }
    return size;
}

// Allouer la mémoire pour les piles a et b
void stackmem(int **a, int **b, int size)
{
    *a = malloc(sizeof(int) * size);
    if (!*a)
    {
        ft_printf("%s", "Error\n");
        exit(EXIT_FAILURE);
    }

    *b = malloc(sizeof(int) * size);
    if (!*b)
    {
        free(*a);
        ft_printf("%s", "Error\n");
        exit(EXIT_FAILURE);
    }
}

// Remplir le tableau a avec les valeurs de la liste chaînée et libérer la liste
void filllist(int *a, t_node **list)
{
    t_node *current = *list;
    t_node *temp;
    int i = 0;

    while (current)
    {
        a[i++] = current->value;
        temp = current;
        current = current->next;
        free(temp);
    }

    *list = NULL;
}

// Fonction principale pour initialiser les piles
void init_stacks(int **a, int *size_a, int **b, int *size_b, t_node **list_a)
{
    *size_a = calculate_size(*list_a);
    *size_b = 0;

    allocate_stacks(a, b, *size_a);
    fill_and_free_list(*a, list_a);
}