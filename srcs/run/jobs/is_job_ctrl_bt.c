/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_job_ctrl_bt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 16:52:24 by ndubouil          #+#    #+#             */
/*   Updated: 2019/03/08 15:37:59 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		is_job_ctrl_bt(t_ast *ast)
{
	if (!ast)
		return (0);
	if (ast->left)
		return (is_job_ctrl_bt(ast->left));
	if (ast->token->type == WORD)
	{
		if (ft_strequ(ast->token->val, "jobs"))
			return (1);
		else if (ft_strequ(ast->token->val, "bg"))
			return (1);
		else if (ft_strequ(ast->token->val, "fg"))
			return (1);
	}
	if (ast->right)
		return (is_job_ctrl_bt(ast->right));
	return (0);
}
