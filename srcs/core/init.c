/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 17:27:38 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/29 19:09:20 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/*
** Initialisation du shell
** - de la structure data
** - on verifie le terminal
** - on intercepte les signaux
*/

void	init_term(t_data *data, int mode)
{
	struct termios	term;

	term = data->term_dft_config;
	term.c_lflag ^= ICANON | ECHO | CREAD;
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	tcsetattr(FD_EDL, mode, &term);
}

void	set_pwd_var(t_data *data)
{
	char	*s;

	s = try_m(getcwd(NULL, 0));
	set_val(&data->env, "PWD", s);
	ft_strdel(&s);
}

char	*inline_args(int ac, char **av)
{
	char	*ret;
	int		i;

	ret = try_m(ft_strnew(0));
	i = 0;
	while (ret && i < ac)
		ret = try_m(ft_strjoinfs(ret, av[i++], FT_ARG1));
	return (ret);
}

void	set_special_vars(t_data *data, int ac, char **av)
{
	data->param.av = try_m(ft_strtabdup(av));
	data->param.ac = ac;
	data->param.pid = getpid();
}

int		init_shell(t_data *data, int ac, char **av, char **env)
{
	data->env = try_m(ft_strtabdup(env));
	data->edl.hist.list = try_m(ft_strtabnew(0));
	data->loc = try_m(ft_strtabnew(0));
	data->alias = try_m(ft_strtabnew(0));
	data->spe = try_m(ft_strtabnew(0));
	data->tmpenv = try_m(ft_strtabnew(0));
	data->hashtable = ht_create(1);
	if (!isatty(FD_IN))
		data->edl.line = read_input(FD_IN);
	else if (++data->param.interactive && check_terminal(data))
		return (MAJOR_ERROR);
	init_term(data, TCSAFLUSH);
	reset_term(data, TCSANOW);
	check_options(data, ac - 1, av + 1);
	set_pwd_var(data);
	set_special_vars(data, ac, av);
	data->arguments = inline_args(ac, av);
	catch_signals();
	data->param.run = 1;
	return (OK);
}
