/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parnaldo <parnaldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 18:12:35 by microdri          #+#    #+#             */
/*   Updated: 2023/07/06 16:01:12 by parnaldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/dot.h"
#include <stdio.h>

int validate_arguments(char *str)
{
	char **nbrs;
	int i;

	i = 0;
	nbrs = ft_split(str, ' ');
	while (nbrs != NULL)
	{
		printf("%s", nbrs[i]);
		i++;
	}
	return (1);
}

int main (int argc, char **argv)
{
	if (argc == 2)
	{
		printf("%s ", argv[1]);
	}
	return (0);
}
