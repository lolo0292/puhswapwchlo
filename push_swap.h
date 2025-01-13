/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleichtn <lleichtn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:05:41 by lleichtn          #+#    #+#             */
/*   Updated: 2025/01/13 15:45:04 by lleichtn         ###   ########.fr       */
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


typedef struct s_stack
{
    int *array;
    int size;
} t_stack;


// Sorting algorithms
void sort_small(t_stack *a, t_stack *b);
void radix_sort(t_stack *a, t_stack *b);
// void sort(int argc, char **argv);

// Utility functions
void error_exit(void);
int is_sorted(t_stack *stack);
t_stack init_stack(int size);
void free_stack(t_stack *stack);


// Prototypes de parsing.c
#include "push_swap.h"
int parse_int(const char *str, int *error);
int has_duplicates(int *array, int size, int value);
int parse_arguments(int argc, char **argv, int *array, int *size);

// int parse_int(const char *str, int *is_error);
// int has_duplicates(int *array, int size);
// int count_tokens(const char *buffer);
// int parse_tokens(int *numbers, char *buffer, int *size);
// int *parse_file(const char *filename, int *size);

// Prototypes d'operation.c
void swap(t_stack *stack);
void push(t_stack *src, t_stack *dest);
void rotate(t_stack *stack);
void reverse_rotate(t_stack *stack);
void sa(t_stack *a);
void sb(t_stack *b);
void ss(t_stack *a, t_stack *b);
void pa(t_stack *a, t_stack *b);
void pb(t_stack *a, t_stack *b);
void rra(t_stack *a);
void rrb(t_stack *b);
void rrr(t_stack *a, t_stack *b);
void ra(t_stack *a);
void rb(t_stack *b);
void rr(t_stack *a, t_stack *b);

int count_steps(t_stack *a, t_stack *b);

#endif