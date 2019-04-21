/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 14:09:13 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/26 22:34:12 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/*
**   http://pubs.opengroup.org/onlinepubs/9699919799/utilities/bg.html
*/

static void		print_and_put_bg(t_job *tmp)
{
	ft_putstrnbr("[", tmp->id, "] ");
	ft_putstr2(tmp->command, " &\n");
	put_job_in_background(tmp, 1);
}

static int		get_job(char *str, t_data_jobs *djobs, t_job *tmp)
{
	int		id;
	int		ret;

	ret = EXIT_SUCCESS;
	id = 0;
	if (str[0] == '%')
		id = parse_job_id_arg(str, &djobs->jobs);
	else
		id = last_id(&djobs->jobs);
	if (id == 0 && str)
	{
		ft_putstr3(""SH_NAME": bg: ", str, ": no such job\n");
		ret = EXIT_FAILURE;
	}
	else if (id == -1)
	{
		ft_putstr3(""SH_NAME": bg: ", str, ": ambiguous job spec\n");
		ret = EXIT_FAILURE;
	}
	tmp = get_job_by_id(&djobs->jobs, id);
	if (tmp)
		print_and_put_bg(tmp);
	return (ret);
}

static int		check_job(t_job *tmp)
{
	int		ret;

	ret = EXIT_SUCCESS;
	if (tmp && tmp->ground == 0)
		print_and_put_bg(tmp);
	else
	{
		ft_putendl(""SH_NAME": bg: current: no such job");
		ret = EXIT_FAILURE;
	}
	return (ret);
}

int				sh_bg(t_data *data, int ac, char **av)
{
	t_job			*tmp;
	t_data_jobs		*djobs;
	int				id;
	int				i;
	int				ret;

	(void)data;
	(void)ac;
	ret = EXIT_SUCCESS;
	i = 1;
	id = 0;
	djobs = get_data_jobs();
	if (!av[1])
	{
		tmp = get_job_by_id(&djobs->jobs, last_id(&djobs->jobs));
		ret = check_job(tmp);
	}
	while (av[i])
	{
		ret = get_job(av[i], djobs, tmp);
		i++;
	}
	return (ret);
}
