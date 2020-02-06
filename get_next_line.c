/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-lo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 12:50:53 by adiaz-lo          #+#    #+#             */
/*   Updated: 2020/01/22 09:29:16 by adiaz-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Main function of the project, which realises the logic of the program,
** getting the 
*/

int	get_next_line(int fd, char **line)
{
	static char	*rem_str[4096];

	while (read(fd, buffer, BUFFER_SIZE) > 0)
		if (ft_read_line)
			return (1);
}
