/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toon <toon@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 23:14:21 by kkomasat          #+#    #+#             */
/*   Updated: 2024/11/27 12:49:16 by toon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(-n, fd);
	}
	else if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(n % 10 + '0', fd);
	}
	else
		ft_putchar_fd(n + '0', fd);
}
/*
int	main()
{
	int	a = 123;
	int b = -123;
	int c = -2147483648;
	int d = -0;

	ft_putnbr_fd(a, 1);
	write(1, "\n", 1);
	ft_putnbr_fd(b, 1);
	write(1, "\n", 1);
	ft_putnbr_fd(c, 1);
	write(1, "\n", 1);
	ft_putnbr_fd(d, 1);
	write(1, "\n", 1);
	return(0);
}*/
