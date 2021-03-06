/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tablen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 11:15:11 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/29 22:06:51 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_tablen(void **tab)
{
	void **d;

	d = tab;
	while (*d)
		++d;
	return ((size_t)(d - tab));
}

size_t		ft_strtablen(char **tab)
{
	return (ft_tablen((void **)tab));
}

size_t		ft_strtabstrlen(char **tab, size_t *i)
{
	size_t len;

	len = 0;
	*i = 0;
	while (tab[*i])
		len += ft_strlen(tab[(*i)++]);
	return (len);
}
