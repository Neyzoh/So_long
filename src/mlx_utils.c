/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adammour <adammour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 11:30:39 by adammour          #+#    #+#             */
/*   Updated: 2025/06/05 14:17:41 by adammour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int init_map(t_game *game, char *path)
{
    game->map = parse_map(path);
    game->map_height = map_height(game->map);
    game->map_width = map_width(game->map);
    game->nb_collectible = count_elem(game->map, 'C');
    game->already_collect = 0;
    return (1);
}
int init_mlx(t_game *game)
{
    game->mlx_ptr = mlx_init();
    if (!game->mlx_ptr)
        return (free_tab(game->map), write(2, "Error:\n mlx initialization failed", 34), 0);
    game->window_height = game->map_height * IMG_SIZE;
    game->window_width = game->map_width * IMG_SIZE;
    game->window_ptr = mlx_new_window(game->mlx_ptr, game->window_width,
                                      game->window_height, "so_long");
    if (!game->window_ptr)
        return (free_tab(game->map), free(game->mlx_ptr), write(2, "Error:\nwindow creation", 23), 0);
    mlx_loop(game->mlx_ptr);
    return (1);
}

int init_img(t_game *game)
{

    int img_size;

    img_size = IMG_SIZE;
    
    game->img_wall = mlx_xpm_file_to_image(game->mlx_ptr, "../img/wall.xpm", &img_size, &img_size);
    game->img_player = mlx_xpm_file_to_image(game->mlx_ptr, "../img/player.xpm", &img_size, &img_size);
    game->img_floor = mlx_xpm_file_to_image(game->mlx_ptr, "../img/floor.xpm", &img_size, &img_size);
    game->img_exit = mlx_xpm_file_to_image(game->mlx_ptr, "../img/exit.xpm", &img_size, &img_size);
    game->img_collect = mlx_xpm_file_to_image(game->mlx_ptr, "../img/coin.xpm", &img_size, &img_size);

    if (!(game->img_wall && game->img_exit && game->img_floor && game->img_player && game->img_collect))
        return (free_tab(game->map), free(game->mlx_ptr), ft_putstr_fd("Error:\nimg creation", 2), 0);
    return(1);
}

int init_game(char *path, t_game *game)
{
    if (!init_map(game, path))
        return (0);
    if (!init_mlx(game))
        return (0);
    if (!init_img(game))
        return (0);
    return(1);
}
// void mlx_xpm_to_img();

// void mlx_put_img_to_window();
