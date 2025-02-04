/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artperez <artperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 09:34:59 by artperez          #+#    #+#             */
/*   Updated: 2025/02/04 09:53:49 by artperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	handle_input(int keysym, t_data *ptr)
{
	ptr->map.width = ft_strlen(ptr->map.grid[0]);
	check_map_goodway_playerpos(&ptr->map, &ptr->playerpos);
	if (keysym == XK_Escape)
		clean_exit(ptr);
	if (keysym == 97)
		left(ptr);
	if (keysym == 115)
		down(ptr);
	if (keysym == 100)
		right(ptr);
	if (keysym == 119)
		up(ptr);
	if (ptr->playerpos.item_total == ptr->playerpos.item)
	{
		findexit (ptr);
		mlx_put_image_to_window(ptr->mlx_start, ptr->mlx_window,
			ptr->textures.exitopen,
			ptr->playerpos.exitwidth * 42, ptr->playerpos.exitheight * 42);
	}
	return (0);
}

void	taking_map(char *map_name, t_map *ptr)
{
	int	file;

	file = open(map_name, O_RDONLY);
	if (file == -1)
	{
		write(2, "Error\nMap not found", 20);
		exit (0);
	}
	close(file);
	ptr->height = count_height(map_name);
	ptr->grid = malloc(sizeof(char *) * ptr->height);
	if (get_map(ptr, map_name) == 1)
	{
		write(2,"Error\nMap invalid", 18);
		exit (0);
	}
	if (ptr->grid == NULL)
	{
		write(2, "Error\nMap not found", 20);
		exit (0);
	}
}

int	check_map(t_map *ptr, t_playerpos *pos, t_map *map)
{
	if (check_map_size(ptr) == 1)
		return (1);
	pos->item_total = check_map_goodway_items_number(ptr);
	if (ptr->height == ptr->width)
		return (1);
	if (check_map_close(ptr) == 1)
		return (1);
	if (check_map_goodelement(ptr) == 1)
		return (1);
	if (check_map_allelement(ptr, pos) == 1)
		return (1);
	pos->exit = 0;
	pos->item = 0;
	check_map_goodway_playerpos(ptr, pos);
	check_map_goodway(ptr, pos->height, pos->w, pos);
	if (pos->exit != 1 || pos->item != pos->item_total)
		return (1);
	map->width = ptr->width;
	free_map(ptr);
	return (0);
}

int	main(int argc, char **argv)
{
	t_map		map_check;
	t_data		data;

	data.mlx_start = NULL;
	data.mlx_window = NULL;
	check_arguments(argc, argv[1]);
	taking_map(argv[1], &data.map);
	map_giving(&map_check, &data.map);
	if (check_map(&map_check, &data.playerpos, &data.map) == 1)
	{
		write(2, "Error\nMap invalid", 18);
		free_map(&map_check);
		clean_exit(&data);
	}
	if (create_window(&data, &map_check) == 1)
		clean_exit(&data);
	init_textures(&data.textures, &data);
	display(&data, &data.textures, &data.map);
	mlx_key_hook(data.mlx_window, handle_input, &data);
	mlx_hook(data.mlx_window, 17, 0, clean_exit, &data);
	mlx_loop(data.mlx_start);
	return (0);
}
