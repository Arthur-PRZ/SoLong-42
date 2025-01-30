/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artperez <artperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 09:34:59 by artperez          #+#    #+#             */
/*   Updated: 2025/01/30 11:32:58 by artperez         ###   ########.fr       */
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
		ft_printf("Error: Map not found");
		exit (0);
	}
	close(file);
	ptr->height = count_height(map_name);
	ptr->grid = malloc(sizeof(char *) * ptr->height);
	get_map(ptr, map_name);
}

int	check_map(t_map *ptr, t_playerpos *pos)
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
	check_map_goodway(ptr, pos->height, pos->width, pos);
	if (pos->exit != 1 || pos->item != pos->item_total)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_textures	textures;
	t_map		map_check;
	t_data		data;

	if (argc != 2)
	{
		ft_printf("Error: Number of argument invalid\n");
		exit (0);
	}
	if (check_map_name(argv[1]) == 1)
	{
		ft_printf("Error: Map name invalid\n");
		exit (0);
	}
	data.mlx_start = NULL;
	data.mlx_window = NULL;
	taking_map(argv[1], &data.map);
	if (data.map.grid == NULL)
	{
		ft_printf("Error: Map not found\n");
		exit (0);
	}
	map_giving(&map_check, &data.map);
	if (check_map(&map_check, &data.playerpos) == 1)
	{
		ft_printf("Error: Map invalid\n");
		free_map(&map_check);
		clean_exit(&data);
	}
	free_map(&map_check);
	data.map.width = map_check.width;
	if (createWindow(&data, &map_check) == 1)
		clean_exit(&data);
	initTextures(&textures, &data);
	mlx_key_hook(data.mlx_window, handle_input, &data);
	display(&data, &textures, &data.map);
	data.textures = textures;
	data.playerpos.exit = 0;
	data.playerpos.item = 0;
	data.i = 0;
	data.a = 0;
	mlx_hook(data.mlx_window, 17, 0, clean_exit, &data);
	mlx_loop(data.mlx_start);
	return (0);
}
