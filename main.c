/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microdri <microdri@student.42.rj>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 14:19:42 by microdri          #+#    #+#             */
/*   Updated: 2023/07/11 14:55:08 by microdri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/dot.h"

int main (int argc, char **argv)
{
	char	**nbrs;
	int	i;
	int	**matriz_checker;
	int	**matriz_result;
	int	matriz_ret[24][4];
	int	number[16];

	i = 0;
	nbrs = ft_split(argv[1], ' ');
	matriz_checker = (int **)malloc(4 * sizeof(int *));
	matriz_result = (int **)malloc(4 * sizeof(int *));
   	while (i < 4)
	{
		matriz_checker[i] = (int *)malloc(4 * sizeof(int));
		matriz_result[i] = (int *)malloc(4 * sizeof(int));
	    i++;
	}
	i = 0;
	if (argc == 2)
	{
		if (validate_arguments(nbrs, number) == 0)
		{
			ft_putstr_fd("Error: Impossible create table!\n", 2);
			return (0);
		}
		mount_matriz_checker(number, matriz_checker);
		do_algo(matriz_result, matriz_checker, matriz_ret);
	}
	else
		ft_putstr_fd("Error: wrong paraments\n", 2);
	clear_memory(nbrs);
	return (0);
}
