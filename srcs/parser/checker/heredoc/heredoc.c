/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 22:32:14 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/29 19:50:59 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	get_heredoc(t_data *data, t_token *tok)
{
	int		is_quoted;
	char	*path;
	char	*key;
	int		fd;

	if (tok && tok->valid == 1)
	{
		key = try_m(ft_itoa((int)tok));
		path = try_m(ft_strjoinfs("/tmp/.42sh-thd-", key, FT_ARG2));
		if ((fd = open(path, O_WRONLY | O_CREAT | O_EXCL | O_TRUNC, 0600)) >= 0)
		{
			if ((is_quoted = has_quotes_or_backslash(tok->val)))
				exp_quotes(tok->val);
			write(fd, is_quoted ? "'" : "\"", 1);
			compose_heredoc(data, tok, is_quoted, fd);
			close(fd);
		}
		tok->valid = (int)tok;
		ft_strdel(&path);
	}
}
