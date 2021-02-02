/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-lo <adiaz-lo@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 13:37:53 by adiaz-lo          #+#    #+#             */
/*   Updated: 2021/02/01 16:47:40 by adiaz-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	int		i;
	int		BUFFER_SIZE = 8;
	char		*buf[BUFFER_SIZE + 1];
	static char	*aux;
	char		*aux2;
	char		*tmp;
	char		*tmp2;

	if (!line)
		return (-1);
	while (i = read(fd, buf, BUFFER_SIZE) > 0)
	{
		buf[i] = '\0';
		if (!aux)
			aux = ft_strdup(buf);
		else
		{
			aux2 = ft_strjoin(aux, buf);
			free(aux);
			aux = aux2;
		}
		if (ft_strchr(aux, '\n'))
			break;
	}
	if (i == -1)
		return (i);
	if (i == 0 && !aux)
	{
		aux = ft_strdup("");
		return (i);
	}
	if (tmp = ft_strchr(aux, '\n'))
	{
		*tmp = 0;
		*line = ft_strdup(aux);
		tmp2 = ft_strdup(++tmp);
		free(aux);
		aux = tmp2;
		return (1);
	}
	else if (tmp = ft_strchr(aux, '\0'))
	{
		*line = ft_strdup(aux);
		free(aux);
		aux = 0;
		return (0);
	}
}
