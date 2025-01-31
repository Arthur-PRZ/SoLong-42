/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artperez <artperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 10:39:47 by artperez          #+#    #+#             */
/*   Updated: 2025/01/31 11:03:21 by artperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	left(t_data *ptr)
{
	if (ptr->map.grid[ptr->playerpos.height][ptr->playerpos.w - 1] == 'E'
		&& ptr->playerpos.item_total == ptr->playerpos.item)
	{
		total_movement_count(ptr);
		clean_exit(ptr);
	}
	if (ptr->map.grid[ptr->playerpos.height][ptr->playerpos.w - 1] == 'C')
		ptr->playerpos.item++;
	if (ptr->map.grid[ptr->playerpos.height][ptr->playerpos.w - 1] != '1'
		&& ptr->playerpos.exit == 1)
	{
		ptr->map.grid[ptr->playerpos.height][ptr->playerpos.w - 1] = 'P';
		ptr->map.grid[ptr->playerpos.height][ptr->playerpos.w] = 'E';
		ptr->playerpos.exit = 0;
		total_movement_count(ptr);
	}
	else if (ptr->map.grid[ptr->playerpos.height][ptr->playerpos.w - 1] != '1'
		&& ptr->playerpos.exit == 0)
	{
		if (ptr->map.grid[ptr->playerpos.height][ptr->playerpos.w - 1] == 'E')
			ptr->playerpos.exit = 1;
		ptr->map.grid[ptr->playerpos.height][ptr->playerpos.w - 1] = 'P';
		ptr->map.grid[ptr->playerpos.height][ptr->playerpos.w] = '0';
		total_movement_count(ptr);
	}
}

void	right(t_data *ptr)
{
	if (ptr->map.grid[ptr->playerpos.height][ptr->playerpos.w + 1] == 'E'
		&& ptr->playerpos.item_total == ptr->playerpos.item)
	{
		total_movement_count(ptr);
		clean_exit(ptr);
	}
	if (ptr->map.grid[ptr->playerpos.height][ptr->playerpos.w + 1] == 'C')
		ptr->playerpos.item++;
	if (ptr->map.grid[ptr->playerpos.height][ptr->playerpos.w + 1] != '1'
		&& ptr->playerpos.exit == 1)
	{
		ptr->map.grid[ptr->playerpos.height][ptr->playerpos.w + 1] = 'P';
		ptr->map.grid[ptr->playerpos.height][ptr->playerpos.w] = 'E';
		total_movement_count(ptr);
		ptr->playerpos.exit = 0;
	}
	else if (ptr->map.grid[ptr->playerpos.height][ptr->playerpos.w + 1] != '1'
		&& ptr->playerpos.exit == 0)
	{
		if (ptr->map.grid[ptr->playerpos.height][ptr->playerpos.w + 1] == 'E')
			ptr->playerpos.exit = 1;
		ptr->map.grid[ptr->playerpos.height][ptr->playerpos.w + 1] = 'P';
		ptr->map.grid[ptr->playerpos.height][ptr->playerpos.w] = '0';
		total_movement_count(ptr);
	}
}

void	up(t_data *ptr)
{
	if (ptr->map.grid[ptr->playerpos.height - 1][ptr->playerpos.w] == 'E'
		&& ptr->playerpos.item_total == ptr->playerpos.item)
	{
		total_movement_count(ptr);
		clean_exit(ptr);
	}
	if (ptr->map.grid[ptr->playerpos.height - 1][ptr->playerpos.w] == 'C')
		ptr->playerpos.item++;
	if (ptr->map.grid[ptr->playerpos.height - 1][ptr->playerpos.w] != '1'
		&& ptr->playerpos.exit == 1)
	{
		ptr->map.grid[ptr->playerpos.height - 1][ptr->playerpos.w] = 'P';
		ptr->map.grid[ptr->playerpos.height][ptr->playerpos.w] = 'E';
		ptr->playerpos.exit = 0;
		total_movement_count(ptr);
	}
	else if (ptr->map.grid[ptr->playerpos.height - 1][ptr->playerpos.w] != '1'
		&& ptr->playerpos.exit == 0)
	{
		if (ptr->map.grid[ptr->playerpos.height - 1][ptr->playerpos.w] == 'E')
			ptr->playerpos.exit = 1;
		ptr->map.grid[ptr->playerpos.height - 1][ptr->playerpos.w] = 'P';
		ptr->map.grid[ptr->playerpos.height][ptr->playerpos.w] = '0';
		total_movement_count(ptr);
	}
}

void	down(t_data *ptr)
{
	if (ptr->map.grid[ptr->playerpos.height + 1][ptr->playerpos.w] == 'E'
		&& ptr->playerpos.item_total == ptr->playerpos.item)
	{
		total_movement_count(ptr);
		clean_exit(ptr);
	}
	if (ptr->map.grid[ptr->playerpos.height + 1][ptr->playerpos.w] == 'C')
		ptr->playerpos.item++;
	if (ptr->map.grid[ptr->playerpos.height + 1][ptr->playerpos.w] != '1'
		&& ptr->playerpos.exit == 1)
	{
		ptr->map.grid[ptr->playerpos.height + 1][ptr->playerpos.w] = 'P';
		ptr->map.grid[ptr->playerpos.height][ptr->playerpos.w] = 'E';
		ptr->playerpos.exit = 0;
		total_movement_count(ptr);
	}
	else if (ptr->map.grid[ptr->playerpos.height + 1][ptr->playerpos.w] != '1'
		&& ptr->playerpos.exit == 0)
	{
		if (ptr->map.grid[ptr->playerpos.height + 1][ptr->playerpos.w] == 'E')
			ptr->playerpos.exit = 1;
		ptr->map.grid[ptr->playerpos.height + 1][ptr->playerpos.w] = 'P';
		ptr->map.grid[ptr->playerpos.height][ptr->playerpos.w] = '0';
		total_movement_count(ptr);
	}
}
