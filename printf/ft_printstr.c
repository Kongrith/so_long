/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomasat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 18:53:21 by kkomasat          #+#    #+#             */
/*   Updated: 2024/01/07 18:53:24 by kkomasat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printstr(char *str)
{
	int	length;

	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	length = ft_strlen(str);
	write(1, str, length);
	return (length);
}
