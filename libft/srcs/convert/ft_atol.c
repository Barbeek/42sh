/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 18:35:38 by hben-yah          #+#    #+#             */
/*   Updated: 2019/02/18 18:37:37 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atol(const char *str)
{
	long res;
	char sign;

	res = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		++str;
	if (*str == '+')
		++str;
	else if (*str == '-')
	{
		sign *= -1;
		++str;
	}
	while (*str >= '0' && *str <= '9')
		res = (res * 10) + *(str++) - '0';
	return (res * sign);
}
