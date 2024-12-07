/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printdec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomasat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 18:48:09 by kkomasat          #+#    #+#             */
/*   Updated: 2024/01/07 18:48:16 by kkomasat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printdec(int n)
{
	int	length;

	length = 0;
	length = count_dec_digit(n);
	ft_putnbr_fd(n, 1);
	return (length);
}
