/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-lo <adiaz-lo@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 13:37:53 by adiaz-lo          #+#    #+#             */
/*   Updated: 2021/02/04 17:48:25 by adiaz-lo         ###   ########.fr       */
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

/*
** Auxiliar function that frees memory of a pointer of pointers
*/

void	free_mem(char **line_str)
{
	if (line_str != NULL && *line_str != NULL)
	{
		free(*line_str);
		*line_str = NULL;
	}
}

/*
** Auxiliar function that trims what we read to a line.
*/

static int	set_line(char **line, char **line_read)
{
	int	tmp;
	char	*tmp2;

	tmp = 0;
	while ((*line_read)[tmp] != '\n' && (*line_read)[tmp] != '\0')
		tmp++;
	if ((*line_read)[tmp] == '\n')
	{
		*line = ft_substr(*line_read, 0, tmp);
		tmp2 = ft_strdup(&(*line_read)[tmp + 1]);
		free(*line_read);
		*line_read = tmp2;
	}
	else if ((*line_read)[tmp] == '\0')
	{
		*line = ft_strdup(*line_read);
		free_mem(line_read);
		return (0);
	}
	return (1);
}

/*
** Auxiliar function that checks what's been read
*/

static int	check_read(int fd, int i, char **line, char **line_read)
{
	if (i < 0)
		return (-1);
	else if (i == 0 && !line_read[fd])
	{
		*line = ft_strdup("");
		free_mem(line_read);
		return (0);
	}
	else
		return (set_line(line, &line_read[fd]));
}

/*
** Main function of the program
*/

int	get_next_line(int fd, char **line)
{
	int		i;
	char		buf[BUFFER_SIZE + 1];
	static char	*str[4096];
	char		*str_buf;

	if (!line || fd < 0 || BUFFER_SIZE < 1 || read (fd, buf, 0) < 0)
		return (-1);
	while ((i = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[i] = '\0';
		if (str[fd] == NULL)
			str[fd] = ft_strdup(buf);
		else
		{
			str_buf = ft_strjoin(str[fd], buf);
			free(str[fd]);
			str[fd] = str_buf;
		}
		if (ft_strchr(str[fd], '\n'))
			break ;
	}
	return (check_read(fd, i, line, str));
}

