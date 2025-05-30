/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adammour <adammour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 17:16:23 by adammour          #+#    #+#             */
/*   Updated: 2025/05/30 17:29:47 by adammour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"



size_t	map_width(char **map)
{
	size_t	width;

	width = ft_strlen(*map);
	return (width);
}
size_t	map_height(char **map)
{
	size_t	height;

	height = 0;
	while (map[height])
		height++;
	return (height);
}

void    free_tab(char **tab)
{
    int i;

    i = 0;
    while (tab[i])
    {
        free(tab[i]);
        i++;
    }
    free(tab);
}

void	exit_parse(char **map, char *str)
{
	ft_putstr_fd(str, 2);
	if (map)
		free_tab(map);
	exit(1);
}

char	*ft_strjoin_free(char *s1, char const *s2)
{
	char	*tmp;

	tmp = ft_strjoin((const char *)s1, s2);
	free(s1);
	return (tmp);
}