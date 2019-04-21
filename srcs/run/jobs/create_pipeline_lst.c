/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pipeline_lst.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroblin <aroblin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 16:59:18 by aroblin           #+#    #+#             */
/*   Updated: 2019/03/14 19:59:27 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void		create_pipeline_lst(t_list **lst, t_ast *ast)
{
	t_list	*new;

	if (!ast)
		return ;
	if (ast->token->type == PIPE)
	{
		if (ast->left)
		{
			try_m(new = ft_lstnew(ast->left, sizeof(t_ast)));
			if (!(*lst))
				*lst = new;
			else
				lstaddend(lst, new);
		}
		if (ast->right)
			create_pipeline_lst(lst, ast->right);
	}
	else
	{
		try_m(new = ft_lstnew(ast, sizeof(t_ast)));
		if (!(*lst))
			*lst = new;
		else
			lstaddend(lst, new);
	}
}
