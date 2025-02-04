/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artperez <artperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 09:32:58 by artperez          #+#    #+#             */
/*   Updated: 2025/02/04 09:50:16 by artperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <fcntl.h>

typedef struct s_map
{
	char		**grid;
	int			height;
	int			width;
}				t_map;

typedef struct s_playerpos
{
	int			height;
	int			w;
	int			exitheight;
	int			exitwidth;
	int			exit;
	int			item;
	int			item_total;
	int			pos;
}				t_playerpos;

typedef struct s_textures
{
	int			*player;
	int			*exit;
	int			*exitopen;
	int			*collectible;
	void		*wall;
	void		*wallin;
	char		*floor;
	int			x;
	int			y;
}				t_textures;

typedef struct s_data
{
	void		*mlx_start;
	void		*mlx_window;
	int			i;
	int			a;
	t_map		map;
	t_playerpos	playerpos;
	t_textures	textures;
}				t_data;

# define HEIGHT 800
# define WIDTH 800

int				ft_strchr_gnl(char *str, char c);
int				handle_input(int keysym, t_data *ptr);
int				clean_exit(t_data *data);
size_t			count_height(char *file);
char			*ft_strjoin0(char const *s1, char const *s2);
int			get_map(t_map *ptrptr, char *map_name);
void			taking_map(char *map_name, t_map *ptr);
int				check_map(t_map *ptr, t_playerpos *pos, t_map *map);
int				check_map_close_mid(t_map *ptr);
int				check_map_close(t_map *ptr);
void			check_map_goodway(t_map *ptr, int height, int width,
					t_playerpos *pos);
int				check_map_size(t_map *ptr);
int				check_map_allelement(t_map *ptr, t_playerpos *variables);
int				check_map_goodelement(t_map *ptr);
void			free_map(t_map *map);
void			free_textures(t_textures *textures, t_data *data);
int				create_window(t_data *data, t_map *map_check);
void			init_textures(t_textures *textures, t_data *data);
void			display(t_data *data, t_textures *textures, t_map *map);
void			map_giving(t_map *rmap, t_map *map);
int				check_map_goodway_playerpos(t_map *ptr, t_playerpos *pos);
void			left(t_data *ptr);
void			right(t_data *ptr);
void			up(t_data *ptr);
void			down(t_data *ptr);
int				check_map_goodway_items_number(t_map *ptr);
void			findexit(t_data *ptr);
char			*readline(int fd);
void			total_movement_count(t_data *ptr);
int				check_map_name(char *map_name);
void			check_arguments(int argc, char *argv);
void			display_floor(t_data *data, t_textures *textures, int i, int a);
void			display_exit(t_data *data, t_textures *textures, int i, int a);
void			display_collectible(t_data *data, t_textures *textures, int i,
					int a);
void			display_wall(t_data *data, t_textures *textures, int i, int a);
void			display_player(t_data *data, t_textures *textures, int i,
					int a);

#endif