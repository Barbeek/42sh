/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delimitor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 17:39:16 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/23 12:03:16 by pespalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static const int	g_delim[4][15] = {
	{TRIPLELESS, TRIPLEGREAT, DOUBLELESSDASH, DOUBLELESSAND, DOUBLEGREATAND,
		ANDDOUBLEGREAT, ANDDOUBLELESS, DOUBLESEMICOLONAND, 0},
	{DOUBLEAND, DOUBLEPIPE, DOUBLESEMICOLON, DOUBLELESS, DOUBLEGREAT, LESSGREAT,
		LESSAND, GREATAND, ANDGREAT, ANDLESS, GREATPIPE, PIPEAND, SEMICOLONAND,
		0},
	{PIPE, AND, SEMICOLON, LESS, GREAT, OP_PAR, CL_PAR, NEWLINE, BANG, 0},
	{0}};

static t_token
	*get_after_op_token(char **line)
{
	t_token	*token;
	char	*l;
	char	c;

	c = **line;
	if (**line == '{' || **line == '}' || **line == '!')
	{
		l = *line + 1;
		if (sh_isspace(*l))
		{
			*line = l;
			return (token_new(&c, 1, (int)(c % 256), NULL));
		}
		skip_spaces(&l);
		if ((token = get_delimitor_token(&l, 1)))
		{
			*line = l;
			return (token_new(&c, 1, (int)(c % 256), token));
		}
	}
	return (NULL);
}

static t_token
	*get_operators_token(char **line)
{
	int		op;
	int		i;
	int		j;

	i = -1;
	op = 0;
	while (++i < 3 && *(*line + i))
		op += *(*line + i) << (8 * i);
	i = 0;
	while (g_delim[i][0])
	{
		j = 0;
		while (g_delim[i][j])
		{
			if (g_delim[i][j] == (op & (0xFFFFFF >> (8 * i))))
			{
				*line += 3 - i;
				return (token_new((char *)&op, 3 - i, g_delim[i][j], NULL));
			}
			++j;
		}
		++i;
	}
	return (NULL);
}

static t_token
	*get_io_number_token(char **line)
{
	t_token	*new;
	size_t	len;

	new = NULL;
	if (ft_isdigit(**line))
	{
		len = 1;
		while (ft_isdigit(*(*line + len)))
			++len;
		if (*(*line + len) == '<' || *(*line + len) == '>')
		{
			new = token_new(*line, len, IO_NUMBER, NULL);
			*line = *line + len;
		}
	}
	return (new);
}

t_token
	*get_delimitor_token(char **line, size_t wordlen)
{
	t_token *new;

	if ((!wordlen && (new = get_after_op_token(line)))
		|| (new = get_operators_token(line))
		|| (new = get_io_number_token(line)))
		;
	return (new);
}
