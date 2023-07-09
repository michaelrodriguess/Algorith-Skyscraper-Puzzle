/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microdri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 19:51:25 by microdri          #+#    #+#             */
/*   Updated: 2023/07/09 05:34:35 by microdri         ###   ########.fr       */
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

char	*ft_substr(char const *s, unsigned int start, int len)
{
	char	*dst;
	int		i;
	int		j;

	if (len > ft_strlen(s))
		len = ft_strlen(s);
	dst = (char *) malloc(sizeof(char) * (len + 1));
	if (dst == NULL)
		return (NULL);
	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= (int)start && j < len)
		{
			dst[j] = s[i];
			j++;
		}
		i++;
	}
	dst[j] = '\0';
	return (dst);
}

int mount_array(char **nbrs, int *number)
{
	int i;

	i = 0;
	while(nbrs[i] != NULL)
	{
		number[i] = ft_atoi(nbrs[i]);
		if (number[i] < 1 || number[i] > 4)
			return (0);
		i++;
	}
	return (1);
}
