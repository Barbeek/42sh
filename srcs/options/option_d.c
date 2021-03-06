/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 14:52:53 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/12 11:48:27 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		is_option_d(t_data *data)
{
	return ((data->param.options & OP_D) || 0);
}
