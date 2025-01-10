/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleichtn <lleichtn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:05:41 by lleichtn          #+#    #+#             */
/*   Updated: 2025/01/09 13:02:59 by lleichtn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <limits.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>
#include <fcntl.h>
#include "../printf/ft_printf.h"

typedef struct s_node
{
    int value;
    struct s_node *next;
} t_node;

typedef struct s_stack
{
    int *array;
    int size;
    struct s_stack *next;
} t_stack;

// Prototypes de stacks.c
int     sizeoflist(t_node *list);
void    stackmem(int **a, int **b, int size);
void    filllist(int *a, t_node **list);
void    init_stacks(int **a, int *size_a, int **b, int *size_b, t_node **list_a);

// Prototypes de parsing.c
int     parse_int(const char *str);
int     has_duplicates(int *array, int size);
int     count_tokens(const char *buffer);
int     parse_tokens(int *numbers, char *buffer, int *size);
int     *parse_file(const char *filename, int *size);

// Prototypes d'operation.c
void    swap(int *stack, int size);
void    sa(int *a, int size_a);
void    sb(int *b, int size_b);
void    ss(int *a, int *b, int size_a, int size_b);
void    push(int *dest, int *size_dest, int *src, int *size_src);
void    pa(int *stack_a, int *size_a, int *stack_b, int *size_b);
void    pb(int *stack_a, int *size_a, int *stack_b, int *size_b);
void    rotate(int *stack, int size);
void    ra(int *stack, int size);
void    rb(int *stack, int size);
void    rr(int *stack_a, int size_a, int *stack_b, int size_b);
void    reverse_rotate(int *stack, int size);
void    rra(int *stack, int size);
void    rrb(int *stack, int size);
void    rrr(int *stack_a, int size_a, int *stack_b, int size_b);

// Prototypes de radix.c
int     get_bit(int num, int pos);
int     find_max(t_stack *stack);
int     count_bits(int max);
void    radix_sort(t_stack **stack_a, t_stack **stack_b);

// Prototypes de push_swap.c
void sort_three(t_stack *a, t_stack *b);
void sort_five(t_stack *a, t_stack *b);
void push_swap(t_stack *a, t_stack *b);


#endif