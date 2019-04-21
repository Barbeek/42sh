/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 16:02:02 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/29 21:17:16 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static t_token
	*get_next_tokens(char **line)
{
	t_token	*delim_token;
	char	*begin;
	size_t	len;

	begin = *line;
	len = 0;
	while (!(delim_token = get_delimitor_token(line, len))
		&& **line && !sh_isspace(**line))
		len += walk_word(line);
	if (len)
		return (token_new(begin, len, WORD, delim_token));
	return (delim_token);
}

void
	lexical_analysis(t_token **token, char *line)
{
	t_token *new;
	t_token *last;

	tokenlist_del(token);
	if (!line)
		return ;
	while (*line)
	{
		skip_spaces(&line);
		if ((new = get_next_tokens(&line)))
		{
			if (!(*token))
				*token = new;
			else if (last)
				last->next = new;
			last = new;
			while (last->next)
				last = last->next;
		}
	}
	check_token_words(*token);
}
