/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microdri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 18:12:35 by microdri          #+#    #+#             */
/*   Updated: 2023/07/06 14:47:51 by microdri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/dot.h"

int main (int argc, char **argv)
{
	int i;
	int j;
	int number;

	if (argc != 17)
	{
		ft_putstr_fd("Error: wrong arguments!", 2);
		return (0);
	}
	i = 1;
	j = 0;
	number = 0;
	while (argv[i][j] != '\0')
	{
		j = 0;
		while (argv[i][j] != '\0')
		{	
			if (ft_isnum(argv[i][j]) == 0)
			{
				ft_putstr_fd("Error: only number on arguments!\n", 2);
				return (0);
			}
			number = ft_atoi(&argv[i][j]);
			j++;
		}
		i++;
	}
}
