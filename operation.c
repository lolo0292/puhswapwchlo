/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleichtn <lleichtn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:04:50 by lleichtn          #+#    #+#             */
/*   Updated: 2025/01/07 17:06:59 by lleichtn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Échanger deux éléments, swap.c
void swap (int *stack, int size)
{
	int tmp;
	
	if (size < 2)
		return;
	tmp = stack [0];
	stack[0] = stack[1];
	stack[1] = tmp;
}

void sa(int *a, int size_a)
{
	swap(a, size_a);
	ft_printf("sa\n");
}

void sb(int *b, int size_b)
{
	swap(b, size_b);
	ft_printf("sb\n");
}

void ss(int *a, int *b, int size_a, int size_b)
{
	swap(a, size_a);
	swap(b, size_b);
	ft_printf("ss\n");
}


// Pousser un élément entre les piles, push.c
void push(int *dest, int *size_dest, int *src, int *size_src)
{
	int i; //index qui se balade

	if (!(*size_src)) // si c est nul ca sort car src vide r a copie
		return;
   else
    {
        (*size_dest) += 1;//augmente la taile de dest de 1
        int i = *size_dest - 1;
        while (i > 0) //libere dest[0]
        {
            dest[i] = dest[i - 1];
            i--;
        }
        dest[0] = src[0]; //remplace dest 0
        i = 0;
        while (i < *size_src) //remonte 
        {
            src[i] = src[i + 1];
            i++;
        }
        (*size_src) -= 1; //diminue la taille de src de 1 car src est parti ds dest
    }
}

void pa(int *a, int *size_a, int *b, int *size_b)
{
    push(a, size_a, b, size_b);
	ft_printf("pa\n");
}

void pb(int *a, int *size_a, int *b, int *size_b)
{
    push(b, size_b, a, size_a);
	ft_printf("pb\n");
}

// Faire pivoter les éléments, r.c
void rotate(int *stack, int size)
{
    if (size < 2)
        return;
    int tmp = stack[0];
    int i = 0;
    while (i < size - 1)
    {
        stack[i] = stack[i + 1];
        i++;
    }
    stack[size - 1] = tmp;
}

void ra(int *stack, int size)
{
    rotate(stack, size);
	printf("ra\n");
}

void rb(int *stack, int size)
{
    rotate(stack, size);
	printf("rb\n");
}

void rr(int *a, int size_a, int *b, int size_b)
{
    rotate(a, size_a);
    rotate(b, size_b);
	printf("rr\n");
}

// reverse pivotage, rr.c
void reverse_rotate(int *stack, int size)
{
    if (size < 2)
        return;
    int tmp = stack[size - 1];
    int i = size - 1;
    while (i > 0)
    {
        stack[i] = stack[i - 1];
        i--;
    }
    stack[0] = tmp;
}

void rra(int *stack, int size)
{
    reverse_rotate(stack, size);
	printf("rra\n");
}

void rrb(int *stack, int size)
{
    reverse_rotate(stack, size);
	printf("rrb\n");
}

void rrr(int *a, int size_a, int *b, int size_b)
{
    reverse_rotate(a, size_a);
    reverse_rotate(b, size_b);
	printf("rrr\n");
}

