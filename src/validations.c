/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microdri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 18:21:32 by microdri          #+#    #+#             */
/*   Updated: 2023/07/09 05:34:08 by microdri         ###   ########.fr       */
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
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

#include <stdio.h>
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
//	if (count == 16)
//		printf("number of how much is count_nbrs: %i\n", count);
	return (count);
}

int validate_arguments(char **nbrs, int *number)
{

	if (verify_only_num(nbrs) == 1)
	{
		if (count_numbers(nbrs) == 16)
		{
			if (mount_array(nbrs, number) != 0)
				return (1);
		}
	}
	clear_memory(nbrs);
	return (0);
}
