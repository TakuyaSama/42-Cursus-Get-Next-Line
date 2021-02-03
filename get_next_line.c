/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-lo <adiaz-lo@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 13:37:53 by adiaz-lo          #+#    #+#             */
/*   Updated: 2021/02/03 17:24:03 by adiaz-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
** This function allocates (using 'malloc()') and returns a substring from the
** string 's'.
** The substring begins at index 'start' and is as maximum size 'len'.
*/

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	count;
	size_t	size;
	char	*tab;

	if (!s)
		return (NULL);
	if ((unsigned int)ft_strlen(s) < start)
		return (ft_strdup(""));
	size = ft_strlen(s + start);
	if (size < len)
		len = size;
	if (!(tab = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	count = 0;
	while (count < len)
	{
		tab[count] = s[start + count];
		count++;
	}
	tab[count] = '\0';
	return (tab);
}

int	get_next_line(int fd, char **line)
{
	int		i;
	char		buf[BUFFER_SIZE + 1];
	static char	*aux;
	char		*aux2;
	int		tmp;
	char		*tmp2;

	if (!line)
		return (-1);
	while ((i = read(fd, buf, BUFFER_SIZE)) > 0)
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
	else
	{
		tmp = 0;
		while (aux[tmp] != '\n' && aux[tmp] != '\0')
			tmp++;
		if (aux[tmp] == '\n')
		{
			*line = ft_substr(aux, 0, tmp);
			tmp2 = ft_strdup(&aux[tmp + 1]);
			free(aux);
			aux = tmp2;
		}
		else if (aux[tmp] == '\0')
		{
			*line = ft_strdup(aux);
			free(aux);
			aux = 0;
			return (0);
		}
		return (1);
	}
}

