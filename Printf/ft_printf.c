/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adammour <adammour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:35:51 by adammour          #+#    #+#             */
/*   Updated: 2025/06/11 21:36:49 by adammour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_verif(char c, va_list args)
{
	int	size;

	size = 0;
	if (c == '%')
		size = ft_print_char('%');
	else if (c == 'c')
		size = ft_print_char(va_arg(args, int));
	else if (c == 's')
		size = ft_print_str(va_arg(args, char *));
	else if (c == 'p')
		size = ft_print_pointer(va_arg(args, unsigned long long int));
	else if (c == 'd')
		size = ft_print_base(va_arg(args, int));
	else if (c == 'i')
		size = ft_print_base(va_arg(args, int));
	else if (c == 'u')
		size = ft_print_unsigned(va_arg(args, unsigned int));
	else if (c == 'x')
		size = ft_print_hexmin(va_arg(args, unsigned int));
	else if (c == 'X')
		size = ft_print_hexmaj(va_arg(args, unsigned int));
	return (size);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		len;
	va_list	args;

	i = 0;
	len = 0;
	if (!format)
		return (-1);
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			len = len + ft_verif(format[i], args);
		}
		else
		{
			ft_print_char(format[i]);
			len++;
		}
		i++;
	}
	va_end(args);
	return (len);
}

// #include <stdio.h>
// #include <limits.h>
// int	main(void)
// {
//   	ft_printf(" %X ", INT_MAX);
// 	ft_printf(" %X ", INT_MIN);
// 	ft_printf(" %X ", LONG_MAX);
// 	ft_printf(" %X ", LONG_MIN);
// 	ft_printf(" %X ", UINT_MAX);
// 	ft_printf(" %X \n", ULONG_MAX);
// 	printf(" %lX ", INT_MAX);
// 	printf(" %lX ", INT_MIN);
// 	printf(" %lX ", LONG_MAX);
// 	printf(" %lX ", LONG_MIN);
// 	printf(" %lX ", UINT_MAX);
// 	printf(" %lX ", ULONG_MAX);

//     return (0);
// }