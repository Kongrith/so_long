/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilities.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomasat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 18:53:52 by kkomasat          #+#    #+#             */
/*   Updated: 2024/01/07 18:53:55 by kkomasat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_dec_digit(int n)
{
	int	digit;
	int	num;

	digit = 0;
	num = n;
	if (n < 0)
	{
		n = n * -1;
		digit++;
	}
	else if (n == 0)
		return (1);
	while (num != 0)
	{
		digit += 1;
		num /= 10;
	}
	return (digit);
}

int	count_digit_lu(unsigned long n)
{
	int				digit;
	unsigned long	num;

	digit = 0;
	num = n;
	if (n == 0)
		return (1);
	while (num != 0)
	{
		digit += 1;
		num /= 16;
	}
	return (digit);
}

int	count_uint_digit(unsigned int u, int base)
{
	int				digit;
	unsigned int	num;

	digit = 0;
	num = u;
	if (u == 0)
		return (1);
	while (num != 0)
	{
		digit += 1;
		num /= base;
	}
	return (digit);
}

char	*reverse_hex(char *hex, int digit, int i)
{
	int	start;
	int	end;
	int	tmp;

	hex[i] = '\0';
	start = 0;
	end = digit - 1;
	while (start < end)
	{
		tmp = hex[start];
		hex[start] = hex[end];
		hex[end] = tmp;
		start++;
		end--;
	}
	return (hex);
}

char	*dec2hex(unsigned long dec, int digit, const char format)
{
	int		i;
	int		remainder;
	char	*hex;

	hex = (char *)malloc((digit + 1) * sizeof(char));
	if (!hex)
		return (NULL);
	i = 0;
	while (dec != 0)
	{
		remainder = dec % 16;
		if (remainder < 10)
			remainder += '0';
		else
		{
			if ((format == 'x') || (format == 'p'))
				remainder += 'W';
			else
				remainder += '7';
		}
		hex[i++] = remainder;
		dec /= 16;
	}
	hex = reverse_hex(hex, digit, i);
	return (hex);
}
