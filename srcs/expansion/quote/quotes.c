/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 08:54:57 by hwolff            #+#    #+#             */
/*   Updated: 2019/03/24 12:58:11 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char	*expand_dquote(char *line)
{
	char *end;

	end = ft_strmove(line, line + 1);
	while (*end && *end != '"')
	{
		if (*end == '\\'
			&& (*(end + 1) == '$' || *(end + 1) == '`'
			|| *(end + 1) == '"' || *(end + 1) == '\\'))
			ft_strmove(end, end + 1);
		else if (*end == '\\' && *(end + 1) == '\n')
			ft_strmove(end, end + 2);
		else
			++end;
	}
	if (*end == '\"')
		ft_strmove(end, end + 1);
	return (end);
}

char	*expand_quote(char *line)
{
	char *end;

	ft_strmove(line, line + 1);
	if ((end = ft_strchr(line, '\'')))
		ft_strmove(end, end + 1);
	return (end);
}

void	exp_quotes(char *line)
{
	if (!line)
		return ;
	while (line && *line)
	{
		if (*line == '\\' && *(line + 1))
		{
			ft_strmove(line, line + 1);
			++line;
		}
		else if (*line == '\'')
			line = expand_quote(line);
		else if (*line == '"')
			line = expand_dquote(line);
		else
			++line;
	}
}
