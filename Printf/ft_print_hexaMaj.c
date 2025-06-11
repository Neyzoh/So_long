/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexaMaj.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adammour <adammour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:35:51 by adammour          #+#    #+#             */
/*   Updated: 2024/12/21 14:57:26 by adammour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hexmaj(unsigned int nb)
{
	char	*hexa;
	int		i;

	hexa = "0123456789ABCDEF";
	i = 0;
	if (nb >= 16)
		i += ft_print_hexmaj(nb / 16);
	i += ft_print_char(hexa[nb % 16]);
	return (i);
}
