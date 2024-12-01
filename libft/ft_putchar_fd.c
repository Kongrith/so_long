/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toon <toon@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 23:08:11 by kkomasat          #+#    #+#             */
/*   Updated: 2024/12/02 05:22:46 by khkomasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 	ft_putchar_fd
 *	write character c on a specified file descriptor
 *
 *	write(fd, buffer, nbytes)
 */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/*
int	main()
{
	char s[] = "abcd";
	ft_putchar_fd(s[0], 1);
	return(0);
}*/
