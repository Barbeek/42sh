/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 08:38:11 by hwolff            #+#    #+#             */
/*   Updated: 2019/03/30 00:50:19 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	reset_term(t_data *data, int mode)
{
	tcsetattr(STDIN_FILENO, mode, &data->term_dft_config);
}

int		reset_shell(t_data *data)
{
	int ret;

	if (data)
	{
		ret = data->param.status;
		if (isatty(FD_EDL))
			reset_term(data, TCSAFLUSH);
		free_jobs();
		reset_subshell(data);
		return (ret);
	}
	return (OK);
}

void	reset_subshell(t_data *data)
{
	reset_command(data);
	if (data->env)
		ft_strtabdel(&data->env);
	if (data->tmpenv)
		ft_strtabdel(&data->tmpenv);
	if (data->loc)
		ft_strtabdel(&data->loc);
	if (data->arguments)
		ft_strdel(&data->arguments);
	if (data->edl.hist.list)
		ft_strtabdel(&data->edl.hist.list);
	if (data->hashtable->size)
		h_table_free(data->hashtable);
	ft_strtabdel(&data->alias);
	ft_strtabdel(&data->spe);
	ft_strtabdel(&data->param.av);
	ft_strtabdel(&data->tmpenv);
	reset_edl(&data->edl);
}

void	reset_edl(t_edl *edl)
{
	ft_strdel(&edl->line);
	ft_strdel(&edl->hist.tmpline);
	carlist_del(&edl->last);
	carlist_del(&edl->clip);
	edl->bef = NULL;
	edl->cur = NULL;
	edl->select_ori = NULL;
	edl->len = 0;
	edl->select_mode = 0;
	edl->enter = 0;
	ft_strtabdel(&edl->sugg.list);
}

void	reset_command(t_data *data)
{
	t_data_jobs *djobs;

	djobs = get_data_jobs();
	tokenlist_del(&data->token);
	tokenlist_del(&djobs->token_list);
	ft_strdel(&data->command);
	data->param.cancel = 0;
	data->edl.hist.cur = 0;
	reset_edition_current_line(&data->edl);
	data->edl.tabul = 0;
	data->edl.eof = 0;
	data->edl.incomp_type = INC_EMPTY;
}
