/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 15:10:33 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/27 15:10:43 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		find_path(t_data *data, char *built)
{
	char	**path;
	int		i;

	if (!ft_strchr(built, '/') && !is_builtin(built))
	{
		if ((path = get_path(data->env, &built)))
		{
			i = 0;
			while (path[i])
			{
				if (access(path[i], F_OK) == 0)
				{
					if (access(path[i], X_OK) == 0)
						ht_put(data->hashtable, built, path[i]);
					ft_strtabdel(&path);
					return (OK);
				}
				++i;
			}
			ft_strtabdel(&path);
			return (ERROR);
		}
	}
	return (OK);
}
