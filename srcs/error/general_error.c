/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 18:32:12 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/19 17:32:56 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		put_error(int ret, char *message)
{
	if (message)
	{
		ft_putstr_fd(""SH_NAME"", FD_ERR);
		ft_putendl2_fd(": ", message, FD_ERR);
	}
	return (ret);
}

int		put_error2(int ret, char *info, char *message)
{
	if (message)
	{
		ft_putstr_fd(""SH_NAME"", FD_ERR);
		if (info)
			ft_putstr2_fd(": ", info, FD_ERR);
		ft_putendl2_fd(": ", message, FD_ERR);
	}
	return (ret);
}

int		put_error3(int ret, char *info1, char *info2, char *message)
{
	if (message)
	{
		ft_putstr_fd(""SH_NAME"", FD_ERR);
		if (info1)
			ft_putstr2_fd(": ", info1, FD_ERR);
		if (info2)
			ft_putstr2_fd(": ", info2, FD_ERR);
		ft_putendl2_fd(": ", message, FD_ERR);
	}
	return (ret);
}
