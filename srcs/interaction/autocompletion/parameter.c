/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parameter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 20:50:22 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/17 18:41:05 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	complete_from_tab_param(t_edl *edl, char **arr, char *key, int len)
{
	char	*suffix;
	char	*suggest;
	int		i;
	int		j;
	char	c;

	i = 0;
	c = *(key++);
	while (arr[i] && edl->sugg.len < 102)
	{
		if (ft_strnequ(key, arr[i], len))
		{
			j = ft_indexof('=', arr[i]);
			suggest = try_m(ft_strsub(arr[i], 0, j));
			suffix = try_m(ft_strjoin(suggest, (c == '{' ? "} " : " ")));
			set_compl_suffix(edl->sugg.list, suffix + len);
			ft_strdel(&suffix);
			ft_strtabadd(&edl->sugg.list, suggest) && try_m(edl->sugg.list);
			++edl->sugg.len;
			edl->sugg.max = (edl->sugg.max < j ? j : edl->sugg.max);
		}
		++i;
	}
}

void	complete_parameter(t_data *data, t_edl *edl, t_token *tok)
{
	char	*n;
	int		len;

	if ((n = ft_strrchr(tok->val, '$')))
	{
		if (*(n + 1) == '{')
			++n;
		len = ft_strlen(n + 1);
		complete_from_tab_param(edl, data->env, n, len);
		complete_from_tab_param(edl, data->loc, n, len);
	}
}
