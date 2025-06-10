/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adammour <adammour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 21:54:28 by adammour          #+#    #+#             */
/*   Updated: 2025/06/10 22:04:39 by adammour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_xpm(t_game *game)
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

int	ft_clean(t_game *game, char *str)
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

void	print_tab(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		printf("%s\n", str[i]);
		i++;
	}
}

int	cross_clicked(t_game *game)
{
	ft_clean(game, "Cross clicked");
	return (1);
}
