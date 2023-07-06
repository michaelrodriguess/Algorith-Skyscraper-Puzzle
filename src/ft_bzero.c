/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parnaldo <parnaldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 16:57:45 by parnaldo          #+#    #+#             */
/*   Updated: 2023/07/06 16:57:53 by parnaldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dot.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*clean;
	size_t			index;

	clean = (unsigned char *)s;
	index = 0;
	while (index < n)
	{
		clean[index] = 0;
		index++;
	}
}
