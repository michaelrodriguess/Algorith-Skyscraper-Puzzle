/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microdri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 19:49:45 by microdri          #+#    #+#             */
/*   Updated: 2023/07/07 17:25:20 by microdri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOT_H
# define DOT_H

# include <unistd.h>
# include <stdlib.h>

void	clear_memory(char **nbrs);
void	ft_bzero(void *s, size_t n);
void	ft_putstr_fd(char *str, int fd);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_substr(char const *s, unsigned int start, int len);
char	**ft_split(char const *s, char c);
int		ft_isnum(int c);
int		ft_atoi(char *str);
int		ft_isspace(int c);
int 	ft_strlen(const char *str);
int		verify_only_num(char **nbrs);
int		count_numbers(char **nbrs);
void	mount_array(char **nbrs, int *number);

#endif /* DOT_H */
