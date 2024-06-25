/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 17:05:59 by akostian          #+#    #+#             */
/*   Updated: 2024/06/25 16:49:45 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
# include <unistd.h>

void	ft_putchar(int c)
{
	write(1, &c, 1);
}

void	ft_putstr2(char *str)
{
	while (*str)
	{
		if (*str == '\n')
		{
			ft_putstr2("\033[1;33m\\10\033[0m");
		}
		else
			ft_putchar(*str);
		str++;
	}
}

int	main(void)
{
	int		fd = open("test.txt", O_RDONLY | O_CREAT);
	char	*str;

	while (str = get_next_line(fd))
	{
		ft_putstr2("[GNL]:\t\t'");
		ft_putstr2(str);
		ft_putstr2("'");
		ft_putchar('\n');
	}
	str = get_next_line(fd);
	ft_putstr2("[GNL]:\t\t'");
	if (str)
		ft_putstr2(str);
	else
		ft_putstr2("NULL");
	ft_putstr2("'");
	ft_putchar('\n');
}
