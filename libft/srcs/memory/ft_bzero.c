/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 17:55:06 by hben-yah          #+#    #+#             */
/*   Updated: 2019/02/18 18:29:19 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char *d;

	d = (unsigned char *)s;
	while (n--)
		*(d++) = 0;
}

/*
** void	ft_bzero(void *s, size_t n)
** {
** 	unsigned char	*d;
** 	unsigned long	*l;
** 	size_t			sl;
** 	size_t			r;
**
** 	if (!n)
** 		return ;
** 	d = (unsigned char *)s;
** 	sl = sizeof(long);
** 	r = (sl - (((size_t)d + 1) % sl)) % sl;
** 	while (r-- && n--)
** 		*(d++) = 0;
** 	l = (unsigned long *)d;
** 	while (n >= sl)
** 	{
** 		*(l++) = 0;
** 		n -= sl;
** 	}
** 	d = (unsigned char *)l;
** 	while (n--)
** 		*(d++) = 0;
** }
*/
