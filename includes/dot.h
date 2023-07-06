/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microdri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 18:12:47 by microdri          #+#    #+#             */
/*   Updated: 2023/07/06 14:37:18 by microdri         ###   ########.fr       */
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

#endif /* DOT_H */
