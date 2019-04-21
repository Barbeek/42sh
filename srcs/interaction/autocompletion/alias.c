/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alias.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 12:12:44 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/17 18:41:22 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	complete_from_alias(t_edl *edl, char **alias, t_token *tok)
{
	char	*suffix;
	char	*suggest;
	int		i;
	int		j;

	i = 0;
	while (alias[i] && edl->sugg.len < 102)
	{
		if (ft_strnequ(tok->val, alias[i], tok->length))
		{
			j = ft_indexof('=', alias[i]);
			suggest = try_m(ft_strsub(alias[i], 0, j));
			suffix = try_m(ft_strjoin(suggest, " "));
			set_compl_suffix(edl->sugg.list, suffix + tok->length);
			ft_strdel(&suffix);
			ft_strtabadd(&edl->sugg.list, suggest) && try_m(edl->sugg.list);
			++edl->sugg.len;
			edl->sugg.max = (edl->sugg.max < j ? j : edl->sugg.max);
		}
		++i;
	}
}
