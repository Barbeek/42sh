/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delimitor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 17:42:09 by hwolff            #+#    #+#             */
/*   Updated: 2019/03/29 19:28:35 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static const int	g_delim[3][15] = {
	{DOUBLEPLUS, DOUBLEMINUS, DOUBLEAND, DOUBLEPIPE, LESSEQUAL, GREATEQUAL,
		DOUBLEEQUAL, BANGEQUAL, 0},
	{PLUS, MINUS, LESS, GREAT, OP_PAR, CL_PAR, BANG, STAR, PERCENT,
		SLASH, 0},
	{0}};

t_token		*arith_get_crement_token(char **line)
{
	t_token	*tok;

	tok = NULL;
	arith_skip_spaces(line);
	if (**line == '+' && *(*line + 1) == '+')
	{
		tok = token_new(*line, 2, DOUBLEPLUS, NULL);
		(*line) += 2;
	}
	else if (**line == '-' && *(*line + 1) == '-')
	{
		tok = token_new(*line, 2, DOUBLEMINUS, NULL);
		(*line) += 2;
	}
	return (tok);
}

t_token		*arith_get_variable_token(char **line, int check_post_crement)
{
	t_token	*tok;
	size_t	len;

	len = 1;
	while ((*line)[len] == '_' || ft_isalnum((*line)[len]))
		++len;
	tok = token_new(*line, len, VARIABLE, NULL);
	(*line) += len;
	if (check_post_crement)
		tok->next = arith_get_crement_token(line);
	return (tok);
}

t_token		*compare_operator(char **line, int type, int test, int size)
{
	t_token *tok;
	char	*s;

	if (type == (test & (0xFFFF >> (8 * size))))
	{
		*line += 2 - size;
		tok = NULL;
		if (type == DOUBLEMINUS || type == DOUBLEPLUS)
		{
			s = *line;
			arith_skip_spaces(line);
			if (**line == '_' || ft_isalpha(**line))
				tok = arith_get_variable_token(line, 0);
			else
			{
				++size;
				*line = s - 1;
				type = type == DOUBLEMINUS ? MINUS : PLUS;
			}
		}
		return (token_new((char *)&test, 2 - size, type, tok));
	}
	return (NULL);
}

t_token		*arith_get_operators_token(char **line)
{
	int		op;
	int		i;
	int		j;
	t_token *tok;

	i = -1;
	op = 0;
	tok = NULL;
	while (++i < 2 && *(*line + i))
		op += *(*line + i) << (8 * i);
	i = 0;
	while (g_delim[i][0])
	{
		j = 0;
		while (g_delim[i][j])
		{
			if ((tok = compare_operator(line, g_delim[i][j], op, i)))
				return (tok);
			++j;
		}
		++i;
	}
	return (NULL);
}
