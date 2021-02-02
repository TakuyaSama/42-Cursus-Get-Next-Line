/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-lo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 12:52:10 by adiaz-lo          #+#    #+#             */
/*   Updated: 2021/02/02 13:26:28 by adiaz-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
** This function returns the length of a string.
*/

size_t	ft_strlen(const char *s)
{
	size_t lenght;

	lenght = 0;
	while (*s++)
	{
		lenght++;
	}
	return (lenght);
}

/*
** This function allocates (with malloc(3)) and returns a new string, result of
** the concatenation of s1 and s2.
*/

char    *ft_strjoin(char const *s1, char const *s2)
{
	char    *s3;
	int     i;

	if (!s1 || !s2)
		return (0);
	if (!(s3 = (char*)malloc(sizeof(*s3) * (ft_strlen(s1) +
                 ft_strlen(s2) + 1))))
		return (0);
	i = 0;
	while (*s1)
		s3[i++] = *s1++;
	while (*s2)
		s3[i++] = *s2++;
	s3[i] = 0;
	return (s3);
}

/*
** This function returns a pointer to the first occurrence of the character 'c'
** in the string 's'.
** For further information, please check the Standard C Library function
** 'strchr(const char *s, int c)'
*/

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (0);
}

/*
** This function copies 'dstsize' of the string 'src' into 'dst' and returns
** the total length of the result string.
*/

size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;
	int				counter;

	if (!src)
		return (0);
	counter = (unsigned int)ft_strlen(src);
	if (!dstsize)
		return (counter);
	i = 0;
	while (src[i] && i < (dstsize - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (counter);
}


/*
** This function returns a pointer to a new string obtained duplicating 's'.
** For further information, please check the Standard C Library
** strdup(const char *s)
*/

char	*ft_strdup(const char *s)
{
	char	*str;
	int		str_len;

	str_len = ft_strlen(s) + 1;
	if ((str = malloc(str_len)))
	{
		ft_strlcpy(str, s, str_len);
		return (str);
	}
	return (NULL);
}
