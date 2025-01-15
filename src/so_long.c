/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artperez <artperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 09:34:59 by artperez          #+#    #+#             */
/*   Updated: 2025/01/15 13:35:34 by artperez         ###   ########.fr       */
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

size_t	count_height()
{
	int		readbytes;
	char	*buf;
	size_t		height;
	int		file;
	
	height = 1;
	readbytes = 1;
	buf = malloc(sizeof(char) * 3);	
	if (buf == NULL)
		return (0);
	file = open("/home/artperez/Stud/exercices/so_long/map/map.ber", O_RDONLY);
	if (file == -1)
		return (0);
	while (readbytes != 0)
	{
		readbytes = read(file, buf, 2);
		if (readbytes == -1)
			return (free(buf), close(file), 0);
		if (ft_strchr_gnl(buf, '\n') == 1)
			height++;
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
	file = open("/home/artperez/Stud/exercices/so_long/map/map.ber", O_RDONLY);
	if (file == -1)
		return (NULL);
	while (i < height)
	{
		map[i] = calloc(1, sizeof(char));
		line = get_next_line(file);
		len = ft_strlen(line);
		map[i] = ft_strjoin0(map[i], line);
		i++;
	}
	free(line);
	close(file);
	return (map);
}

int	check_map()
{
	char	**map;
	size_t		height;

	height = count_height();
	map = malloc(sizeof(char *) * height);
	map = get_map(map, height);
	// while (line !=)
	// {
	// 	line = get_next_line("/map/map.ber")
	// 	map[i] = line;
	// 	i++;
	// }
	// if (map == NULL)
	exit (0);
	
}
int	check_map_name(char *str)
{
	int	i;
	int	len;
	
	i =
	i = ft_strlen(str);
	while (i > 0)
	{
		if (str[i] == '.')
		{
			if (ft_strnstr(str + i, "ber", 4) = "ber");
				return (0);
		}
		i--;
	}
	return (1);
}
int	main(int argc, char **argv)
{
	int	i;
	// t_mlx_data	mlx_data;
	
	i = 0;
	if (argv[0][1])
		i = 1;
	if (argc != 2)
	{
		ft_printf("Number of argument unvailable");
		exit (0);
	}
	if (check_map_name(argv[2]) = 1)
	{
		
	}
	//check_map();
	// check_map()
	// mlx_data.mlx_start = mlx_init();
	// if (mlx_data.mlx_start == NULL)
	// 	return (1);
	
	// mlx_data.mlx_window = mlx_new_window(mlx_data.mlx_start, HEIGHT, WIDTH, "SIUUU");
	// if (mlx_data.mlx_window == NULL)
	// {
	// 	mlx_destroy_display(mlx_data.mlx_start);
	// 	free(mlx_data.mlx_start);
	// 	return (1);
	// }
	// mlx_key_hook(mlx_data.mlx_window, handle_input, &mlx_data);
	// mlx_hook(mlx_data.mlx_window, 17, 0, clean_exit, &mlx_data);
	// mlx_loop(mlx_data.mlx_start);
	return (0);
}
