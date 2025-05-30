/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adammour <adammour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:09:21 by adammour          #+#    #+#             */
/*   Updated: 2024/11/27 13:35:06 by adammour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dstc;
	char	*srcc;

	dstc = (char *)dst;
	srcc = (char *)src;
	if (dstc > srcc && dstc < srcc + len)
	{
		dstc = dstc + len;
		srcc = srcc + len;
		while (len--)
			*--dstc = *--srcc;
	}
	else
		ft_memcpy(dstc, srcc, len);
	return (dstc);
}
