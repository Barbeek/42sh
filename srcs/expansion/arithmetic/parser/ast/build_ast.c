/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_ast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 17:42:09 by hwolff            #+#    #+#             */
/*   Updated: 2019/03/23 13:04:33 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void
	arith_add_node(t_data *data, t_ast **ast, t_token *beginlist)
{
	t_token *chosen_prev;
	t_token *chosen;
	int		type;

	if (!ast || !beginlist)
		return ;
	arith_remove_parentheses(&beginlist);
	chosen_prev = NULL;
	if (!(chosen = arith_get_primary_prev_token(&chosen_prev, beginlist)))
		return ;
	type = chosen->type;
	if (chosen_prev)
		chosen_prev->next = NULL;
	else
		beginlist = NULL;
	arith_fill_node(ast, &chosen);
	if (beginlist)
		arith_add_node(data, &(*ast)->left, beginlist);
	if (chosen)
		arith_add_node(data, &(*ast)->right, chosen);
}

void
	arith_build_ast(t_data *data, t_ast **ast, t_token **token)
{
	if (token && *token)
		arith_add_node(data, ast, *token);
	*token = NULL;
	is_option_d(data) && print_ast(*ast);
}
