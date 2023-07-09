/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microdri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 18:21:12 by microdri          #+#    #+#             */
/*   Updated: 2023/07/09 15:31:42 by microdri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dot.h"

void mount_matriz_chec(int *array_int, int matriz_chec[ROWS][COLUMNS])
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (i < ROWS)
	{
		j = 0;
		while(j < COLUMNS)
		{
			matriz_chec[i][j] = array_int[k];
//			printf("%i ", matriz_checker[i][j]);
			k++;
			j++;
		}
//		printf("\n");
		i++;
	}
}

void do_algo(int matriz_r[ROWS][COLUMNS], int matriz_c[ROWS][COLUMNS])
//void do_algo(int matriz_r[ROWS][COLUMNS])
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(i < ROWS)
	{
		j = 0;
		while(j < COLUMNS)
		{
			if (matriz_c[i][j] > 0)
				matriz_r[i][j] = 1;
			printf("%i ", matriz_r[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}
