/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_walker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 20:36:28 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/19 17:24:00 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

t_token		*get_next_relevant_token(t_token *token)
{
	token = token->next;
	while (token && token->type == NEWLINE)
		token = token->next;
	return (token);
}

t_token		*get_last_token(t_token *token)
{
	if (!token)
		return (NULL);
	while (token->next)
		token = token->next;
	return (token);
}

int			next_token(t_token **token)
{
	return ((*token = (*token)->next) || 0);
}

int			count_token(t_token *token)
{
	int		i;

	i = 0;
	while (token)
	{
		++i;
		token = token->next;
	}
	return (i);
}
