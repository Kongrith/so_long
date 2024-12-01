#ifndef LIBFT_H
# define LIBFT_H
// # include "../so_long.h"
# include <unistd.h>
# include <stdlib.h>

// functions from string.h
size_t ft_strlen(const char *s);
char *ft_strrchr(const char *s, int c);
int ft_strncmp(const char *s1, const char *s2, size_t n);

// custom functions from 42bangkok
void ft_putchar_fd(char c, int fd);
void ft_putstr_fd(char *s, int fd);
void ft_putnbr_fd(int n, int fd);

#endif
