/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 21:25:48 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/29 19:16:21 by pespalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

t_token
	*token_new(char *val, size_t length, int type, t_token *next)
{
	t_token *new;

	try_m((new = (t_token*)ft_memalloc(sizeof(t_token))));
	try_m((new->val = ft_strsub(val, 0, length)));
	new->length = length;
	new->type = type;
	new->next = next;
	return (new);
}

t_token
	*token_dup(t_token *tok)
{
	t_token *new;

	try_m(new = ft_memalloc(sizeof(t_token)));
	if (tok->val)
		try_m(new->val = ft_strdup(tok->val));
	new->length = tok->length;
	new->type = tok->type;
	new->valid = tok->valid;
	new->next = NULL;
	return (new);
}

void
	token_del(t_token **tok)
{
	t_token *todel;

	if (tok && *tok)
	{
		todel = *tok;
		*tok = (*tok)->next;
		ft_strdel(&todel->val);
		todel->next = NULL;
		free(todel);
	}
}
