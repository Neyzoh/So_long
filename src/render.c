/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adammour <adammour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 15:14:32 by adammour          #+#    #+#             */
/*   Updated: 2025/06/05 18:47:24 by adammour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int map_render(t_game *game)
{
    int    i;
    int    j;

    i = 0;
    while (game->map[i])
    {
        j = 0;
        while (game->map[i][j])
        {
            if (game->map[i][j] == '1')
                mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
                    game->img_wall, j * IMG_SIZE, i * IMG_SIZE);
            else if (game->map[i][j] == '0')
                mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
                    game->img_floor,j * IMG_SIZE, i * IMG_SIZE);
            else if (game->map[i][j] == 'C')
                mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
                    game->img_collect, j * IMG_SIZE, i * IMG_SIZE);
            else if (game->map[i][j] == 'E')
                mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
                    game->img_exit, j * IMG_SIZE, i * IMG_SIZE);
            else if (game->map[i][j] == 'P')
                mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
                    game->img_player, j * IMG_SIZE, i * IMG_SIZE);
            j++;
        }
        i++;
    }
    return (1); 
}

