/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parnaldo <parnaldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 16:04:52 by parnaldo          #+#    #+#             */
/*   Updated: 2023/07/06 16:04:55 by parnaldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dot.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total_m;
	void	*ptr;

	total_m = nmemb * size;
	ptr = malloc(total_m);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, total_m);
	return (ptr);
}
