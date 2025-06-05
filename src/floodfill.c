#include "../includes/so_long.h"

t_point	player_position(char **map)
{
	t_point	player_pos;
	int		i;
	int		j;

	i = 0;
	player_pos.x = 0;
	player_pos.y = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				player_pos.x = j;
				player_pos.y = i;
			}
			j++;
		}
		i++;
	}
	return (player_pos);
}
void	fill(char **map, t_fill *data, int y, int x)
{
	if (y < 0 || x < 0 || y >= data->height || x >= data->width)
		return ;
	if (map[y][x] == 'F' || map[y][x] == '1')
		return ;
	if (map[y][x] == 'C')
		data->collect++;
	if (map[y][x] == 'E')
	{
		data->exit++;
		map[y][x] = 'F';
		return ;
	}
	map[y][x] = 'F';
	fill(map, data, y - 1, x);
	fill(map, data, y + 1, x);
	fill(map, data, y, x - 1);
	fill(map, data, y, x + 1);
}
t_fill	flood_fill(char **map)
{
	t_point	begin;
	t_fill	fill_data;

	begin = player_position(map);
	fill_data.collect = 0;
	fill_data.exit = 0;
	fill_data.width = map_width(map);
	fill_data.height = map_height(map);
	fill(map, &fill_data, begin.y, begin.x);
	return (fill_data);
}
