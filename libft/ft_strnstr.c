/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adammour <adammour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:19:02 by adammour          #+#    #+#             */
/*   Updated: 2024/11/27 13:28:39 by adammour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	i;
	size_t	y;
	size_t	len;

	i = 0;
	len = ft_strlen(needle);
	if (len == 0)
		return ((char *)haystack);
	while (haystack[i] && i < n)
	{
		y = 0;
		while (needle[y] == haystack[i + y] && (i + y) < n)
		{
			if (y == len - 1)
				return ((char *)haystack + i);
			y++;
		}
		i++;
	}
	return (NULL);
}
