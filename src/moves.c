/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adammour <adammour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 18:13:19 by adammour          #+#    #+#             */
/*   Updated: 2025/06/10 22:05:10 by adammour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	go_down(t_game *game, t_point pos)
{
	if (pos.y + 1 < 0 || game->map[pos.y + 1][pos.x] == '1')
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
		game->map[pos.y][pos.x] = '0';
		ft_clean(game, "gg");
	}
	return (0);
}

int	go_up(t_game *game, t_point pos)
{
	if (pos.y - 1 < 0 || game->map[pos.y - 1][pos.x] == '1')
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
		game->map[pos.y][pos.x] = '0';
		ft_clean(game, "gg");
	}
	return (0);
}

int	go_right(t_game *game, t_point pos)
{
	if (pos.x + 1 < 0 || game->map[pos.y][pos.x + 1] == '1')
		return (1);
	else if (game->map[pos.y][pos.x + 1] == '0')
	{
		game->map[pos.y][pos.x + 1] = 'P';
		game->map[pos.y][pos.x] = '0';
	}
	else if (game->map[pos.y][pos.x + 1] == 'C')
	{
		game->map[pos.y][pos.x + 1] = 'P';
		game->map[pos.y][pos.x] = '0';
		game->already_collect++;
	}
	else if (game->map[pos.y][pos.x + 1] == 'E')
	{
		if (game->already_collect != game->nb_collectible)
			return (1);
		game->map[pos.y][pos.x + 1] = 'P';
		game->map[pos.y][pos.x] = '0';
		ft_clean(game, "gg");
	}
	return (0);
}

int	go_left(t_game *game, t_point pos)
{
	if (pos.x - 1 < 0 || game->map[pos.y][pos.x - 1] == '1')
		return (1);
	else if (game->map[pos.y][pos.x - 1] == '0')
	{
		game->map[pos.y][pos.x - 1] = 'P';
		game->map[pos.y][pos.x] = '0';
	}
	else if (game->map[pos.y][pos.x - 1] == 'C')
	{
		game->map[pos.y][pos.x - 1] = 'P';
		game->map[pos.y][pos.x] = '0';
		game->already_collect++;
	}
	else if (game->map[pos.y][pos.x - 1] == 'E')
	{
		if (game->already_collect != game->nb_collectible)
			return (1);
		game->map[pos.y][pos.x - 1] = 'P';
		game->map[pos.y][pos.x] = '0';
		ft_clean(game, "gg");
	}
	return (0);
}

int	player_moove(int key, t_game *game)
{
	t_point	pos;
	int		flag;

	pos = player_position(game->map);
	flag = 1;
	if (key == XK_w)
		flag = go_up(game, pos);
	if (key == XK_d)
		flag = go_right(game, pos);
	if (key == XK_a)
		flag = go_left(game, pos);
	if (key == XK_s)
		flag = go_down(game, pos);
	if (key == XK_Escape)
		ft_clean(game, "Esc clicked");
	if (!flag)
	{
		game->steps++;
		printf("%d steps\n", game->steps);
	}
	map_render(game);
	return (1);
}
