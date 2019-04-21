/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 17:11:33 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/29 19:54:22 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void	fill_node_io_number(t_ast **ast, t_token **chosen,
			t_token **prev, t_token **beginlist)
{
	(*ast)->left_arg = token_dup(*chosen);
	token_del(chosen);
	(*ast)->token = token_dup(*chosen);
	token_del(chosen);
	if (*chosen
		&& ((*chosen)->type == IO_NUMBER
		|| (*chosen)->type == WORD))
	{
		(*ast)->right_arg = token_dup(*chosen);
		token_del(chosen);
	}
	if (*prev)
		(*prev)->next = *chosen;
	else
		*beginlist = *chosen;
	*chosen = NULL;
}

static void	fill_node_redir_agreg(t_ast **ast, t_token **chosen,
			t_token **prev, t_token **beginlist)
{
	(*ast)->token = token_dup(*chosen);
	token_del(chosen);
	if (*chosen)
	{
		(*ast)->right_arg = token_dup(*chosen);
		token_del(chosen);
	}
	if (*prev)
		(*prev)->next = *chosen;
	else
		*beginlist = *chosen;
	*chosen = NULL;
}

void		fill_node(t_ast **ast, t_token **chosen,
				t_token **prev, t_token **beginlist)
{
	try_m((*ast = (t_ast *)ft_memalloc(sizeof(t_ast))));
	if ((*chosen)->type == OP_PAR || (*chosen)->type == WORD)
	{
		(*ast)->token = *chosen;
		extract_parentheses(*chosen, prev);
		*chosen = NULL;
	}
	else if ((*chosen)->type == IO_NUMBER)
		fill_node_io_number(ast, chosen, prev, beginlist);
	else if (is_redir_op((*chosen)->type))
		fill_node_redir_agreg(ast, chosen, prev, beginlist);
	else
	{
		(*ast)->token = token_dup(*chosen);
		token_del(chosen);
		if (*prev)
			(*prev)->next = NULL;
	}
}
