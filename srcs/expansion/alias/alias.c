/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alias.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolff <hwolff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 16:09:59 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/30 00:26:29 by hwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void	init_tok(t_token **tok, t_token *new)
{
	ft_strdel(&(*tok)->val);
	(*tok)->val = new->val;
	(*tok)->type = new->type;
	(*tok)->length = new->length;
	(*tok)->next = new->next;
	(*tok)->valid = new->valid;
}

static void	exp_alias_one(t_data *data, t_token **tok)
{
	t_token *new;
	t_token	*next;
	char	**alias;
	char	*res;

	if ((res = get_val(data->alias, (*tok)->val)))
	{
		new = NULL;
		alias = try_m(ft_strtabdup(data->alias));
		unset_val(&alias, (*tok)->val);
		ft_strtabswap(&alias, &data->alias);
		lexical_analysis(&new, res);
		exp_alias(data, &new);
		ft_strtabswap(&alias, &data->alias);
		ft_strtabdel(&alias);
		next = (*tok)->next;
		init_tok(tok, new);
		free(new);
		new = get_last_token(*tok);
		new->next = next;
		*tok = new;
	}
}

void		exp_alias(t_data *data, t_token **token)
{
	t_token *prev;
	t_token *cur;

	prev = NULL;
	cur = *token;
	while (cur)
	{
		if ((!prev || (prev->type != WORD && !is_redir_op(prev->type)))
			&& cur->type == WORD)
			exp_alias_one(data, &cur);
		prev = cur;
		cur = cur->next;
	}
}
