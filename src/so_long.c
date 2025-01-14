/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artperez <artperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 09:34:59 by artperez          #+#    #+#             */
/*   Updated: 2025/01/14 14:50:10 by artperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	handle_input(int keysym, t_mlx_data *ptr)
{
	if (keysym == XK_Escape)
		clean_exit(ptr);
	return (0);
}

int	clean_exit(t_mlx_data *ptr)
{
	mlx_destroy_window(ptr->mlx_start, ptr->mlx_window);
	mlx_destroy_display(ptr->mlx_start);
	free(ptr->mlx_start);
	exit(0);
}

// int	count_height()
// {
// 	char	*line;
// 	int		height;
// 	int		file;
	
// 	hesight = 0;
// 	file = open("/map/map.ber", O_RDONLY);
// 	while (line != NULL)
// 	{
// 		line = get_next_line(file);
// 		if (line == NULL)
// 			break ;
// 		free(line);
// 		height++;
// 	}
// 	if (height < 3)
// 	{
// 		free(line);
// 		close(file);
// 		return (-1);
// 	}
// 	close(file);
// 	return (height);
// }

int	count_height()
{
	int		readbytes
	char	*buf;
	int		height;
	int		file;
	
	height = 0;
	buf = malloc(char * 3);	
	if (buf == NULL)
		return (NULL);
	file = open("/map/map.ber", O_RDONLY);
	while (readbytes != 0)
	{
		readbytes = read(file, buf, 2);
		if (readbytes == -1)
			return (free(buf), free (line), NULL)
		if (strchr(buf, '\n'))
			height++;
		// 1 de plus a la height ?
	}
	close (file);
	return (height);
}

char	*ft_strjoin0(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		a;

	i = 0;
	a = 0;
	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[a] != '\0')
	{
		str[i] = s2[a];
		i++;
		a++;
	}
	if (str[i - 1] == '\n')
		str[i - 1] = '\0'; 
	str[i] = '\0';
	return (str);
}
char	**get_map(char **map, int height)
{
	char	*line;
	int		file;
	int		len;
	int		i;

	i = 0;
	check = 0;
	file = open("/map/map.ber", O_RDONLY);
	if (file == -1)
		return (NULL);
	while (i < height)
	{
		map[i] = calloc(1, sizeof(char));
		line = get_next_line(file);
		len = ft_strlen(line);
		ft_strjoin0(map[i], line);
		i++;
	}
	free(line);
	close(file);
	return (map);
}

int	check_map()
{
	char	**map;
	char	*line;
	char	
	int		len;
	int		height;

	height = count_height();
	map = malloc((char *) * height)
	map = get_map(map, height);
	while (line !=)
	{
		line = get_next_line("/map/map.ber")
		map[i] = line;
		i++;
	}
	if (map == NULL)
	exit (0);
	
}

int	main()
{
	t_mlx_data	mlx_data;
	
	check_map()
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
	mlx_hook(mlx_data.mlx_window, 17, 0, clean_exit, &mlx_data);
	mlx_loop(mlx_data.mlx_start);
}
