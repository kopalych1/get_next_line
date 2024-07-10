/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 17:03:45 by akostian          #+#    #+#             */
/*   Updated: 2024/07/10 07:42:29 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

char	*check_and_return(char **result)
{
	size_t		i;
	char		*ret;
	char		*result_cpy;

	result_cpy = *result;
	if (!result_cpy)
		return (NULL);
	i = 0;
	while (i < ft_strlen(result_cpy))
	{
		if (result_cpy[i] == '\n')
		{
			ret = ft_substr(result_cpy, 0, i + 1);
			*result = &result_cpy[i + 1];
			return (ret);
		}
		i++;
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*result = NULL;
	char		*ret;
	int			bytes_read;
	char		buffer[BUFFER_SIZE + 1];

	while (1)
	{
		ret = check_and_return(&result);
		if (ret)
			return (ret);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (!bytes_read)
		{
			ret = result;
			result = NULL;
			return (ret);
		}
		buffer[bytes_read] = '\0';
		result = ft_strjoin(result, buffer);
		if (!result)
			return (NULL);
	}
}

/* 
Should I have used this, to join strings?
void	append_buffer(char **src, char (*buffer)[BUFFER_SIZE + 1])
{
	char	*old_src;

	old_src = *src;
	*src = ft_strjoin(*src, *buffer);
	if (old_src)
		free(old_src);
} */