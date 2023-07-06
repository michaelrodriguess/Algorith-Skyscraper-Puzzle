/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parnaldo <parnaldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 18:12:47 by microdri          #+#    #+#             */
/*   Updated: 2023/07/06 16:58:04 by parnaldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOT_H
# define DOT_H

# include <unistd.h>
# include <stdlib.h>

int		ft_isnum(int c);
int		ft_atoi(char *str);
int		ft_isspace(int c);
void	ft_putstr_fd(char *str, int fd);

char	*ft_substr(char const *s, unsigned int start, int len);
void	*ft_calloc(size_t nmemb, size_t size);
char	**ft_split(char const *s, char c);
void	ft_bzero(void *s, size_t n);
int 	ft_strlen(const char *str);

#endif /* DOT_H */
