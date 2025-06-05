/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adammour <adammour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 12:23:11 by adammour          #+#    #+#             */
/*   Updated: 2025/06/05 19:12:14 by adammour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int ac, char **av)
{

    (void)ac;

    t_game game;
    if (!init_game(av[1], &game))
        ft_putstr_fd("hey", 1);
    map_render(&game);
    mlx_loop_hook(game.window_ptr, &map_render, &game);
    mlx_loop(game.mlx_ptr);
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

