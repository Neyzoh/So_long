/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adammour <adammour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:06:43 by adammour          #+#    #+#             */
/*   Updated: 2024/12/21 14:59:42 by adammour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);

int	ft_print_base(int nb);

int	ft_print_unsigned(unsigned int nb);

int	ft_print_char(char c);

int	ft_print_hexmaj(unsigned int nb);

int	ft_print_hexmin(unsigned int nb);

int	ft_print_pointer(unsigned long long int nb);

int	ft_print_str(char *str);

#endif
