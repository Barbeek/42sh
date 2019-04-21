/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_terminal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 18:27:23 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/23 18:42:47 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/*
** On check :
** - config du terminal
** - nom du terminal
** - si les standards IO sont bien un terminal
** - si la database contient des entrées pour ce terminal
** - si la databse existe
*/

int		check_terminal(t_data *data)
{
	int		ret;

	if (tcgetattr(FD_EDL, &data->term_dft_config) == -1)
		return (term_error("Could not get terminal config"));
	if (!(data->param.term_name = getenv("TERM"))
		|| ft_strequ(data->param.term_name, "dumb"))
	{
		if (!(set_val(&data->env, "TERM",
									(data->param.term_name = DEFAULT_TERM))))
			return (MAJOR_ERROR);
	}
	if (!isatty(FD_IN) || !isatty(FD_OUT) || !isatty(FD_ERR))
		return (term_error("Standard I/O doesn't refer to a terminal\n"));
	if ((ret = tgetent(NULL, data->param.term_name)) == 0)
		return (tent_error(data->param.term_name));
	else if (ret == -1)
		return (term_error("Termcap database not found\n"));
	return (OK);
}
