/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adammour <adammour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 17:34:47 by adammour          #+#    #+#             */
/*   Updated: 2024/11/27 17:56:54 by adammour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	while (i >= 0 && s[i] != (unsigned char)c)
	{
		i--;
	}
	if (i < 0)
		return ((char *) NULL);
	else
		return ((char *)(s + i));
}

/*int main()
{
	const char  *str= "Bonjour, mondem";
	char    c = 'm';
	char    *result = ft_strrchr(str, c);

	if (result != NULL)
	{
		printf("caractere trouve a la position :%ld\n", result - str);
	}
	else
	{
		printf("caractere non trouve. \n");
	}
}*/