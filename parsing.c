/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleichtn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 11:45:03 by lleichtn          #+#    #+#             */
/*   Updated: 2025/01/10 11:45:09 by lleichtn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parse_int(const char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (write(2, "Error\n", 6), NULL);
		result = result * 10 + (*str - '0');
		if (result * sign < INT_MIN || result * sign > INT_MAX)
			return (NULL);
		str++;
	}
	return (result * sign);
}

int	has_duplicates(int *array, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i] == array[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	count_tokens(const char *buffer)
{
	int	count;
	int	in_token;

	count = 0;
	in_token = 0;
	while (*buffer)
	{
		if (*buffer == ' ' || *buffer == '\n')
			in_token = 0;
		else if (!in_token)
		{
			in_token = 1;
			count++;
		}
		buffer++;
	}
	return (count);
}

int	parse_tokens(int *numbers, char *buffer, int *size)
{
	char	*token;
	char	*end;
	int		num;

	token = buffer;
	*size = 0;
	while (*token)
	{
		while (*token == ' ' || *token == '\n')
			token++;
		if (!*token)
			break ;
		end = token;
		while (*end && *end != ' ' && *end != '\n')
			end++;
		*end = '\0';
		num = parse_int(token);
		if (num == INT_MAX)
			return (0);
		numbers[*size] = num;
		(*size)++;
		token = end + 1;
	}
	return (1);
}

int	*parse_file(const char *filename, int *size)
{
	int		fd;
	int		bytes_read;
	int		token_count;
	char	buffer[4096];
	int		*numbers;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (write(2, "Error\n", 6), NULL);
	bytes_read = read(fd, buffer, sizeof(buffer) - 1);
	close(fd);
	if (bytes_read <= 0)
		return (write(2, "Error\n", 6), NULL);
	buffer[bytes_read] = '\0';
	token_count = count_tokens(buffer);
	numbers = malloc(token_count * sizeof(int));
	if (!numbers)
		return (write(2, "Error\n", 6), NULL);
	if (!parse_tokens(numbers, buffer, size) || has_duplicates(numbers, *size))
		return (free(numbers), write(2, "Error\n", 6), NULL);
	return (numbers);
}
