/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microdri <microdri@student.42.rj>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 14:19:42 by microdri          #+#    #+#             */
/*   Updated: 2023/07/10 17:09:55 by microdri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/dot.h"

int main (int argc, char **argv)
{
	char **nbrs;
	int matriz_checker[ROWS][COLUMNS];
	int matriz_result[ROWS][COLUMNS];
	int number[16];

	nbrs = ft_split(argv[1], ' ');
	if (argc == 2)
	{
		if (validate_arguments(nbrs, number) == 0)
		{
			ft_putstr_fd("Error: Impossible create table!\n", 2);
			return (0);
		}
		mount_matriz_chec(number, matriz_checker);
		do_algo(matriz_result, matriz_checker);
//		int i = 0;
//		while(i <= 15)
//		{
//			printf("number is-> %i\n", number[i++]);
//		}
	}
	else
		ft_putstr_fd("Error: wrong paraments\n", 2);
	clear_memory(nbrs);
	return (0);
}
