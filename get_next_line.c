/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 17:03:45 by akostian          #+#    #+#             */
/*   Updated: 2024/07/04 03:12:36 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

char	*ft_strchr(const char *s, int c)
{
	while (1)
	{
		if (*s == c)
			return ((char *)s);
		if (!*s)
			return (NULL);
		s++;
	}
}

char	*check_and_return(char **result)
{
	size_t		i;
	char		*ret;
	char		*str;

	str = *result;
	i = 0;
	while (i < ft_strlen(str))
	{
		if (str[i] == '\n')
		{
			ret = ft_substr(str, 0, i + 1);
			*result = &str[i + 1];
			return (ret);
		}
		i++;
	}
	return (NULL);
}

void	clear_buffer(char *buffer)
{
	size_t	i;

	i = 0;
	while (buffer[i])
		buffer[i++] = 0;
}

char	*get_next_line(int fd)
{
	static char	*result;
	char		*ret;
	int			bytes_read;
	char		buffer[BUFFER_SIZE + 1];

	while (1)
	{
		clear_buffer(buffer);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (!bytes_read)
		{
			if (!ft_strchr(result, '\n'))
				break ;
			ret = result;
			result = NULL;
			return (ret);
		}
		result = ft_strjoin(result, buffer);
		if (!result)
			return (NULL);
		ret = check_and_return(&result);
		if (ret)
			return (ret);
	}
}
