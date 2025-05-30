/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_verifs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adammour <adammour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 17:32:01 by adammour          #+#    #+#             */
/*   Updated: 2025/05/30 17:40:08 by adammour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"


int	check_line_size(char **map)
{
	size_t	i;
	size_t	len;

	i = 1;
	len = ft_strlen(map[0]);
	while (map[i])
	{
		if (ft_strlen(map[i]) != len)
			return (0);
		i++;
	}
	return (1);
}

int	check_wall(char **map)
{
	int	i;
	int	j;
	int	height;
	int	width;

	i = 0;
	j = 0;
	height = map_height(map);
	width = map_width(map);
	while (i < width)
	{
		if (map[0][i] != '1' || map[height - 1][i] != '1')
			return (0);
		i++;
	}
	while (j < height)
	{
		if (map[j][0] != '1' || map[j][width - 1] != '1')
			return (0);
		j++;
	}
	return (1);
}

int	count_elem(char **map, char c)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (c == map[i][j])
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int	check_map_elem(char **map)
{
    int i;
    int j;

    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (!(map[i][j] == '0' || map[i][j] == '1' || map[i][j] == 'P'
                || map[i][j] == 'E' || map[i][j] == 'C'))
                return(42);
            j++;
        }
        i++;
    }
    if (count_elem(map, 'P') != 1)
        return (0);
    if (count_elem(map, 'C') < 1)
        return (0);
    if (count_elem(map, 'E') != 1)
        return (0);
    return (1);
}
