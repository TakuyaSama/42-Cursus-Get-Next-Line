/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-lo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 12:52:10 by adiaz-lo          #+#    #+#             */
/*   Updated: 2020/01/29 13:30:42 by adiaz-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
** This function allows to print a string to the terminal. Useful to show
** messages in terminal.
*/

void	ft_putstr(char *str)
{
	while(*str && *str != '\n')
		write(1, s++, 1);
{

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
** This function returns a pointer to a new string obtained duplicating 's'.
** For further information, please check the Standard C Library function
** strdup(const char *s).
*/

char    *ft_strdup(const char *s)
{
        char    *str;
        int             str_len;

        str_len = ft_strlen(s) + 1;
        if ((str = malloc(str_len)))
        {
                ft_strlcpy(str, s, str_len);
                return (str);
        }
        return (NULL);
}

/*
** This function returns a pointer to the first ocurrence of the character
** 'c' in the string 's'. Additionally, it locates the last occurrence of 'c'.
** For further information, please check the Standard C Library function
** 'strrchr(const char *s, int c)'.
*/

char	*ft_strrchr(const char *s, int c)
{
	const char	*str;

	str = s;
	while (*s)
		s++;
	if (c == 0)
		return ((char *)s);
	while (s >= str)
	{
		if (*s == c)
			return ((char *)s);
		s--;
	}
	return (0);
}

/*
** This function frees the memory of a pointer received by parameter and sets
** to NULL, to avoid leaving memory leaks.
*/

void	ft_free_memory(char **p)
{
	if(*p)
	{
		free(*p);
		*p = NULL;
	}
}
