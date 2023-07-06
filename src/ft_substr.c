/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parnaldo <parnaldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 16:55:07 by parnaldo          #+#    #+#             */
/*   Updated: 2023/07/06 16:55:13 by parnaldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dot.h"

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
