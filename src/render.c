/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adammour <adammour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 15:14:32 by adammour          #+#    #+#             */
/*   Updated: 2025/06/10 22:37:54 by adammour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	add_img(t_game *game, int i, int j)
{
	char	tile;

	tile = game->map[i][j];
	if (tile == '1')
	{
		mlx_put_image_to_window(game->mlx_ptr, game->window_ptr, game->img_wall,
			j * IMG_SIZE, i * IMG_SIZE);
	}
	else
	{
		mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
			game->img_floor, j * IMG_SIZE, i * IMG_SIZE);
		if (tile == 'C')
			mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
				game->img_collect, j * IMG_SIZE, i * IMG_SIZE);
		else if (tile == 'E')
			mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
				game->img_exit, j * IMG_SIZE, i * IMG_SIZE);
		else if (tile == 'P')
			mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
				game->img_player, j * IMG_SIZE, i * IMG_SIZE);
	}
}

int	map_render(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			add_img(game, i, j);
			j++;
		}
		i++;
	}
	return (1);
}
