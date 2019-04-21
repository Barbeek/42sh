/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 21:20:11 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/30 02:40:44 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void	(*g_actions[])(t_data *) = {do_tabulation, do_delete, do_arrow_up,
	do_arrow_down, do_arrow_left, do_arrow_right, do_home, do_end,
	do_shift_up, do_shift_down, do_shift_tab, do_shift_left,
	do_shift_right, do_alt_left, do_alt_right, do_alt_x, do_alt_c,
	do_alt_v, 0};

static void	(*g_spechar_actions[])(t_data *) = {do_enter, do_backspace,
	do_ctrl_d, 0};

static unsigned long	g_keys[] = {K_TAB, K_DEL, K_UP, K_DOWN, K_LEFT, K_RIGHT,
	K_HOME, K_END, K_SH_UP, K_SH_DOWN, K_SHIFT_TAB, K_SH_LEFT,
	K_SH_RIGHT, K_ALT_LEFT, K_ALT_RIGHT, K_ALT_X,
	K_ALT_C, K_ALT_V, 0};

static char	g_spechar[] = {K_ENTER, K_BACKDEL, K_CTRL_D, 0};

void			routine_input(t_data *data, char c, int i)
{
	leave_select_mode(&data->edl, 1);
	data->edl.bef = data->edl.cur->prev;
	if (g_spechar[i])
		(*g_spechar_actions[i])(data);
	else
		insert_car_to_editline(&data->edl, c);
	update_view(&data->edl);
}

void			handle_input(t_data *data, unsigned long key)
{
	int		i;
	char	c;

	i = 0;
	if (key != K_TAB)
		data->edl.tabul = 0;
	while (g_keys[i] && key != g_keys[i])
		++i;
	if (g_keys[i])
		(*g_actions[i])(data);
	else
	{
		while ((c = key % 256))
		{
			key /= 256;
			i = 0;
			while (g_spechar[i] && c != g_spechar[i])
				++i;
			routine_input(data, c, i);
		}
	}
}

static void		compose_line(t_data *data)
{
	unsigned long	key;
	int				len;

	while (!(key = 0) && !data->param.cancel && !data->edl.eof
		&& !data->edl.enter && (len = read(1, &key, sizeof(key)) > 0))
		handle_input(data, key);
	if (!data->param.cancel)
		data->edl.line = carlist_to_str(data);
}

void			compose_heredoc(t_data *data, t_token *token
		, int is_quoted, int fd)
{
	char *heredoc;

	heredoc = NULL;
	signal(SIGINT, here_edl_sigint_handler);
	data->edl.incomp_type = INC_HER;
	while (data->edl.incomp_type)
	{
		set_prompt(&data->edl);
		display_prompt(&data->edl);
		init_edl(&data->edl);
		compose_line(data);
		if (data->param.cancel)
			break ;
		if ((data->edl.incomp_type = check_heredoc(data, token)))
			add_line_to_heredoc(data, fd, is_quoted);
		reset_edition_current_line(&data->edl);
	}
	signal(SIGINT, signal_handler);
}

void			compose_command(t_data *data)
{
	init_term(data, TCSAFLUSH);
	signal(SIGINT, edl_sigint_handler);
	while (check_command(data))
	{
		if (!data->param.cancel)
		{
			set_prompt(&data->edl);
			display_prompt(&data->edl);
			init_edl(&data->edl);
		}
		else
			data->param.cancel = 0;
		compose_line(data);
		save_line(data);
		reset_edition_current_line(&data->edl);
	}
	signal(SIGINT, signal_handler);
	reset_term(data, TCSANOW);
	token_list_dup_for_jobctrl(data->token);
}
