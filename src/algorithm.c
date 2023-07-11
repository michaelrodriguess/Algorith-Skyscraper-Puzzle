/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microdri <microdri@student.42.rj>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 18:21:12 by microdri          #+#    #+#             */
/*   Updated: 2023/07/11 18:18:23 by microdri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dot.h"

static void print_rules(int **matriz_c)
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
void make_line(int **mtrz_r, int **mtrz_c, int combinations[24][4])
{
	int i;
	int	j;
	int	line_cmb;

	i = 0;
	line_cmb = 0;
	while(i < COLUMNS)
	{
		j = 0;
		while (j < 4)
		{
			mtrz_r[i][j] = combinations[line_cmb][j];
			j++;
		}
		if (!validations_line(mtrz_r[i], mtrz_c[2], mtrz_c[3], i))
			line_cmb += 1;
		else
		{
			line_cmb = 0;
			i++;
		}
	}
}

void make_col(int **mtrz_r, int **mtrz_c, int combinations[24][4])
{
	int i;
	int	j;
	int	line_cmb;

	i = 0;
	line_cmb = 0;
	while(i < COLUMNS)
	{
		j = 0;
		while (j < 4)
		{
			mtrz_r[j][i] = combinations[line_cmb][j];
			j++;
		}
		if (!validations_col(mtrz_r, mtrz_c[0], mtrz_c[1], i))
			line_cmb += 1;
		else
		{
			line_cmb = 0;
			i++;
		}
	}
}

void brute_force(int **mtrz_r, int **mtrz_c, int combinations[24][4])
{
	make_line(mtrz_r, mtrz_c, combinations);
	//make_col(mtrz_r, mtrz_c, combinations);
}

void do_algo(int **matriz_r, int **matriz_c, int combinations[24][4])
{
	int	i;
	int	j;

	print_rules(matriz_c);
	init_gen(combinations);
	printf("\n");
	brute_force(matriz_r, matriz_c, combinations);
	printf("\n");
	i = 0;
	j = 0;
	while(i < 4)
	{
		j = 0;
		printf("   ");
		while (j < 4)
			printf("%d ", matriz_r[i][j++]);
		printf("\n");
		i++;
	}
	printf("\n");
	printf("\n");
	int	k = 0;
	while (k < 24)
	{
		int	l = 0;
		printf("   ");	
		while (l < 4)
			printf("%d ", combinations[k][l++]);
		printf("\n");	
		k++;
	}
}
