/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   completion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 10:39:33 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/29 17:45:27 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int
	get_completion_type(t_token *lex)
{
	t_token	*prev;
	char	*c;

	if (lex)
	{
		prev = NULL;
		while (lex->next && (prev = lex))
			lex = lex->next;
		if ((c = ft_strrchr(lex->val, '$')) && c + 1 && *(c + 1) != '(')
			return (3);
		if (lex->type == WORD || lex->type == ASSIGNEMENT)
			return (1
				+ (prev && (prev->type == WORD || is_redir_op(prev->type))));
	}
	return (0);
}

void
	set_compl_suffix(char **ret, char *res)
{
	size_t	i;

	if (!*ret)
		try_m(*ret = ft_strdup(res));
	else
	{
		i = 0;
		while ((*ret)[i] && res[i] && (*ret)[i] == res[i])
			++i;
		if (i > 0)
			try_m(*ret = ft_strrealloc(*ret, i));
		else
			try_m(*ret = ft_strover(*ret, ft_strnew(0)));
	}
}

void
	autocomplete(t_data *data, char **line)
{
	t_token	*lex;
	t_token	*last;
	int		type;

	if (*line)
	{
		try_m(*line = ft_strjoinfs(*line, "=", FT_ARG1));
		lex = NULL;
		lexical_analysis(&lex, *line);
		is_option_d(data) && print_lex(lex, "AUTOCOMPLETION");
		type = get_completion_type(lex);
		ft_strtabdel(&data->edl.sugg.list);
		ft_bzero(&data->edl.sugg, sizeof(data->edl.sugg));
		try_m(data->edl.sugg.list = ft_strtabnew(1));
		last = get_last_token(lex);
		last->val[--last->length] = 0;
		if (type == 1)
			complete_command(data, &data->edl, last);
		else if (type == 2)
			complete_file(&data->edl, last);
		else if (type == 3)
			complete_parameter(data, &data->edl, last);
		ft_sortstrtab(data->edl.sugg.list + 1);
		tokenlist_del(&lex);
	}
}
