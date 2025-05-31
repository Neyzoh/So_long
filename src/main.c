/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adammour <skn.aga108@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 12:23:11 by adammour          #+#    #+#             */
/*   Updated: 2025/05/31 15:32:02 by adammour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int main(int ac, char **av)
{
    (void)ac;

    char **map;
    // int i = 0;
    
    map = parse_map(av[1]);
    free_tab(map);
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
    
    return (0);
}