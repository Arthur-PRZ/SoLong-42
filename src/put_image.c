/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artperez <artperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 11:14:05 by artperez          #+#    #+#             */
/*   Updated: 2025/01/31 11:23:42 by artperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	display_floor(t_data *data, t_textures *textures, int i, int a)
{
	mlx_put_image_to_window(data->mlx_start, data->mlx_window,
		textures->floor, i * 42, a * 42);
}

void	display_exit(t_data *data, t_textures *textures, int i, int a)
{
	mlx_put_image_to_window(data->mlx_start, data->mlx_window,
		textures->exit, i * 42, a * 42);
}

void	display_collectible(t_data *data, t_textures *textures, int i, int a)
{
	mlx_put_image_to_window(data->mlx_start, data->mlx_window,
		textures->collectible, i * 42, a * 42);
}

void	display_player(t_data *data, t_textures *textures, int i, int a)
{
	mlx_put_image_to_window(data->mlx_start, data->mlx_window,
		textures->player, i * 42, a * 42);
}
