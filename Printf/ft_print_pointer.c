/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adammour <adammour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:37:58 by adammour          #+#    #+#             */
/*   Updated: 2024/12/21 14:28:13 by adammour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_pointer(unsigned long long int nb)
{
	static int	i;
	char		*hexa;

	i = 2;
	hexa = "0123456789abcdef";
	if (nb == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	if (nb >= 16)
		ft_print_pointer(nb / 16);
	if (i == 2)
		write(1, "0x", 2);
	i++;
	ft_print_char(hexa[nb % 16]);
	return (i);
}
