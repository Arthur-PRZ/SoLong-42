/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   taking_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artperez <artperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 10:39:55 by artperez          #+#    #+#             */
/*   Updated: 2025/01/30 10:53:24 by artperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

size_t	count_height(char *file)
{
	int		fd;
	char	*line;
	int		height;
	
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (1);
	height = 0;
	while (1)
	{
		line = readline(fd);
		if (line == NULL)
			break ;
		height++;
		free(line);
	}
	close(fd);
	return (height);
}

char	*readline(int fd)
{
	char	*line;
	int		len;

	line = get_next_line(fd);
	if (line == NULL)
		return (NULL);
	len = ft_strlen(line);
	if (line[len - 1] == '\n')
		line[len - 1] = '\0';
	return (line);		
}

void	get_map(t_map *ptrptr, char *map_name)
{
	char	*line;
	int		file;
	int		i;

	i = 0;
	file = open(map_name, O_RDONLY);
	if (file == -1)
		return ;

	while (i < ptrptr->height)
	{
		ptrptr->grid[i] = ft_calloc(1, sizeof(char));
		line = get_next_line(file);
		if (line != NULL)
			ptrptr->grid[i] = ft_strjoin0(ptrptr->grid[i], line);
		if (line == NULL && i == ptrptr->height - 1)
			ptrptr->grid[i] = NULL;
		i++;
		free(line);
	}
	line = get_next_line(file);
	free(line);
	close(file);
}