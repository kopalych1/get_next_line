/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 17:03:45 by akostian          #+#    #+#             */
/*   Updated: 2024/06/25 16:48:39 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif

void	move_buffer(char *buffer)
{
	int	i;
	int	j;

	j = 0;
	while (j < BUFFER_SIZE && !((buffer[j] < 1) || (buffer[j] == '\n')))
		j++;
	i = 0;
	while (++j < BUFFER_SIZE)
		buffer[i++] = buffer[j];
	while (i < (BUFFER_SIZE + 1))
		buffer[i++] = 0;
}

// Checks buffer, and rewrites result
void	check_buffer(char *buffer, char **result)
{
	size_t	i;
	char	is_nl;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		is_nl = buffer[i] == '\n';
		if ((buffer[i] <= 0) || is_nl)
		{
			*result = ft_strjoin(*result, ft_substr(buffer, 0, i + is_nl));
			move_buffer(buffer);
			return ;
		}
		i++;
	}
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*result;
	size_t		buffer_length;

	result = NULL;
	while (1)
	{
		buffer_length = ft_strlen(buffer);
		if (buffer_length < BUFFER_SIZE)
			read(fd, buffer + buffer_length, BUFFER_SIZE - buffer_length);
		if (!ft_strlen(buffer))
			return (NULL);
		check_buffer(buffer, &result);
		if (result)
			return (result);
		result = ft_strjoin(result, buffer);
		if (!result)
			return (NULL);
		move_buffer(buffer);
	}
}
