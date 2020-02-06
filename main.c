/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-lo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 10:32:56 by adiaz-lo          #+#    #+#             */
/*   Updated: 2020/01/22 10:39:13 by adiaz-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

/*
** Main function to test the Get Next Line project
*/

int		main(void)
{
	int	fd;
	char	*line;
	
	fd = open("test_files/1_empty_line");
	if (fd == -1)
		ft_putstr("Open failed");
	while (get_next_line(fd, &line) > 0)
		printf(%s\n, line);

	return (0);
}
