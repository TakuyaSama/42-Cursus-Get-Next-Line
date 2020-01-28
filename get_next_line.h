/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-lo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 12:52:28 by adiaz-lo          #+#    #+#             */
/*   Updated: 2020/01/27 09:49:38 by adiaz-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int		get_next_line(int fd, char **line);
void	ft_putstr(char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char    *ft_strdup(const char *s);


#endif
