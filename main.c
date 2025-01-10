
#include "push_swap.h"

int main(int argc, char **argv)
{
    t_stack a;
    t_stack b;
    int fd;

    if (argc != 2)
    {
        write(2, "Usage: ./push_swap <file>\n", 27);
        return (1);
    }
    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
    {
        write(2, "Error: Cannot open file\n", 24);
        return (1);
    }
    if (!parse_file(fd, &a))
    {
        write(2, "Error\n", 6);
        close(fd);
        return (1);
    }
    close(fd);
    init_stack(&b);
    push_swap(&a, &b);
    free_stack(&a);
    free_stack(&b);
    return (0);
}
