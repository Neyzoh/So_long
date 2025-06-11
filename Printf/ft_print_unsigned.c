/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adammour <adammour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 13:37:48 by adammour          #+#    #+#             */
/*   Updated: 2024/12/21 14:31:31 by adammour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unsigned(unsigned int nb)
{
	int	i;

	i = 0;
	if (nb > 9)
		i += ft_print_unsigned(nb / 10);
	i += ft_print_char(nb % 10 + '0');
	return (i);
}
