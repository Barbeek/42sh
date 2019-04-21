/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 18:59:41 by hwolff            #+#    #+#             */
/*   Updated: 2019/03/30 01:46:12 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	word_expansion(t_data *data, t_token *tok)
{
	if (tok)
	{
		exp_tilde(&tok->val, data);
		exp_vars(&tok->val, data, 0);
		exp_substit_cmd(&tok->val, data);
		exp_arithmetic(&tok->val, data);
		if (data->param.cancel)
			return ;
		field_split(&tok);
		exp_quotes(tok->val);
	}
}

void	heredoc_expansion(t_data *data, char **heredoc)
{
	exp_vars(heredoc, data, 1);
	exp_substit_cmd(heredoc, data);
	exp_arithmetic(heredoc, data);
}

void	heredoc_rewrite_expansion(t_data *data, t_token *tok)
{
	char	*path;
	char	*text;
	int		fd;
	char	quote;

	path = try_m(ft_strjoinfs("/tmp/.42sh-thd-",
		try_m(ft_itoa((int)tok->valid)), FT_ARG2));
	if ((fd = open(path, O_RDONLY)))
	{
		if ((text = read_heredoc(fd)))
		{
			close(fd);
			quote = *text;
			if (text[0] == '\'' || text[0] == '"')
				ft_strmove(text, text + 1);
			if (quote != '\'')
				heredoc_expansion(data, &text);
			if ((fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0600)))
				ft_putstr_fd(text, fd);
		}
		close(fd);
	}
	ft_strdel2(&path, &text);
}

void	redirection_file_expansion(t_data *data, t_token *tok)
{
	if (tok)
	{
		exp_tilde(&tok->val, data);
		exp_vars(&tok->val, data, 0);
		exp_substit_cmd(&tok->val, data);
		exp_arithmetic(&tok->val, data);
		if (data->param.cancel)
			return ;
		exp_quotes(tok->val);
	}
}

void	expansion(t_data *data, t_ast *ast)
{
	t_token *tok;

	if (!ast || ast->token->type == OP_PAR)
		return ;
	if (ast->token->type == DOUBLELESS)
		heredoc_rewrite_expansion(data, ast->right_arg);
	else if (is_redir_op(ast->token->type))
		redirection_file_expansion(data, ast->right_arg);
	else if (is_word(ast->token->type))
	{
		tok = ast->token;
		while (tok)
		{
			word_expansion(data, tok);
			tok = tok->next;
		}
	}
}
