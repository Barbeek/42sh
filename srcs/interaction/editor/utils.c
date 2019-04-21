/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroblin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 21:20:35 by aroblin           #+#    #+#             */
/*   Updated: 2019/03/30 01:59:43 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

size_t	str_to_carlist(t_car **car, char *line)
{
	size_t	len;

	if (!line)
		return (0);
	*car = car_new();
	len = 0;
	(*car)->next = (*car);
	(*car)->prev = (*car);
	while (*line)
	{
		insert_car(*car, *line);
		++len && ++line;
	}
	return (len);
}

char	*carlist_to_str(t_data *data)
{
	t_car	*car;
	char	*ret;
	int		i;

	try_m(ret = ft_stralloc(data->edl.len));
	i = 0;
	car = data->edl.last->next;
	while (car && (ret[i++] = car->val))
		car = car->next;
	return (ret);
}
