/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_job_name.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroblin <aroblin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 07:11:19 by aroblin           #+#    #+#             */
/*   Updated: 2019/03/25 21:56:07 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void		join_cmd(char **str, t_token *tmp_tok)
{
	char			*tmp;

	tmp = NULL;
	if (!(*str))
		try_m(*str = ft_strdup(tmp_tok->val));
	else
	{
		tmp = *str;
		try_m(*str = ft_strjoin3(*str, " ", tmp_tok->val));
		ft_strdel(&tmp);
	}
}

static void		check_sub(int *sub, t_token *tmp_tok)
{
	if (tmp_tok->type == OP_PAR)
		*sub = 1;
	else if (tmp_tok->type == CL_PAR)
		*sub = 0;
}

void			get_job_name(char **str)
{
	t_data_jobs		*djobs;
	t_token			*tmp_tok;
	int				sub;

	sub = 0;
	djobs = get_data_jobs();
	tmp_tok = NULL;
	if (djobs->token_list)
	{
		tmp_tok = djobs->current_token;
		while (tmp_tok)
		{
			check_sub(&sub, tmp_tok);
			if (((tmp_tok->type == SEMICOLON || tmp_tok->type == AND
				|| ft_strequ(tmp_tok->val, "\n"))) && sub == 0)
			{
				djobs->current_token = tmp_tok->next;
				break ;
			}
			join_cmd(str, tmp_tok);
			tmp_tok = tmp_tok->next;
		}
	}
}
