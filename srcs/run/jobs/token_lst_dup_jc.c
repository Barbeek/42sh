/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_lst_dup_jc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroblin <aroblin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 16:24:15 by aroblin           #+#    #+#             */
/*   Updated: 2019/03/08 16:25:26 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	token_list_dup_for_jobctrl(t_token *token)
{
	t_data_jobs	*djobs;
	t_token		*tmp;
	t_token		*result;
	t_token		*new;

	new = NULL;
	tmp = token;
	while (tmp)
	{
		if (!new)
		{
			new = token_dup(tmp);
			result = new;
		}
		else
		{
			new->next = token_dup(tmp);
			new = new->next;
		}
		tmp = tmp->next;
	}
	djobs = get_data_jobs();
	djobs->token_list = result;
	djobs->current_token = result;
}
