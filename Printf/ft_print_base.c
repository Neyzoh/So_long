/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adammour <adammour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:35:51 by adammour          #+#    #+#             */
/*   Updated: 2024/12/21 14:21:18 by adammour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_base(int nb)
{
	long long	n;
	int			i;

	n = nb;
	i = 0;
	if (n < 0)
	{
		i += ft_print_char('-');
		n = -n;
	}
	if (n > 9)
		i += ft_print_base(n / 10);
	i += ft_print_char(n % 10 + '0');
	return (i);
}

// #include <stdlib.h>
// #include <stdio.h>
// int main(int ac, char **av)
// {
// 	printf(" length: %d\n", ft_print_base(atoi(av[1])));
// // 	ft_printf(" %d ", INT_MAX);
// // 	ft_printf(" %d ", INT_MIN);
// // 	ft_printf(" %d ", LONG_MAX);
// // 	ft_printf(" %d ", LONG_MIN);
// // 	ft_printf(" %d ", UINT_MAX);
// // 	ft_printf(" %d ", ULONG_MAX);
// }
