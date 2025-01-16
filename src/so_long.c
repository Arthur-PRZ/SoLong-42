/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artperez <artperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 09:34:59 by artperez          #+#    #+#             */
/*   Updated: 2025/01/16 14:46:06 by artperez         ###   ########.fr       */
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

size_t	count_height(char *map_name)
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
	buf[2] = '\0';
	file = open(map_name, O_RDONLY);
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
	// free(buf);
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
void	get_map(t_map *ptrptr, char *map_name)
{
	char	*line;
	int		file;
	int		len;
	int		i;

	i = 0;
	file = open(map_name, O_RDONLY);
	if (file == -1)
		return ;
	while (i < ptrptr->height)
	{
		ptrptr->grid[i] = calloc(1, sizeof(char));
		line = get_next_line(file);
		len = ft_strlen(line);
		ptrptr->grid[i] = ft_strjoin0(ptrptr->grid[i], line);
		i++;
	}
	free(line);
	close(file);
}

void	taking_map(char *map_name, t_map *ptr)
{
	ptr->height = count_height(map_name);
	ptr->grid = malloc(sizeof(char *) * ptr->height);
	get_map(ptr, map_name);
	// while (line !=)
	// {
	// 	line = get_next_line("/map/map.ber")
	// 	map[i] = line;
	// 	i++;
	// }
	// if (map == NULL)
	return ;	
	
}
int	check_map_name(char *map_name)
{
	int	i;
	int	len;
	
	i = ft_strlen(map_name);
	len = ft_strlen(map_name);
	while (i > 0)
	{
		if (map_name[i] == '.')
		{
			if (ft_strncmp(ft_strnstr(map_name + i, ".ber", 5), ".ber", len) == 0)
				return (0);
		}
		i--;
	}
	return (1);
}

int	check_map_size(t_map *ptr)
{
	int		i;
	size_t	len;
	
	i = 0;
	len = ft_strlen(ptr->grid[i]);
	while (i != ptr->height)
	{
		if (len != ft_strlen(ptr->grid[i]))
			return (1);
		i++;
	}
	ptr->width = len;
	return (0);
}

int check_map_close_mid(t_map *ptr)
{
	int	i;
	
	i = 1;
	while (i < ptr->height - 1)
	{
		if (ptr->grid[i][0] != '1' || ptr->grid[i][ptr->width - 1] != '1')
			return (1);
		i++;
	}
	return (0);
}
int	check_map_close(t_map *ptr)
{
	int	i;
	
	i = 0;
	while (i < ptr->width)
	{
		if (ptr->grid[0][i] != '1')
			return (1);
		i++;
	}
	i = 0;
	while (i < ptr->width)
	{
		if (ptr->grid[ptr->height - 1][i] != '1')
			return (1);
		i++;
	}
	if (check_map_close_mid(ptr) == 1)
		return (1);
	return (0);
}
int	check_map_goodway_playerpos(t_map *ptr, t_playerpos *pos)
{
	int	i;
	int	a;
	
	i = 0;
	a = 0;
	while(ptr->grid[a][i] != 'P')
	{
		i++;
		if (i > ptr->width)
		{
			i = 0;
			a++;
		}
	}
	pos->width = a;
	pos->height = i;
	return (1);
}

int	check_map_allelement(t_map *ptr, t_playerpos *variables)
{
	int	i;
	int	a;
	
	i = 0;
	a = 0;
	variables->exit = 0;
	variables->pos = 0;
	while(i < ptr->height)
	{
		if (ptr->grid[a][i] == 'E')
			variables->exit++;
		if (ptr->grid[a][i] == 'C')
			variables->item = 1;
		if (ptr->grid[a][i] == 'P')
			variables->pos++;
		i++;
		if(i == ptr->width - 1)
		{
			i = 0;
			a++;
		}
	}
	if (variables->exit == 1 && variables->item == 1 && variables->pos == 1)
		return (0);
	return (1);
}

// int	check_map_goodway(t_map *ptr, t_playerpos *pos)
// {
// 	check_map_goodway_playerpos()
// }

int	check_map(t_map *ptr, t_playerpos *pos)
{
	if (check_map_size(ptr) == 1)
		return (1);
	if (ptr->height == ptr->width)
		return (1);
	if (check_map_close(ptr) == 1)
		return (1);
	if (check_map_allelement(ptr, pos) == 1)
		return (1);
	// if (check_map_goodway(ptr, pos) == 1)
	return (0);
}

int	main(int argc, char **argv)
{
	int			i;
	t_map 		map;
	t_playerpos	pos;

	// t_mlx_data	mlx_data;
	
	i = 0;
	if (argc != 2)
	{
		ft_printf("Number of argument invalid");
		exit (0);
	}
	if (check_map_name(argv[1]) == 1)
	{
		ft_printf("Map name invalid");
		exit (0);
	}
	taking_map(argv[1], &map);
	if (map.grid == NULL)
	{
		ft_printf("Map not found");
		exit (0);
	}
	if (check_map(&map, &pos) == 1)
	{
		ft_printf("Map invalid");
		exit (0);
	}
	ft_printf("good");
	//taking_map();
	// taking_map()
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