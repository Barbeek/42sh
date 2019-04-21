/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carlist.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 18:58:37 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/23 23:31:20 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

t_car	*carlist_dup(t_car *car)
{
	t_car *ret;
	t_car *dup;
	t_car *first;

	if (!car)
		return (NULL);
	first = car;
	ret = car_dup(first);
	dup = ret;
	car = car->next;
	while (car != first)
	{
		dup->next = car_dup(car);
		car = car->next;
		dup = dup->next;
	}
	ret->prev = dup;
	dup->next = ret;
	return (ret);
}

void	carlist_del(t_car **car)
{
	if (car && *car)
	{
		if ((*car)->prev)
			(*car)->prev->next = NULL;
		while (*car)
			car_del(car);
	}
}

void	carlist_del_until_nl(t_car **car)
{
	if (car && *car && (*car)->val && (*car)->val != '\n')
	{
		if ((*car)->prev)
			(*car)->prev->next = NULL;
		while (*car && (*car)->val && (*car)->val != '\n')
			car_del(car);
	}
}
