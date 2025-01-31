/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artperez <artperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 10:40:58 by artperez          #+#    #+#             */
/*   Updated: 2025/01/31 11:23:13 by artperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_map_goodway(t_map *ptr, int height, int width, t_playerpos *pos)
{
	if (height < 0 || height >= ptr->height || width < 0 || width >= ptr->width)
		return ;
	if (ptr->grid[height][width] == '1' || ptr->grid[height][width] == 'V')
		return ;
	if (ptr->grid[height][width] == 'E')
		pos->exit = 1;
	if (ptr->grid[height][width] == 'C')
	{
		pos->item++;
		ptr->grid[height][width] = 'V';
	}
	if (pos->exit == 1 && pos->item == pos->item_total)
		return ;
	ptr->grid[height][width] = 'V';
	check_map_goodway(ptr, height + 1, width, pos);
	check_map_goodway(ptr, height - 1, width, pos);
	check_map_goodway(ptr, height, width + 1, pos);
	check_map_goodway(ptr, height, width - 1, pos);
}

int	check_map_goodway_items_number(t_map *ptr)
{
	int	i;
	int	a;
	int	items_number;

	items_number = 0;
	i = 0;
	a = 0;
	while (a < ptr->height - 1)
	{
		if (ptr->grid[a][i] == 'C')
			items_number++;
		if (i > ptr->width - 1)
		{
			a++;
			i = 0;
		}
		i++;
	}
	return (items_number);
}

int	check_map_goodelement(t_map *ptr)
{
	int	i;
	int	a;

	i = 0;
	a = 0;
	while (a < ptr->height)
	{
		if (ptr->grid[a][i] != '1' && ptr->grid[a][i] != '0'
			&& ptr->grid[a][i] != 'E' && ptr->grid[a][i] != 'C'
			&& ptr->grid[a][i] != 'P')
			return (1);
		i++;
		if (i == ptr->width - 1)
		{
			i = 0;
			a++;
		}
	}
	return (0);
}

int	check_map_allelement(t_map *ptr, t_playerpos *variables)
{
	int	i;
	int	a;

	i = 0;
	a = 0;
	variables->exit = 0;
	variables->pos = 0;
	while (a < ptr->height)
	{
		if (ptr->grid[a][i] == 'E')
			variables->exit++;
		if (ptr->grid[a][i] == 'C')
			variables->item = 1;
		if (ptr->grid[a][i] == 'P')
			variables->pos++;
		i++;
		if (i == ptr->width - 1)
		{
			i = 0;
			a++;
		}
	}
	if (variables->exit == 1 && variables->item == 1 && variables->pos == 1)
		return (0);
	return (1);
}
