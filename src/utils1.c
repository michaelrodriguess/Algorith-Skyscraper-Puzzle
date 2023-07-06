/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microdri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 18:54:58 by microdri          #+#    #+#             */
/*   Updated: 2023/07/06 19:50:13 by microdri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dot.h"

int	ft_atoi(char *str)
{
	size_t	i;
	size_t	signal;
	size_t	ret;

	ret = 0;
	i = 0;
	signal = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signal *= -1;
		i++;
	}
	while (ft_isnum(str[i]))
	{
		ret = ret * 10 + str[i] - '0';
		i++;
	}
	return (ret * signal);
}

void ft_putstr_fd(char *str, int fd)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i] != '\0')
	{
		write (fd, &str[i], 1);
		i++;
	}
}

int		ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

