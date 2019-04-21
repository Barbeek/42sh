/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   car.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 18:58:37 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/29 17:23:47 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

t_car	*car_new(void)
{
	return ((t_car *)try_m(ft_memalloc(sizeof(t_car))));
}

t_car	*car_dup(t_car *car)
{
	t_car *ret;

	ret = car_new();
	ret->val = car->val;
	if (car->wide)
		if (!(ret->wide = car_dup(car->wide)))
		{
			free(ret);
			return (NULL);
		}
	return (ret);
}

int		car_del(t_car **car)
{
	int		ret;
	t_car	*todel;

	if (car && *car)
	{
		ret = 1;
		todel = *car;
		*car = (*car)->next;
		if (todel->wide)
			ret += car_del(&todel->wide);
		free(todel);
		return (ret);
	}
	return (0);
}
