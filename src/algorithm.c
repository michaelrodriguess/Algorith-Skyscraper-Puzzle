/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microdri <microdri@student.42.rj>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 18:21:12 by microdri          #+#    #+#             */
/*   Updated: 2023/07/11 14:55:07 by microdri         ###   ########.fr       */
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
	int i;
	int j;
	int valid;

	j = 0;
    if (pos == 4) 
	{
		i = 0;
		while (i < 4)
		{
            possible[*line][i] = temp[i];
			i++;
        }
		*line += 1;
        return (0);
    }
	i = 1;
	while(i <= 4)
	{
		valid = 1;
		j = 0;
		while (j < pos)
		{
            if (temp[j] == i) 
			{
                valid = 0;
                break;
            }
			j++;
        }
        if (valid)
		{
            temp[pos] = i;
            generate_combinations(temp, pos + 1, possible, line);
            temp[pos] = 0;
        }
		i++;
    }
    return (0);
}


void init_values(int ret[24][4])
{
	int	line = 0;
	int	temp[4] = {0};
	
	generate_combinations(temp, 0, ret, &line);
}

int	validations_line(int *matriz_r, int	*vision_left, int *vision_rigth, int line)
{
	int	i;
	int	temp;
	int	size_vision_l;
	int	size_vision_r;

	i = 0;
	size_vision_l = 1;
	size_vision_r = 1;
	temp = matriz_r[i];
	while (i < 4)
	{
		i++;
		if (temp < matriz_r[i])
		{
			temp = matriz_r[i];
			size_vision_l++;
		}
	}
	i--;
	temp = matriz_r[i];
	while (i)
	{
		i--;
		if (temp < matriz_r[i])
		{
			temp = matriz_r[i];
			size_vision_r++;
		}
	}
	if (size_vision_l != vision_left[line] || size_vision_r != vision_rigth[line])
		return (0);
	return(1);
}

static void brute_force(int **matriz_r, int **matriz_c, int	combinations[24][4], int i)
{
	int j;
	int	k;
	int	line_cmb;

	j = 0;
	line_cmb = 0;
	(void) i;
	while(j < COLUMNS)
	{
		k = 0;
		while (k < 4)
		{
			matriz_r[j][k] = combinations[line_cmb][k];
			k++;
		}
		if (!validations_line(matriz_r[j], matriz_c[2], matriz_c[3], j))
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
	brute_force(matriz_r, matriz_c, ret, i);
	printf("\n");
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
			printf("%d ", ret[k][l++]);
		printf("\n");	
		k++;
	}
}
