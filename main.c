/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-lo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 10:32:56 by adiaz-lo          #+#    #+#             */
/*   Updated: 2021/02/03 12:34:08 by adiaz-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

/*
** Main function to test the Get Next Line project
*/

int		main(void)
{
	int	fd;
	char	*line;
	
	fd = open("test_files/1_empty_line", O_RDONLY);
	if (fd == -1)
		write(2, "Open failed\n", 13);
	while (get_next_line(fd, &line) > 0)
		printf("%s\n", line);

	return (0);
}
