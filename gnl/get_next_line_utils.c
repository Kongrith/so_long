/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomasat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 04:35:11 by kkomasat          #+#    #+#             */
/*   Updated: 2024/12/02 16:09:50 by khkomasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (0);
	if (c == '\0')
		return (ft_strdup(s));
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (&s[i]);
		++i;
	}
	return (0);
}

char	*ft_strdup(const char *s1)
{
	char	*dest;
	char	*p;
	int		len;

	len = ft_strlen(s1);
	dest = (char *)malloc((len + 1) * sizeof(char));
	if (dest == NULL)
	{
		free(dest);
		return (NULL);
	}
	p = dest;
	while (*s1)
		*p++ = *s1++;
	*p = '\0';
	return (dest);
}

char	*join_string(char *ptr, char *s1, char *s2)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s1[i] != '\0')
	{
		ptr[i] = s1[i];
		++i;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		ptr[i + j] = s2[j];
		++j;
	}
	ptr[i + j] = '\0';
	return (ptr);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ptr;

	if (!s1 && s2)
	{
		ptr = ft_strdup(s2);
		if (ptr == NULL)
		{
			free(ptr);
			return (NULL);
		}
		else
			return (ptr);
	}
	ptr = (char *)malloc((ft_strlen((char *)s1) + ft_strlen((char *)s2) \
							+ 1) * sizeof(char));
	// ft_printf("after ptr\n");
	if (!ptr)
	{
		free(ptr);
		free(s1);
		return (NULL);
	}
	// ft_printf("after ptr before join_string\n");
	ptr = join_string(ptr, s1, s2);
	// ft_printf("after join_string: %s\n", ptr);
	free(s1);
	return (ptr);
}
