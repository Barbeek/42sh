/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenlist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 12:02:18 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/29 19:43:04 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void
	tokenlist_del(t_token **token)
{
	t_token *tok;
	t_token *tmp;

	if (token && *token)
	{
		tok = *token;
		while (tok)
		{
			tmp = tok;
			ft_strdel(&tmp->val);
			tok = tmp->next;
			free(tmp);
		}
		*token = NULL;
	}
}

size_t
	tokenlist_to_tab(char ***table, t_token *token)
{
	char	**p;
	int		nbword;

	nbword = count_token(token);
	try_m((*table = (char **)ft_memalloc(sizeof(char *) * (nbword + 1))));
	p = *table;
	while (token)
	{
		try_m((*p = ft_strdup(token->val)));
		token = token->next;
		++p;
	}
	return (nbword);
}
