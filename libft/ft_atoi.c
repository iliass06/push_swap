/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-fadi <iel-fadi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 00:35:03 by iel-fadi          #+#    #+#             */
/*   Updated: 2026/02/14 23:44:33 by iel-fadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// static int	sign(int n)
// {
// 	if (n < 0)
// 		return (0);
// 	else
// 		return (-1);
// }

// int	ft_atoi(const char *nptr)
// {
// 	long	test;
// 	long	result;
// 	int		signe;
// 	int		i;

// 	i = 0;
// 	signe = 1;
// 	result = 0;
// 	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
// 		i++;
// 	if (nptr[i] == '-' || nptr[i] == '+')
// 	{
// 		if (nptr[i] == '-')
// 			signe = -1;
// 		i++;
// 	}
// 	while (nptr[i] >= '0' && nptr[i] <= '9')
// 	{
// 		test = result;
// 		result = result * 10 + (nptr[i] - '0');
// 		if (result / 10 != test)
// 			return (sign(signe));
// 		i++;
// 	}
// 	return ((int)(result * signe));
//}

long ft_atol(const char *nptr)
{
    long    result;
    int     signe;
    int     i;

    i = 0;
    signe = 1;
    result = 0;
    // Gestion espaces
    while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
        i++;
    // Gestion signes
    if (nptr[i] == '-' || nptr[i] == '+')
    {
        if (nptr[i] == '-')
            signe = -1;
        i++;
    }
    // Conversion
    while (nptr[i] >= '0' && nptr[i] <= '9')
    {
        result = result * 10 + (nptr[i] - '0');
        i++;
    }
    return (result * signe); // On retourne un LONG, pas un int !
}
