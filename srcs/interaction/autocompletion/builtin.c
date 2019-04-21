/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 20:52:49 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/20 11:46:01 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	complete_from_builtin(t_edl *edl, t_token *tok)
{
	char	**bt_list;
	char	*str;
	int		i;
	int		j;

	i = 0;
	bt_list = get_builtins_list();
	while (bt_list[i] && edl->sugg.len < 102)
	{
		if (ft_strnequ(tok->val, bt_list[i], tok->length))
		{
			set_compl_suffix(edl->sugg.list, (char *)bt_list[i] + tok->length);
			j = ft_strlen(bt_list[i]);
			try_m(str = ft_strsub(bt_list[i], 0, j));
			ft_strtabadd(&edl->sugg.list, str) && try_m(edl->sugg.list);
			++edl->sugg.len;
			edl->sugg.max = (edl->sugg.max < j ? j : edl->sugg.max);
		}
		++i;
	}
}
