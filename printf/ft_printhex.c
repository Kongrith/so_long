/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomasat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 18:52:08 by kkomasat          #+#    #+#             */
/*   Updated: 2024/01/07 18:52:14 by kkomasat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhex(unsigned int dec, const char format)
{
	int		length;
	int		i;
	int		digit;
	char	*hex;

	if (dec == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	length = 0;
	digit = count_uint_digit(dec, 16);
	hex = dec2hex(dec, digit, format);
	i = 0;
	while (i < digit)
	{
		if (hex[i] != '\0')
		{
			write(1, &hex[i], 1);
			length++;
		}
		++i;
	}
	free(hex);
	return (length);
}
