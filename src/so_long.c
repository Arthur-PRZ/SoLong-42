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

int	main()
{
	void	*mlx_start;
	void	*window;
	
	mlx_start = mlx_init();
	if (mlx_start == NULL)
		return (1);
	
	window = mlx_new_window(mlx_start, HEIGHT, WIDTH, "SIUUU");
	if (window == NULL)
	{
		mlx_destroy_display(mlx_start);
		free(mlx_start);
		return (1);
	}
	mlx_key_hook()
	mlx_loop(mlx_start);
	mlx_destroy_display(mlx_start);
	mlx_destroy_window(mlx_start, window);
	free(mlx_start);
}