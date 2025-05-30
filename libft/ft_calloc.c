/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adammour <adammour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:31:01 by adammour          #+#    #+#             */
/*   Updated: 2024/11/28 15:23:28 by adammour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// permet d'allouer la memoire necessaire pour un tabeau de 
// num elements de size octets
// cette zone est remplie de zero
// calculer la taille de total de la memoire a allouer 
void	*ft_calloc(size_t num, size_t size)
{
	size_t	len;
	void	*ptr;

	len = num * size;
	ptr = malloc(len);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, len);
	return (ptr);
}
