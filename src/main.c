/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adammour <adammour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 12:23:11 by adammour          #+#    #+#             */
/*   Updated: 2025/06/07 21:45:46 by adammour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <stdio.h> // pour printf

void print_game_state(t_game *game)
{
	int i = 0;

	printf("=== GAME STATE ===\n");
	printf("Map Width: %d\n", game->map_width);
	printf("Map Height: %d\n", game->map_height);
	printf("Number of Collectibles: %d\n", game->nb_collectible);
	printf("Already Collected: %d\n", game->already_collect);
	printf("Window Width: %d\n", game->window_width);
	printf("Window Height: %d\n", game->window_height);

	printf("\n--- MAP ---\n");
	if (!game->map)
	{
		printf("Map is NULL\n");
	}
	else
	{
		while (game->map[i])
		{
			printf("%s\n", game->map[i]);
			i++;
		}
	}

	printf("\n--- MLX POINTERS ---\n");
	printf("mlx_ptr: %p\n", game->mlx_ptr);
	printf("window_ptr: %p\n", game->window_ptr);

	printf("\n--- IMAGES ---\n");
	printf("img_wall: %p\n", game->img_wall);
	printf("img_floor: %p\n", game->img_floor);
	printf("img_collect: %p\n", game->img_collect);
	printf("img_exit: %p\n", game->img_exit);
	printf("img_player: %p\n", game->img_player);
}

int main(int ac, char **av)
{

	t_game game = {0};
	if (ac != 2)
		return (printf("Usage ./so_long <map>\n"), 1);

	// if (!init_game(av[1], &game))
	//     ft_putstr_fd("hey", 1);

	if (!init_game(av[1], &game))
	{
		ft_putstr_fd("Failed to initialize game\n", 2);
		return (1); // ou exit(1);
	}

	map_render(&game);		 // PREMIER RENDU MANUEL
	// print_game_state(&game); // Affiche dans le terminal (optionnel)
	mlx_hook(game.window_ptr, KeyPress, KeyPressMask, &player_moove, &game);
	mlx_loop_hook(game.mlx_ptr, map_render, &game); // Hook la fonction pour la boucle
	mlx_hook(game.window_ptr, 17, 0, cross_clicked, &game);
	mlx_loop(game.mlx_ptr);							// Démarre la boucle MLX

	// mlx_loop(game.mlx_ptr);
	return (0);

	// char **map;
	// map = parse_map(av[1]);
	// init_mlx(map);
	// // int i = 0;

	// free_tab(map);
	// while (map[i])
	// {
	//     printf("%s\n", map[i]);
	//     i++;
	// }
	// free_tab(map);
	// flood_fill(map);
	// printf("\n");
	// int i = 0;
	// while (map[i])
	// {
	//     printf("%s\n", map[i]);
	//     i++;
	// }
	// free_tab(map);
	// map = load_map(av[1]);
	// // printf("%d\n", check_extension(av[1]));
	// // printf("%d\n", check_line_size(map));
	// printf("%d\n", check_wall(map));
	// // printf("P: %d\n", count_elem(map, 'E'));
	// // printf("%d\n", check_map_elem(map));
}
