/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parnaldo <parnaldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 18:12:35 by microdri          #+#    #+#             */
/*   Updated: 2023/07/06 20:01:49 by microdri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/dot.h"
#include <stdio.h>

int validate_arguments(char *str)
{
	char **nbrs;
	int *number;
	int count_nbrs;
	int i;
	int j;

	i = 0;
	j = 0;
	count_nbrs = 0;
	number = NULL;
	nbrs = ft_split(str, ' ');
	// verify if have only number and count nbrs
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
		count_nbrs += ft_strlen(nbrs[i]);
	//	printf("\nnumber of how much is count_nbrs: %i\n", count_nbrs);
	//	ft_putstr_fd(nbrs[i], 1);
	//	ft_putstr_fd(" ", 1);
		i++;
	}
	// verify count nbrs and  mount matriz
	i = 0;
	j = 0;
	if ( count_nbrs == 16 )
	{
		number = malloc(count_nbrs * sizeof(int));
		if(!number)
			return (0);
		while(nbrs[i] != NULL)
		{
			number[i] = ft_atoi(nbrs[i]);
			//printf("number is -> %i\n", number[i]);
			i++;
		}
	}
	else
		ft_putstr_fd("Error: missing arguments, impossible to create the table.\n", 2);
	return (1);
}

int main (int argc, char **argv)
{
	if (argc == 2)
	{
		validate_arguments(argv[1]);
	}
	else
		ft_putstr_fd("Error: wrong paraments\n", 2);
	return (0);
}
