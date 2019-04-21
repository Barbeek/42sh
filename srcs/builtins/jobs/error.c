/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 14:11:12 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/26 22:33:28 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int			print_bad_job(int id, char *str)
{
	int		ret;

	ret = 0;
	if (id == 0 && str)
	{
		ret = EXIT_FAILURE;
		ft_putstr3(""SH_NAME": jobs:", str, ": no such job\n");
	}
	else if (id == -1)
	{
		ret = EXIT_FAILURE;
		ft_putstr3(""SH_NAME": jobs:", str, ": ambiguous job spec\n");
	}
	return (ret);
}
