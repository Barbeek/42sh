/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 16:29:29 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/19 16:34:19 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		get_prompt_position(t_edl *edl)
{
	char	buff[8];
	char	*cur;

	ft_bzero((char *)buff, 5);
	write(FD_OUT, "\033[6n", 4);
	read(FD_IN, buff, 8);
	if ((cur = ft_strchr((char *)buff, '[')) && *cur)
	{
		edl->prompt.v = ft_atoi(++cur) - 1;
		cur = ft_strchr(cur, ';');
		if (cur && *cur)
			edl->prompt.h = ft_atoi(++cur) - 1;
	}
	tc_clear_down();
	return (OK);
}
