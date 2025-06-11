/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adammour <adammour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 12:23:11 by adammour          #+#    #+#             */
/*   Updated: 2025/06/12 00:02:27 by adammour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// int open_file(const char *filename, int *fd)
// {
// 	*fd = open(filename, O_RDONLY);
// 	if (*fd == -1)
// 	{
// 		ft_putstr_fd("Failed to open the map file\n", 2);
// 		return (0);
// 	}
// 	return (1);
// }

// int check_line_length(int fd)
// {
// 	char	buffer[1024];
// 	ssize_t	bytes_read;
// 	char *line;

// 	while ((bytes_read = read(fd, buffer, sizeof(buffer) - 1)) > 0)
// 	{
// 		buffer[bytes_read] = '\0';
// 		line = buffer;
// 		while (*line)
// 		{
// 			size_t line_length = 0;
// 			while (line[line_length] && line[line_length] != '\n')
// 			{
// 				line_length++;
// 			}
// 			if (line_length > 45)
// 			{
// 				ft_putstr_fd("A line exceeds the maximum allowed length of 45 characters\n", 2);
// 				return (0);
// 			}
// 			line += line_length;
// 			if (*line == '\n')
// 				line++;
// 		}
// 	}
// 	return (1);
// }

// int check_map(const char *filename)
// {
// 	int		fd;
// 	char	buffer[1024];
// 	int		line_count = 0;
// 	ssize_t	bytes_read;
// 	char *line;
// 	size_t line_length = 0;



// 	fd = open(filename, O_RDONLY);
// 	if (fd == -1)
// 	{
// 		ft_putstr_fd("Failed to open the map file\n", 2);
// 		return (0);
// 	}
// 	while ((bytes_read = read(fd, buffer, sizeof(buffer) - 1)) > 0)
// 	{
// 		buffer[bytes_read] = '\0';
// 		line = buffer;
// 		while (*line)
// 		{
// 			size_t line_length = 0;
// 			while (line[line_length] && line[line_length] != '\n')
// 			{
// 				line_length++;
// 			}
// 			if (line_length > 45)
// 			{
// 				ft_putstr_fd("A line exceeds the maximum allowed length of 45 characters\n", 2);
// 				close(fd);
// 				return (0);
// 			}
// 			line += line_length;
// 			if (*line == '\n')
// 			{
// 				line++;
// 				line_count++;
// 			}
// 		}
// 	}
// 	if (line_count > 25)
// 	{
// 		ft_putstr_fd("The map exceeds the maximum allowed lines of 25\n", 2);
// 		close(fd);
// 		return (0);
// 	}
// 	close(fd);
// 	return (1);
// }

// int	map_counter(const char *filename)
// {
// 	int	fd;

// 	if (!open_file(filename, &fd))
// 		return (0);
// 	if (!check_line_length(fd))
// 	{
// 		close(fd);
// 		return (0);
// 	}
// 	if (!check_line_count(fd))
// 	{
// 		close(fd);
// 		return (0);
// 	}
// 	close(fd);
// 	return (1);
// }

int	main(int ac, char **av)
{
	t_game	game;

	ft_bzero(&game, sizeof(t_game));
	if (ac != 2)
	{
		ft_putstr_fd("Usage: ./so_long <map>\n", 2);
		return (1);
	}
	// if (!map_counter(av[1]))
	// {
	// 	return (1);
	// }
	if (!init_game(av[1], &game))
	{
		ft_putstr_fd("Failed to initialize game\n", 2);
		return (1);
	}
	// mlx_get_screen_size(game.mlx_ptr, )
	map_render(&game);
	mlx_hook(game.window_ptr, KeyPress, KeyPressMask, &player_moove, &game);
	mlx_loop_hook(game.mlx_ptr, map_render, &game);
	mlx_hook(game.window_ptr, 17, 0, cross_clicked, &game);
	mlx_loop(game.mlx_ptr);
	return (0);
}
