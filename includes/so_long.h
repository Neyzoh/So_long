/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adammour <adammour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 22:09:57 by adammour          #+#    #+#             */
/*   Updated: 2025/06/10 22:10:44 by adammour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define IMG_SIZE 40

# include "../GetNextLine/get_next_line.h"
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_game
{
	char	**map;
	int		steps;
	int		map_width;
	int		map_height;
	int		nb_collectible;
	int		already_collect;
	void	*mlx_ptr;
	void	*window_ptr;
	int		window_height;
	int		window_width;
	void	*img_wall;
	void	*img_player;
	void	*img_collect;
	void	*img_exit;
	void	*img_floor;

}			t_game;

typedef struct s_point
{
	int		x;
	int		y;
}			t_point;

typedef struct s_fill
{
	int		width;
	int		height;
	int		collect;
	int		exit;

}			t_fill;

int			check_extension(char *str);
char		**load_map(char *path);
char		**parse_map(char *path);
char		*ft_strjoin_free(char *s1, char const *s2);
int			check_line_size(char **map);
int			check_wall(char **map);
size_t		map_width(char **map);
size_t		map_height(char **map);
int			count_elem(char **map, char c);
int			check_map_elem(char **map);
void		free_tab(char **tab);
void		exit_parse(char **map, char *str);
t_point		player_position(char **map);
t_fill		flood_fill(char **map);
int			init_game(char *path, t_game *game);
int			map_render(t_game *game);
int			player_moove(int key, t_game *game);
int			ft_clean(t_game *game, char *str);
int			cross_clicked(t_game *game);
#endif