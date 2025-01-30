/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artperez <artperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 10:39:33 by artperez          #+#    #+#             */
/*   Updated: 2025/01/30 10:46:57 by artperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_map_goodway_playerpos(t_map *ptr, t_playerpos *pos)
{
	int	i;
	int	a;
	
	i = 0;
	a = 0;
	while(ptr->grid[a][i] != 'P')
	{
		i++;
		if (i > ptr->width)
		{
			i = 0;
			a++;
		}
	}
	pos->width = i;
	pos->height = a;
	return (0);
}

int	check_map_close(t_map *ptr)
{
	int	i;
	
	i = 0;
	while (i < ptr->width)
	{
		if (ptr->grid[0][i] != '1')
			return (1);
		i++;
	}
	i = 0;
	while (i < ptr->width)
	{
		if (ptr->grid[ptr->height - 1][i] != '1')
			return (1);
		i++;
	}
	if (check_map_close_mid(ptr) == 1)
		return (1);
	return (0);
}

int check_map_close_mid(t_map *ptr)
{
	int	i;
	
	i = 1;
	while (i < ptr->height - 1)
	{
		if (ptr->grid[i][0] != '1' || ptr->grid[i][ptr->width - 1] != '1')
			return (1);
		i++;
	}
	return (0);
}
int	check_map_size(t_map *ptr)
{
	int		i;
	size_t	len;
	
	i = 0;
	len = ft_strlen(ptr->grid[i]);
	while (i != ptr->height - 1)
	{
		if (len != ft_strlen(ptr->grid[i]))
			return (1);
		i++;
	}
	ptr->width = len;
	return (0);
}

int	check_map_name(char *map_name)
{
	int	i;
	int	len;
	
	i = ft_strlen(map_name);
	len = ft_strlen(map_name);
	while (i > 0)
	{
		if (map_name[i] == '.')
		{
			if (ft_strncmp(ft_strnstr(map_name + i, ".ber", 5), ".ber", len) == 0)
				return (0);
		}
		i--;
	}
	return (1);
}