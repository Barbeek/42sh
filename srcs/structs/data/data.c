/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 18:25:38 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/04 17:28:09 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

t_data	*get_data(void)
{
	static t_data	*data = NULL;

	if (!data)
		try_m(data = (t_data *)ft_memalloc(sizeof(t_data)));
	return (data);
}
