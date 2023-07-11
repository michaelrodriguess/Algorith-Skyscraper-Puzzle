/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microdri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 17:05:06 by microdri          #+#    #+#             */
/*   Updated: 2023/07/11 18:00:08 by microdri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dot.h"

int	validations_line(int *mtrz_r, int *vision_l, int *vision_r, int line)
{
	int	i;
	int	temp;
	int	size_vision_l;
	int	size_vision_r;

	i = 0;
	size_vision_l = 1;
	size_vision_r = 1;
	temp = mtrz_r[i];
	while (i < 4)
	{
		i++;
		if (i != 4 && temp < mtrz_r[i])
		{
			temp = mtrz_r[i];
			size_vision_l++;
		}
	}
	i--;
	temp = mtrz_r[i];
	while (i > 0)
	{
		i--;
		if (temp < mtrz_r[i])
		{
			temp = mtrz_r[i];
			size_vision_r++;
		}
	}
	if (size_vision_l != vision_l[line] || size_vision_r != vision_r[line])
		return (0);
	return(1);
}

int validations_col(int **mtrz_r, int *vision_up, int *vision_dw, int col)
{
	int i;
	int tmp;
	int size_vision_up;
	int size_vision_dw;

	i = 0;
	size_vision_up = 1;
	size_vision_dw = 1;
	tmp = mtrz_r[i][col];
	while (i < 4)
	{
		i++;
		if (i != 4 && tmp < mtrz_r[i][col])
		{	
			tmp = mtrz_r[i][col];
			size_vision_up++;
		}
	}
	i--;
	tmp = mtrz_r[i][col];
	while (i > 0)
	{
		i--;
		if (tmp < mtrz_r[i][col])
		{
			tmp = mtrz_r[i][col];
			size_vision_dw++;
		}
	}
	if (size_vision_up != vision_up[col] || size_vision_dw != vision_dw[col])
		return (0);
	return(1);
}


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
		{
			matriz_checker[i][j] = array_int[k];
			j++;
			k++;
		}
		i++;
	}
}

int gen_combinations(int temp[], int pos, int combinatio[24][4], int *line)
{
	int i;
	int j;
	int valid;

	j = 0;
    if (pos == 4) 
	{
		i = -1;
		while (++i < 4)
			combinatio[*line][i] = temp[i];
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
        if (valid == 1)
		{
            temp[pos] = i;
            gen_combinations(temp, pos + 1, combinatio, line);
            temp[pos] = 0;
        }
		i++;
    }
    return (0);
}

void init_gen(int combinations[24][4])
{
	int	line = 0;
	int	temp[4] = {0};
	
	gen_combinations(temp, 0, combinations, &line);
}

