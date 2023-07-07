/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microdri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 18:21:32 by microdri          #+#    #+#             */
/*   Updated: 2023/07/07 17:40:35 by microdri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dot.h"

int	ft_isnum(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	ft_isspace(int c)
{
	if ((c == '\f') || (c == '\n') || (c == '\r') || (c == '\t')
		|| (c == '\v') || (c == ' '))
		return (1);
	return (0);
}

// verify if have only number and count nbrs
int verify_only_num(char **nbrs)
{
	int i;
	int j;

	i = 0;
	while (nbrs[i] != NULL)
	{
		j = 0;
		while(nbrs[i][j] != '\0')
		{
			if (ft_isnum(nbrs[i][j]) == 0)
			{
				ft_putstr_fd("Error: can have only number on parameters\n", 2);
				return (0);
			}
			j++;
		}
	//	ft_putstr_fd(nbrs[i], 1);
	//	ft_putstr_fd(" ", 1);
		i++;
	}
	return (1);
}

int count_numbers(char **nbrs)
{
	int i;
	int count;

	i = 0;
	count = 0;
	if (!nbrs)
		return (0);
	while (nbrs[i] != NULL)
	{
		count += ft_strlen(nbrs[i]);
		i++;
	}
//	printf("\nnumber of how much is count_nbrs: %i\n", count);
	return (count);
}

