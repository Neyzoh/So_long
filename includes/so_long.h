#ifndef SO_LONG
#define SO_LONG


# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include "../GetNextLine/get_next_line.h"
# include <fcntl.h>
# include <stdio.h>
#include "../libft/libft.h"

typedef struct s_game
{
    char **map;

} t_game;


int check_extension(char *str);
char    **load_map(char *path);
char **parse_map(char *path);
char	*ft_strjoin_free(char *s1, char const *s2);
int check_line_size(char **map);
int check_wall(char **map);
size_t map_width(char **map);
size_t map_height(char **map);
int count_elem(char **map, char c);
int	check_map_elem(char **map);
void    free_tab(char **tab);
void	exit_parse(char **map, char *str);



#endif