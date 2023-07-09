/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parnaldo <parnaldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 18:12:35 by microdri          #+#    #+#             */
/*   Updated: 2023/07/08 23:33:08 by microdri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/dot.h"

int main (int argc, char **argv)
{
	if (argc == 2)
	{
		if (validate_arguments(argv[1]) == 0)
			ft_putstr_fd("Error: Impossible create table!\n", 2);
//		do_algorithm();
	}
	else
		ft_putstr_fd("Error: wrong paraments\n", 2);
	return (0);
}
