/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adammour <adammour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 17:19:16 by adammour          #+#    #+#             */
/*   Updated: 2024/11/28 16:42:48 by adammour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// recherche un character dans une zone memoire
void	*ft_memchr(const void *ptr, int value, size_t num)
{
	size_t				i;
	const unsigned char	*p;
	unsigned char		c;

	p = (unsigned char *)ptr;
	c = (unsigned char )value;
	i = 0;
	while (i < num)
	{
		if (p[i] == c)
			return ((void *)(p + i));
		i++;
	}
	return (NULL);
}
