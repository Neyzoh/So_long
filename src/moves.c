/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adammour <adammour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 18:13:19 by adammour          #+#    #+#             */
/*   Updated: 2025/06/07 21:39:31 by adammour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int go_down(t_game *game, t_point pos)
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

int go_up(t_game *game, t_point pos)
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

int go_right(t_game *game, t_point pos)
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
int go_left(t_game *game, t_point pos)
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

void free_xpm(t_game *game)
{
	if (game->img_wall)
		mlx_destroy_image(game->mlx_ptr, game->img_wall);
	if (game->img_player)
		mlx_destroy_image(game->mlx_ptr, game->img_player);
	if (game->img_floor)
		mlx_destroy_image(game->mlx_ptr, game->img_floor);
	if (game->img_exit)
		mlx_destroy_image(game->mlx_ptr, game->img_exit);
	if (game->img_collect)
		mlx_destroy_image(game->mlx_ptr, game->img_collect);
}

int ft_clean(t_game *game, char *str)
{
	free_tab(game->map);
	free_xpm(game);
	if (game->mlx_ptr || game->window_ptr)
		mlx_destroy_window(game->mlx_ptr, game->window_ptr);
	if (game->mlx_ptr)
	{
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
	}
	printf("%s\n", str);
	exit(0);
}

void print_tab(char **str)
{
	int i = 0;
	while (str[i])
	{
		printf("%s\n", str[i]);
		i++;
	}
}

int cross_clicked(t_game *game)
{
	ft_clean(game, "Cross clicked");
	return 1;
}

int player_moove(int key, t_game *game)
{
	t_point pos = player_position(game->map);
	int flag = 1;

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
