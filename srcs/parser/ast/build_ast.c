/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_ast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolff <hwolff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 08:46:19 by hwolff            #+#    #+#             */
/*   Updated: 2019/03/27 20:00:45 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void
	add_node(t_data *data, t_ast **ast, t_token *beginlist1)
{
	t_token *chosen_prev;
	t_token *chosen;
	int		type;

	if (!ast || !beginlist1)
		return ;
	chosen_prev = NULL;
	if (!(chosen = get_primary_prev_token(&chosen_prev, beginlist1)))
		return ;
	type = chosen->type;
	if (chosen_prev)
		chosen_prev->next = NULL;
	else
		beginlist1 = NULL;
	fill_node(ast, &chosen, &chosen_prev, &beginlist1);
	if (beginlist1)
		add_node(data, &(*ast)->left, beginlist1);
	if (chosen)
		add_node(data, &(*ast)->right, chosen);
}

void
	build_ast(t_data *data)
{
	data->ast = NULL;
	if (data->token)
		add_node(data, &data->ast, data->token);
	data->token = NULL;
	is_option_d(data) && print_ast(data->ast);
}
