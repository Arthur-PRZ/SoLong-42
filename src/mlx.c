/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artperez <artperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 10:39:41 by artperez          #+#    #+#             */
/*   Updated: 2025/01/30 11:28:43 by artperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	createWindow(t_data	*data, t_map *map)
{
	data->mlx_start = mlx_init();
	if (data->mlx_start == NULL)
	{
		free_map(&data->map);
		exit (0);
	}
	data->mlx_window = mlx_new_window(data->mlx_start, map->width * 42, map->height * 42, "So_long");
	if (data->mlx_window == NULL)
	{
		free_map(&data->map);
		mlx_destroy_display(data->mlx_start);
		free(data->mlx_start);
		exit (0);
	}
	return (0);
}

void	display_wall(t_data *data, t_textures *textures, int i, int a)
{
		if (i == (int)ft_strlen(data->map.grid[0]) - 1 || i == 0 || a == data->map.height - 1 || a == 0)
			mlx_put_image_to_window(data->mlx_start, data->mlx_window, textures->wall, i * 42, a * 42);
		else
			mlx_put_image_to_window(data->mlx_start, data->mlx_window, textures->wallin, i * 42, a * 42);
}

void	display(t_data *data, t_textures *textures, t_map *map)
{
	int	a;
	int	i;

	a = 0;
	i = 0;
	while (a < map->height)
	{
		if (map->grid[a][i] == '1')
			display_wall(data, textures, i, a);
		else if (map->grid[a][i] == '0')
			mlx_put_image_to_window(data->mlx_start, data->mlx_window, textures->floor, i * 42, a * 42);
		else if (map->grid[a][i] == 'E')
			mlx_put_image_to_window(data->mlx_start, data->mlx_window, textures->exit, i * 42, a * 42);
		else if (map->grid[a][i] == 'P')
			mlx_put_image_to_window(data->mlx_start, data->mlx_window, textures->player, i * 42, a * 42);
		else if (map->grid[a][i] == 'C')
			mlx_put_image_to_window(data->mlx_start, data->mlx_window, textures->collectible, i * 42, a * 42);
		i++;
		if (i > map->width - 1)
		{
			a++;
			i = 0;
		}
	}
}

void initTextures(t_textures *textures, t_data *data)
{
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
    if (textures->player == NULL || textures->exit == NULL || 
        textures->collectible == NULL || textures->floor == NULL || 
        textures->wall == NULL || textures->exitopen == NULL || textures->wallin == NULL)
    {
        ft_printf("Error: Failed to load one or more textures\n");
        clean_exit(data);
    }
}
