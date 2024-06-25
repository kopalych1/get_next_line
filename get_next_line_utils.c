/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 17:03:44 by akostian          #+#    #+#             */
/*   Updated: 2024/06/25 13:11:19 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	length;

	if (!s)
		return (0);
	length = 0;
	while (*s++)
		length++;
	return (length);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	const size_t	joined_len = ft_strlen(s1) + ft_strlen(s2);
	char			*ret;
	size_t			i;

	ret = malloc(sizeof(char) * (joined_len + 1));
	if (!ret)
		return (NULL);
	i = 0;
	if (s1)
		while (*s1)
			ret[i++] = *s1++;
	if (s2)
		while (*s2)
			ret[i++] = *s2++;
	ret[i] = '\0';
	return (ret);
}

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	unsigned char	*dst_cpy;
	unsigned char	*src_cpy;

	dst_cpy = (unsigned char *)dst;
	src_cpy = (unsigned char *)src;
	while (n-- > 0)
		*dst_cpy++ = *src_cpy++;
	return (dst);
}

char	*ft_strdup(const char *s1)
{
	char			*copy;
	const size_t	src_len = ft_strlen(s1);

	copy = malloc(sizeof(char) * (src_len + 1));
	if (!copy)
		return (0);
	return (ft_memcpy(copy, (char *)s1, src_len + 1));
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	const size_t	s_len = ft_strlen(s);
	char			*ret;
	size_t			i;

	if (start + len <= s_len)
		ret = malloc(sizeof(char) * (len + 1));
	else
	{
		if (start >= s_len)
			return (ft_strdup(""));
		ret = malloc(sizeof(char) * (s_len - start + 1));
	}
	if (!ret)
		return (NULL);
	i = 0;
	while (s[start + i] && i < len)
	{
		ret[i] = s[start + i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
