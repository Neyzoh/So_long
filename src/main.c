/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adammour <adammour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 12:23:11 by adammour          #+#    #+#             */
/*   Updated: 2025/06/10 22:09:05 by adammour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int ac, char **av)
{
	t_game	game;

	ft_bzero(&game, sizeof(t_game));
	if (ac != 2)
	{
		ft_putstr_fd("Usage ./so_long <map>\n", 2);
		return (1);
	}
	if (!init_game(av[1], &game))
	{
		ft_putstr_fd("Failed to initialize game\n", 2);
		return (1);
	}
	map_render(&game);
	mlx_hook(game.window_ptr, KeyPress, KeyPressMask, &player_moove, &game);
	mlx_loop_hook(game.mlx_ptr, map_render, &game);
	mlx_hook(game.window_ptr, 17, 0, cross_clicked, &game);
	mlx_loop(game.mlx_ptr);
	return (0);
}
