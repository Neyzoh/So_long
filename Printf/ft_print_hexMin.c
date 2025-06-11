/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexMin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adammour <adammour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:35:51 by adammour          #+#    #+#             */
/*   Updated: 2024/12/21 14:58:13 by adammour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hexmin(unsigned int nb)
{
	char	*hexa;
	int		i;

	hexa = "0123456789abcdef";
	i = 0;
	if (nb >= 16)
		i += ft_print_hexmin(nb / 16);
	i += ft_print_char(hexa[nb % 16]);
	return (i);
}
