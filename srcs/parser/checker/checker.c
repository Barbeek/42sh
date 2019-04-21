/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 20:48:44 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/29 21:27:39 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int			get_incomp_type(int type)
{
	if (type == DOUBLEPIPE)
		return (INC_OR);
	if (type == DOUBLEAND)
		return (INC_AND);
	if (type == PIPE)
		return (INC_PIP);
	if (type == OP_PAR)
		return (INC_PAR);
	if (type == OP_BRA)
		return (INC_BRA);
	return (COMPLETE);
}

t_token		*check_command_lex(t_data *data, t_token *token)
{
	t_token	*t;

	t = token;
	check_is_program(data, &t);
	while (token && token->valid)
		token = token->next;
	return (token);
}

int			check_heredoc(t_data *data, t_token *tok)
{
	char	*line;
	size_t	len;

	if (data->edl.eof)
	{
		if (data->edl.incomp_type == INC_HER)
			return (data->edl.incomp_type = COMPLETE);
		if (data->edl.incomp_type == INC_HER_BKS)
			return (data->edl.incomp_type = INC_HER);
	}
	else if (!data->edl.line)
		return (data->edl.incomp_type = INC_HER);
	len = ft_strlen(data->edl.line);
	try_m(line = ft_strsub(data->edl.line, 0, len - 1));
	if (len > 1 && line[len - 2] == '\\')
		data->edl.incomp_type = INC_HER_BKS;
	else if (data->edl.incomp_type != INC_HER_BKS && ft_strequ(tok->val, line))
	{
		ft_strdel(&line);
		return (data->edl.incomp_type = COMPLETE);
	}
	else
		data->edl.incomp_type = INC_HER;
	ft_strdel(&line);
	return (data->edl.incomp_type);
}

static int	init_check_command(t_data *data, t_token **error_tok)
{
	if (!data->command)
		return (data->edl.incomp_type = INC_EMPTY);
	lexical_analysis(&data->token, data->command);
	exp_alias(data, &data->token);
	is_option_d(data) && print_lex(data->token, "LEXICAL ANALYSIS");
	*error_tok = check_command_lex(data, data->token);
	if (data->param.cancel)
		return (data->edl.incomp_type = INC_EMPTY);
	return (0);
}

int			check_command(t_data *data)
{
	t_token *error_tok;
	int		ret;

	if ((ret = init_check_command(data, &error_tok)) != 0)
		return (ret);
	if (error_tok)
	{
		data->param.cancel = 1;
		data->param.status = syntax_error(error_tok->val, 0);
	}
	else
	{
		data->edl.incomp_type = check_incomplete_type(data->token
			, data->edl.eof);
		if (data->edl.incomp_type > INC_EMPTY
			&& (data->edl.eof || !data->param.interactive))
		{
			data->param.cancel = 1;
			data->param.status = unexpected_eof_error(data->edl.incomp_type);
		}
		else
			return (data->edl.incomp_type);
	}
	return (data->edl.incomp_type = COMPLETE);
}
