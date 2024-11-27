/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printuint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomasat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 18:54:27 by kkomasat          #+#    #+#             */
/*   Updated: 2024/01/07 18:54:31 by kkomasat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_uint(unsigned int u)
{
	int	fd;

	fd = 1;
	if (u >= 10)
	{
		print_uint(u / 10);
		ft_putchar_fd(u % 10 + '0', fd);
	}
	else
		ft_putchar_fd(u + '0', fd);
}

int	ft_printuint(unsigned int u)
{
	int	length;

	length = count_uint_digit(u, 10);
	print_uint(u);
	return (length);
}
