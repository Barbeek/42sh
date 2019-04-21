/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_operators_lst.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 19:59:06 by ndubouil          #+#    #+#             */
/*   Updated: 2019/03/26 19:20:58 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void		create_operator(t_list **lst, t_ast *ast, int prev)
{
	t_list		*new;
	t_pipeline	*content;
	t_list		*pipeline;

	pipeline = NULL;
	new = NULL;
	try_m(content = ft_memalloc(sizeof(t_pipeline)));
	content->prev_operator = prev;
	create_pipeline_lst(&pipeline, ast);
	content->pipeline = pipeline;
	try_m(new = ft_lstnew(&content, sizeof(t_pipeline **)));
	(!(*lst)) ? *lst = new : lstaddend(lst, new);
}

void			create_operators_lst(t_list **lst, t_ast *ast, int prev)
{
	if (!ast)
		return ;
	if (ast->token->type == OP_BRA || ast->token->type == CL_BRA
		|| ast->token->type == SEMICOLON)
	{
		if (ast->left)
			create_operators_lst(lst, ast->left, 0);
		if (ast->right)
			create_operators_lst(lst, ast->right, 0);
	}
	else if (ast->token->type == DOUBLEAND || ast->token->type == DOUBLEPIPE)
	{
		if (ast->left)
			create_operators_lst(lst, ast->left, 0);
		if (ast->right)
			create_operators_lst(lst, ast->right, ast->token->type);
	}
	else
		create_operator(lst, ast, prev);
}
