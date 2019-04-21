/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_tilde.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 08:54:47 by hwolff            #+#    #+#             */
/*   Updated: 2019/03/07 07:45:55 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int			exp_tilde(char **str, t_data *data)
{
	char		*tmp;
	char		*home;

	if ((*str)[0] == '~' && ((*str)[1] == '/' || !(*str)[1]))
	{
		if ((home = get_val(data->env, "HOME")))
		{
			tmp = *str;
			(*str) = ft_strjoin(home, tmp + 1);
			free(tmp);
		}
	}
	return (1);
}
