/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 18:29:56 by hben-yah          #+#    #+#             */
/*   Updated: 2018/04/09 18:29:57 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_pow(int nb, int pow)
{
	int res;
	int i;

	res = 1;
	i = 0;
	while (i++ < pow)
		res *= nb;
	return (res);
}
