/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adammour <adammour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:40:16 by adammour          #+#    #+#             */
/*   Updated: 2024/11/27 18:16:38 by adammour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_totrim(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		min;
	int		max;
	int		len;
	char	*res;

	min = 0;
	while (s1[min] && ft_totrim(s1[min], set))
		min++;
	max = ft_strlen(s1);
	while (max > min && ft_totrim(s1[max - 1], set))
		max--;
	len = max - min;
	res = ft_substr(s1, min, len);
	if (!res)
		return (NULL);
	res[len] = '\0';
	return (res);
}
