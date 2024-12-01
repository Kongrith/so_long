/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toon <toon@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 22:19:14 by kkomasat          #+#    #+#             */
/*   Updated: 2024/12/02 05:23:32 by khkomasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* strncmp
 *  compare two string with specific block.
 *
 */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while ((s1[i] == s2[i]) && i < n)
	{
		if (s1[i] == '\0')
			return (0);
		++i;
	}
	if (i == n)
		return (0);
	return (((unsigned char)s1[i] - (unsigned char)s2[i]));
}
/*
int	main(void)
{
	char	str1[] = "abc";
	char	str2[] = "abb";
	char    str3[] = "abb";
	char    str4[] = "abc";
	char    str5[] = "abb";
	char    str6[] = "abb";
	printf("case0: zero block\n");
	printf("strncmp   :%d\n", strncmp(str1, str2, 0));
	printf("ft_strncmp:%d\n", ft_strncmp(str1, str2, 0));
	printf("case1: greater\n");
	printf("strncmp   :%d\n", strncmp(str1, str2, 3));
	printf("ft_strncmp:%d\n", ft_strncmp(str1, str2, 3));
	printf("case2: less than\n");
	printf("strncmp   :%d\n", strncmp(str3, str4, 3));
	printf("ft_strncmp:%d\n", ft_strncmp(str3, str4, 3));
	printf("case3: equal\n");
	printf("strncmp   :%d\n", strncmp(str5, str6, 3));
	printf("ft_strncmp:%d\n", ft_strncmp(str5, str6, 3));
	return (0);
}*/
