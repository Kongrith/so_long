/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomasat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 18:49:55 by kkomasat          #+#    #+#             */
/*   Updated: 2024/01/10 17:42:02 by kkomasat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
// # include "../so_long.h"
# include "../libft/libft.h"

// Mandatory Functions
int		ft_printf(const char *str, ...);
int		ft_printchar(int c);
int		ft_printstr(char *str);
int		ft_printptr(void *ptr);
int		ft_printdec(int d);
int		ft_printuint(unsigned int u);
int		ft_printhex(unsigned int dec, const char format);

// Utility Functions
int		count_dec_digit(int n);
int		count_uint_digit(unsigned int u, int base);
int		count_digit_lu(unsigned long n);
char	*reverse_hex(char *hex, int digit, int i);
char	*dec2hex(unsigned long dec, int digit, const char format);

#endif
