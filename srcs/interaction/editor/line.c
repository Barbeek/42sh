/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 13:42:00 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/29 21:12:12 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	add_line_to_history(t_edl *edl)
{
	char *dup;

	if (!edl->line || !*edl->line || *edl->line == '\n')
		return ;
	try_m(dup = ft_strdup(edl->line));
	if (edl->incomp_type > 1)
	{
		try_m(dup = ft_strjoin3fs(edl->hist.list[edl->hist.count - 1],
			"\n", remove_last_newline(dup), FT_ARG1 | FT_ARG3));
		edl->hist.list[edl->hist.count - 1] = remove_esc_newlines(dup);
	}
	else
	{
		if (!(ft_strtabadd(&(edl->hist.list), remove_last_newline(dup))))
			try_m(edl->hist.list);
		++edl->hist.count;
	}
}

void	add_line_to_command(t_data *data)
{
	remove_esc_newlines(data->edl.line);
	if (!data->command)
		try_m(data->command = ft_strdup(data->edl.line));
	else
		try_m(data->command = ft_strjoinfs(data->command, data->edl.line,
			FT_ARG1));
}

void	add_line_to_heredoc(t_data *data, int fd, int is_quoted)
{
	if (!is_quoted)
		remove_heredoc_esc_newlines(data->edl.line);
	ft_putstr_fd(data->edl.line, fd);
}

void	save_line(t_data *data)
{
	if (data->edl.line && *data->edl.line)
	{
		add_line_to_history(&data->edl);
		add_line_to_command(data);
	}
	ft_strdel(&data->edl.line);
}
