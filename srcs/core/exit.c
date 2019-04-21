/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 17:28:32 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/11 14:02:41 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	shell_exit(int ret)
{
	t_data *data;

	data = get_data();
	reset_shell(data);
	free(data);
	exit(ret);
}
