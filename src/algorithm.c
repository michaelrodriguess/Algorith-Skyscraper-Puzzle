/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microdri <microdri@student.42.rj>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 18:21:12 by microdri          #+#    #+#             */
/*   Updated: 2023/07/10 17:09:54 by microdri         ###   ########.fr       */
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

static void print_rules(int matriz_c[ROWS][COLUMNS])
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < ROWS)
	{
		if (i == 0)
		{
			printf("   %i %i %i %i ", matriz_c[i][j], matriz_c[i][j + 1], matriz_c[i][j + 2], matriz_c[i][j + 3]);	
			printf("\n");
		}
		if (i == 2)
		{
			printf("  %i       %i\n  %i       %i\n  %i       %i\n  %i       %i\n", matriz_c[i][j], matriz_c[i + 1][j], matriz_c[i][j + 1], matriz_c[i + 1][j + 1],  matriz_c[i][j + 2], matriz_c[i + 1][j + 2], matriz_c[i][j + 3], matriz_c[i + 1][j + 3]);
		}
		if (i == 3)
		{
			printf("   %i %i %i %i ", matriz_c[1][j], matriz_c[1][j + 1], matriz_c[1][j + 2], matriz_c[1][j + 3]);	
			printf("\n");
		}
		i++;	
	}
}

static void brute_force(int matriz_r[ROWS][COLUMNS], int matriz_c[ROWS][COLUMNS], int i)
{
	int j;
	int	k;

	j = 0;
	while(j < COLUMNS)
	{
		k = 0;
		while (k < j)
		{
			k++;
			if (matriz_r[i][j] == matriz_r[i][k])

		}
		if (matriz_r[i][j] == matriz_r[i][j + 1])
			matriz_r[i][j] = 2;
		if (matriz_c[i][j] == 4)
			matriz_r[i][j] = 1;
		if (matriz_c[i][j] == 2)
			matriz_r[i][j] = 3;
		if (matriz_c[i][j] == 3)
			matriz_r[i][j] = 4;
		*/
	//	printf("%i ", matriz_r[i][j]);
		j++;
	}
}

void do_algo(int matriz_r[ROWS][COLUMNS], int matriz_c[ROWS][COLUMNS])
{
	int i;
	int j;

	i = 0;
	j = 0;
	print_rules(matriz_c);
	printf("\n");
	while(i < ROWS)
	{	
		j = 0;
		printf("   ");
		brute_force(matriz_r, matriz_c, i);
		printf("\n");
		i++;
	}
	printf("\n");
}
