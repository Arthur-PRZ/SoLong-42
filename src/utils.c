/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artperez <artperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 10:39:58 by artperez          #+#    #+#             */
/*   Updated: 2025/01/30 11:43:21 by artperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	*ft_strjoin0(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		a;

	i = 0;
	a = 0;
	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	free((char *)s1);
	while (s2[a] != '\0')
	{
		str[i] = s2[a];
		i++;
		a++;
	}
	if (str[i - 1] == '\n')
		str[i - 1] = '\0';
	str[i] = '\0';
	return (str);
}

void	map_giving(t_map *rmap, t_map *map)
{
	int i;
	int	a;
	
	i = 0;
	a = 0;
	rmap->grid = malloc(map->height * sizeof(char *));
	while (a < map->height)
	{
		i = 0;
		rmap->grid[a] = malloc((ft_strlen(map->grid[a]) + 1) * sizeof(char));
		while (i < (int)ft_strlen(map->grid[a]))
		{
			rmap->grid[a][i] = map->grid[a][i];
			i++;
		}
		rmap->grid[a][ft_strlen(map->grid[a])] = '\0';
		a++;
	}
	rmap->height = map->height;
}

void	total_movement_count(t_data *ptr)
{
	ptr->i++;
	ft_printf("%i\n", ptr->i);
	display(ptr, &ptr->textures, &ptr->map);
}

void	findexit(t_data *ptr)
{
	int	i;
	int	a;
	
	i = 0;
	a = 0;
	while(ptr->map.grid[a][i] != 'E')
	{
		i++;
		if (i > ptr->map.width)
		{
			i = 0;
			a++;
		}
		if (a > ptr->map.height - 1)
		 	break ;
	}
	ptr->playerpos.exitwidth = i;
	ptr->playerpos.exitheight = a;
}
