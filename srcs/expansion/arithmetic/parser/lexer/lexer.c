/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 17:42:09 by hwolff            #+#    #+#             */
/*   Updated: 2019/03/29 19:29:05 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static t_token
	*arith_get_number_token(char **line)
{
	t_token	*delim_token;
	char	*begin;
	size_t	len;

	begin = (*line)++;
	len = 1;
	while (!(delim_token = arith_get_operators_token(line))
		&& **line && !arith_isspace(**line))
	{
		++(*line);
		++len;
	}
	return (token_new(begin, len, NUMBER, delim_token));
}

static t_token
	*arith_get_leftover(char **line)
{
	t_token	*tok;
	size_t	len;

	tok = NULL;
	len = 0;
	while ((*line)[len])
		++len;
	if (len)
	{
		tok = token_new(*line, len, INVALID, NULL);
		(*line) += len;
	}
	return (tok);
}

static t_token
	*arith_get_next_tokens(char **line)
{
	t_token *tok;

	if (!**line)
		return (NULL);
	if (**line == '_' || ft_isalpha(**line))
		return (arith_get_variable_token(line, 1));
	else if (ft_isdigit(**line))
		return (arith_get_number_token(line));
	else if (**line && (tok = arith_get_operators_token(line)))
		return (tok);
	return (arith_get_leftover(line));
}

void
	arith_lexical_analysis(t_token **token, char *line)
{
	t_token *new;
	t_token *last;

	if (!line)
		return ;
	while (*line)
	{
		arith_skip_spaces(&line);
		if ((new = arith_get_next_tokens(&line)))
		{
			if (!(*token))
			{
				*token = new;
				last = new;
			}
			else if (last)
			{
				last->next = new;
				last = new;
			}
			while (last->next)
				last = last->next;
		}
	}
}
