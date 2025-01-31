/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artperez <artperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 10:39:41 by artperez          #+#    #+#             */
/*   Updated: 2025/01/31 13:20:34 by artperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	create_window(t_data *data, t_map *map)
{
	data->mlx_start = mlx_init();
	if (data->mlx_start == NULL)
	{
		free_map(&data->map);
		exit (0);
	}
	data->mlx_window = mlx_new_window(data->mlx_start,
			map->width * 42, map->height * 42, "so_long");
	if (data->mlx_window == NULL)
	{
		free_map(&data->map);
		mlx_destroy_display(data->mlx_start);
		free(data->mlx_start);
		exit (0);
	}
	data->playerpos.exit = 0;
	data->playerpos.item = 0;
	return (0);
}

void	display_wall(t_data *data, t_textures *textures, int i, int a)
{
	if (i == (int)ft_strlen(data->map.grid[0]) - 1
		|| i == 0 || a == data->map.height - 1 || a == 0)
		mlx_put_image_to_window(data->mlx_start, data->mlx_window,
			textures->wall, i * 42, a * 42);
	else
		mlx_put_image_to_window(data->mlx_start, data->mlx_window,
			textures->wallin, i * 42, a * 42);
}

void	display(t_data *data, t_textures *textures, t_map *map)
{
	int	a;
	int	i;

	a = 0;
	while (a < map->height)
	{
		i = 0;
		while (i < map->width)
		{
			if (map->grid[a][i] == '1')
				display_wall(data, textures, i, a);
			else if (map->grid[a][i] == '0')
				display_floor(data, textures, i, a);
			else if (map->grid[a][i] == 'E')
				display_exit(data, textures, i, a);
			else if (map->grid[a][i] == 'P')
				display_player(data, textures, i, a);
			else if (map->grid[a][i] == 'C')
				display_collectible(data, textures, i, a);
			i++;
		}
		a++;
	}
}

void	init_textures(t_textures *textures, t_data *data)
{
	data->i = 0;
	textures->x = 42;
	textures->y = 42;
	textures->player = mlx_xpm_file_to_image(data->mlx_start,
			"textures/player.xpm", &textures->x, &textures->y);
	textures->floor = mlx_xpm_file_to_image(data->mlx_start,
			"textures/floor.xpm", &textures->x, &textures->y);
	textures->exit = mlx_xpm_file_to_image(data->mlx_start,
			"textures/exit.xpm", &textures->x, &textures->y);
	textures->wall = mlx_xpm_file_to_image(data->mlx_start,
			"textures/wall.xpm", &textures->x, &textures->y);
	textures->collectible = mlx_xpm_file_to_image(data->mlx_start,
			"textures/collectible.xpm", &textures->x, &textures->y);
	textures->exitopen = mlx_xpm_file_to_image(data->mlx_start,
			"textures/exitopen.xpm", &textures->x, &textures->y);
	textures->wallin = mlx_xpm_file_to_image(data->mlx_start,
			"textures/wallin.xpm", &textures->x, &textures->y);
	if (textures->player == NULL || textures->exit == NULL
		|| textures->collectible == NULL || textures->floor == NULL
		|| textures->wall == NULL || textures->exitopen == NULL
		|| textures->wallin == NULL)
	{
		write(2, "Error\nFailed to load one or more textures", 42);
		clean_exit(data);
	}
}
