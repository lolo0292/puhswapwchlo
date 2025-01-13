#include "push_swap.h"

 int parse_int(const char *str, int *error)
{
    int num;
    int sign;

    num = 0;
    sign = 1;
    *error = 0;
    if (*str == '-')
    {
        sign = -1;
        str++;
    }
    else if (*str == '+')
    {
        str++;
    }
    while (*str)
    {
        if (*str < '0' || *str > '9')
        {
            *error = 1;
            return (0);
        }
        num = num * 10 + (*str - '0');
        if ((sign == 1 && num > INT_MAX) || (sign == -1 && -num < INT_MIN))
        {
            *error = 1;
            return (0);
        }
        str++;
    }
    return (num * sign);
}

 int has_duplicates(int *array, int size, int value)
{
    int i;

    i = 0;
    while (i < size)
    {
        if (array[i] == value)
        {
            return (1);
        }
        i++;
    }
    return (0);
}

int parse_arguments(int argc, char **argv, int *array, int *size)
{
    int i;
    int error;
    int value;

    if (argc < 2)
    {
        return (write(2, "Error2\n", 10), 0);
    }
    *size = 0;
    i = 1;
    while (i < argc)
    {
        if (!argv[i] || !*argv[i])
        {
            return (write(2, "Error\n", 10), 0);
        }
        error = 0;
        value = parse_int(argv[i], &error);
        if (error || has_duplicates(array, *size, value))
        {
            return (write(2, "Error\n", 6), 0);
        }
        array[*size] = value;
        (*size)++;
        i++;
    }
    if (*size == 0)
    {
        return (write(2, "Error\n", 10), 0);
    }
    return (1);
}
