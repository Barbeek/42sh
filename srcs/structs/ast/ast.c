/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 15:19:46 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/27 19:58:39 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	astlist_del(t_ast **ast)
{
	if (ast && *ast)
	{
		if ((*ast)->right)
			astlist_del(&(*ast)->right);
		if ((*ast)->right_arg)
			tokenlist_del(&(*ast)->right_arg);
		if ((*ast)->token)
			tokenlist_del(&(*ast)->token);
		if ((*ast)->left_arg)
			tokenlist_del(&(*ast)->left_arg);
		if ((*ast)->left)
			astlist_del(&(*ast)->left);
		ft_memdel((void **)ast);
	}
}
