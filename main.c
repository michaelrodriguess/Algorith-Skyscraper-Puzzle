/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parnaldo <parnaldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 18:12:35 by microdri          #+#    #+#             */
/*   Updated: 2023/07/07 17:43:10 by microdri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/dot.h"
#include <stdio.h>

int validate_arguments(char *str)
{
	char **nbrs;
	int number[16];
	int count_nbrs;

	count_nbrs = 0;
	nbrs = ft_split(str, ' ');
	if (verify_only_num(nbrs) == 1)
		count_nbrs = count_numbers(nbrs);
	else			// limpar memoria aqui
	{
		clear_memory(nbrs);
		return (0);
	}
	if ( count_nbrs == 16 )
		mount_array(nbrs, number);	
	else			// limpar memoria aqui?
	{
		clear_memory(nbrs);
		ft_putstr_fd("Error: missing arguments, impossible to create the table.\n", 2);
	}
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
