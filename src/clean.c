/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artperez <artperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 10:56:53 by artperez          #+#    #+#             */
/*   Updated: 2025/01/31 13:14:31 by artperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_map(t_map *map)
{
	int	i;

	i = map->height - 1;
	while (i != -1)
	{
		free(map->grid[i]);
		i--;
	}
	free(map->grid);
}

void	free_textures(t_textures *textures, t_data *data)
{
	if (textures->player)
		mlx_destroy_image(data->mlx_start, textures->player);
	if (textures->exit)
		mlx_destroy_image(data->mlx_start, textures->exit);
	if (textures->collectible)
		mlx_destroy_image(data->mlx_start, textures->collectible);
	if (textures->floor)
		mlx_destroy_image(data->mlx_start, textures->floor);
	if (textures->wall)
		mlx_destroy_image(data->mlx_start, textures->wall);
	if (textures->wallin)
		mlx_destroy_image(data->mlx_start, textures->wallin);
	if (textures->exitopen)
		mlx_destroy_image(data->mlx_start, textures->exitopen);
}

int	clean_exit(t_data *data)
{
	free_map(&data->map);
	if (data->mlx_start)
	{
		if (data->mlx_window)
		{
			free_textures(&data->textures, data);
			mlx_destroy_window(data->mlx_start, data->mlx_window);
		}
		mlx_destroy_display(data->mlx_start);
		free(data->mlx_start);
	}
	exit(0);
}
