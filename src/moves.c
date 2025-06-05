/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adammour <adammour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 18:13:19 by adammour          #+#    #+#             */
/*   Updated: 2025/06/05 19:07:01 by adammour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	go_down(t_game *game, t_point pos)
{
	if (pos.y + 1 < game->map_height || game->map[pos.y + 1][pos.x] == '1')
		return (1);
	else if (game->map[pos.y + 1][pos.x] == '0')
	{
		game->map[pos.y + 1][pos.x] = 'P';
		game->map[pos.y][pos.x] = '0';
	}
	else if (game->map[pos.y + 1][pos.x] == 'C')
	{
		game->map[pos.y + 1][pos.x] = 'P';
		game->map[pos.y][pos.x] = '0';
		game->already_collect++;
	}
	else if (game->map[pos.y + 1][pos.x] == 'E')
	{
		if (game->already_collect != game->nb_collectible)
			return (1);
		game->map[pos.y + 1][pos.x] = 'P';
		game->map[pos.y][pos.x] = 'E';
		ft_putstr_fd("gg", 1);
	}
	return (0);
}

int	go_up(t_game *game, t_point pos)
{
	if (pos.y - 1 < game->map_height || game->map[pos.y - 1][pos.x] == '1')
		return (1);
	else if (game->map[pos.y - 1][pos.x] == '0')
	{
		game->map[pos.y - 1][pos.x] = 'P';
		game->map[pos.y][pos.x] = '0';
	}
	else if (game->map[pos.y - 1][pos.x] == 'C')
	{
		game->map[pos.y - 1][pos.x] = 'P';
		game->map[pos.y][pos.x] = '0';
		game->already_collect++;
	}
	else if (game->map[pos.y - 1][pos.x] == 'E')
	{
		if (game->already_collect != game->nb_collectible)
			return (1);
		game->map[pos.y - 1][pos.x] = 'P';
		game->map[pos.y][pos.x] = 'E';
		ft_putstr_fd("gg", 1);
	}
	return (0);
}

int	go_right(t_game *game, t_point pos)
{
	if (pos.x + 1 < game->map_height || game->map[pos.x + 1][pos.y] == '1')
		return (1);
	else if (game->map[pos.x + 1][pos.y] == '0')
	{
		game->map[pos.x + 1][pos.y] = 'P';
		game->map[pos.x][pos.y] = '0';
	}
	else if (game->map[pos.x + 1][pos.y] == 'C')
	{
		game->map[pos.x + 1][pos.y] = 'P';
		game->map[pos.x][pos.y] = '0';
		game->already_collect++;
	}
	else if (game->map[pos.x + 1][pos.y] == 'E')
	{
		if (game->already_collect != game->nb_collectible)
			return (1);
		game->map[pos.x + 1][pos.y] = 'P';
		game->map[pos.x][pos.y] = 'E';
		ft_putstr_fd("gg", 1);
	}
	return (0);
}
int	go_left(t_game *game, t_point pos)
{
	if (pos.x - 1 < game->map_height || game->map[pos.x - 1][pos.y] == '1')
		return (1);
	else if (game->map[pos.x - 1][pos.y] == '0')
	{
		game->map[pos.x - 1][pos.y] = 'P';
		game->map[pos.x][pos.y] = '0';
	}
	else if (game->map[pos.x - 1][pos.y] == 'C')
	{
		game->map[pos.x - 1][pos.y] = 'P';
		game->map[pos.x][pos.y] = '0';
		game->already_collect++;
	}
	else if (game->map[pos.x - 1][pos.y] == 'E')
	{
		if (game->already_collect != game->nb_collectible)
			return (1);
		game->map[pos.x - 1][pos.y] = 'P';
		game->map[pos.x][pos.y] = 'E';
		ft_putstr_fd("gg", 1);
	}
	return (0);
}
int    player_moove(int key, t_game *game)
{
    t_point    pos;

    player_position(game->map);
    if (key == XK_w)
        go_up(game, pos);
    if (key == XK_d)
        go_right(game, pos);
    if (key == XK_a)
        go_left(game, pos);
    if (key == XK_s)
        go_down(game, pos);
    if (key == XK_Escape)
    {
        mlx_destroy_window(game->mlx_ptr, game->window_ptr);
        //free        
    }
    return (1);
} 