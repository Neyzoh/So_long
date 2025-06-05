/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adammour <adammour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 12:03:16 by adammour          #+#    #+#             */
/*   Updated: 2025/06/05 11:27:02 by adammour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_extension(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (ft_strncmp((const char *)(str + len - 4), ".ber", 4) == 0)
		return (1);
	return (0);
}

char	**load_map(char *path)
{
	int		fd;
	char	*line;
	char	*buffer;
	char	**map;

	line = ft_strdup("");
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	buffer = get_next_line(fd);
	while (buffer)
	{
		line = ft_strjoin_free(line, buffer);
		free(buffer);
		buffer = get_next_line(fd);
	}
	free(buffer);
	map = ft_split(line, '\n');
	free(line);
	close(fd);
	return (map);
}

char	**parse_map(char *path)
{
	char	**map;
	char	**map_tmp;
	t_fill	data;

	if (!check_extension(path))
		exit_parse(NULL, "File needs to be .ber");
	map = load_map(path);
	if (!map)
		exit_parse(NULL, "Can not load map !");
	if (!check_line_size(map))
		exit_parse(map, "Invalid map : different line size");
	if (!check_wall(map))
		exit_parse(map, "Invalid map : not surrounded by walls");
	if (check_map_elem(map) == 42)
		exit_parse(map, "Invalid map : invalid element");
	if (!check_map_elem(map))
		exit_parse(map, "Invalid map : invalid number of elements");
	map_tmp = load_map(path);
	data = flood_fill(map_tmp);
	free_tab(map_tmp);
	if (!(data.collect == count_elem(map, 'C') && data.exit == 1))
		exit_parse(map, "Invalid map : not all element are reachable");
	return (map);
}
