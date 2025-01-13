/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artperez <artperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 09:34:59 by artperez          #+#    #+#             */
/*   Updated: 2025/01/10 11:30:36 by artperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	handle_input(int keysym, t_mlx_data *ptr)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(ptr->mlx_start, ptr->mlx_window);
		mlx_destroy_display(ptr->mlx_start);
		free(ptr->mlx_start);
		exit (1);
	}
	return (0);
}
int	main()
{
	t_mlx_data	mlx_data;
	
	mlx_data.mlx_start = mlx_init();
	if (mlx_data.mlx_start == NULL)
		return (1);
	
	mlx_data.mlx_window = mlx_new_window(mlx_data.mlx_start, HEIGHT, WIDTH, "SIUUU");
	if (mlx_data.mlx_window == NULL)
	{
		mlx_destroy_display(mlx_data.mlx_start);
		free(mlx_data.mlx_start);
		return (1);
	}
	mlx_key_hook(mlx_data.mlx_window, handle_input, &mlx_data);
	mlx_loop(mlx_data.mlx_start);
	// mlx_destroy_display(mlx_data.mlx_start);
	// mlx_destroy_window(mlx_data.mlx_start, mlx_data.mlx_window);
	// free(mlx_data.mlx_start);
}