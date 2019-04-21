/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 19:18:56 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/29 12:08:44 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	field_split(t_token **tok)
{
	t_token	*new;
	t_token	*next;

	if (*(*tok)->val && ft_strchr((*tok)->val, ' '))
	{
		new = NULL;
		lexical_analysis(&new, (*tok)->val);
		ft_strdel(&(*tok)->val);
		next = (*tok)->next;
		(*tok)->val = new->val;
		(*tok)->type = new->type;
		(*tok)->length = new->length;
		(*tok)->next = new->next;
		free(new);
		new = get_last_token(*tok);
		new->next = next;
	}
}
