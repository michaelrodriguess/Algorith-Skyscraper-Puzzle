/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microdri <microdri@student.42.rj>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 18:21:12 by microdri          #+#    #+#             */
/*   Updated: 2023/07/11 07:32:30 by pbotelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dot.h"

void mount_matriz_checker(int *array_int, int **matriz_checker)
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
			matriz_checker[i][j++] = array_int[k++];
		i++;
	}
}

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

int generate_combinations(int temp[], int pos, int possible[24][4], int *line) 
{
    if (pos == 4) {
        for (int i = 0; i < 4; i++) {
            possible[*line][i] = temp[i];
        }
	*line += 1;
        return (0);
    }

    for (int i = 1; i <= 4; i++) {
        int valido = 1;
        for (int j = 0; j < pos; j++) {
            if (temp[j] == i) {
                valido = 0;
                break;
            }
        }
        if (valido) {
            temp[pos] = i;
            generate_combinations(temp, pos + 1, possible, line);
            temp[pos] = 0;
        }
    }
    return (0);
}


void init_values(int ret[24][4])
{
	int	line = 0;
	int	temp[4] = {0};
	
	generate_combinations(temp, 0, ret, &line);
}



static void brute_force(int **matriz_r, int **matriz_c, int	combinations[24][4], int i)
{
	int j;
	int	k;
	int	line_cmb;

	j = 0;
	line_cmb = 0;
	(void) matriz_c;
	(void) i;
	while(j < COLUMNS)
	{
		k = 0;
		while (k < 4)
		{
			matriz_r[j][k] =  combinations[line_cmb][k];
			k++;
		}
		if (!validations_line(matriz_r[j], matriz_c[0], matriz_c[1])
			line_cmb += 1;
		else
			j++;
	}
}

void do_algo(int **matriz_r, int **matriz_c, int ret[24][4])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	print_rules(matriz_c);
	init_values(ret);
	printf("\n");
	while(i < ROWS)
	{	
		j = 0;
		printf("   ");
		brute_force(matriz_r, matriz_c, ret, i);
		printf("\n");
		i++;
	}
	printf("\n");
	int	k = 0;
	while (k < 24)
	{
		int	l = 0;
		printf("   ");	
		while (l < 4)
			printf("%d ", ret[k][l++]);
		printf("\n");	
		k++;
	}
}
