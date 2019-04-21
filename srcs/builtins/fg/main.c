/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 14:09:13 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/26 22:34:44 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/*
**   http://pubs.opengroup.org/onlinepubs/9699919799/utilities/fg.html
*/

static void	print_and_put_fg(t_job *tmp)
{
	ft_putendl(tmp->command);
	put_job_in_foreground(tmp, 1);
}

static int	print_bad_job_in_fg(int id, char **av)
{
	int		ret;

	ret = 0;
	if (id == 0 && av[1])
	{
		ft_putstr3(""SH_NAME": fg: ", av[1], ": no such job\n");
		ret = EXIT_FAILURE;
	}
	else if (id == -1)
	{
		ft_putstr3(""SH_NAME": fg: ", av[1], ": ambiguous job spec\n");
		ret = EXIT_FAILURE;
	}
	return (ret);
}

static int	print_no_job(void)
{
	int	ret;

	ft_putendl(""SH_NAME": fg: current: no such job");
	ret = EXIT_FAILURE;
	return (ret);
}

int			sh_fg(t_data *data, int ac, char **av)
{
	t_job			*tmp;
	t_data_jobs		*djobs;
	int				id;
	int				ret;

	(void)data;
	(void)ac;
	ret = EXIT_SUCCESS;
	id = 0;
	djobs = get_data_jobs();
	if (av[1])
	{
		if (av[1][0] == '%')
			id = parse_job_id_arg(av[1], &djobs->jobs);
	}
	else
		id = last_id(&djobs->jobs);
	if ((id == 0 && av[1]) || id == -1)
		ret = print_bad_job_in_fg(id, av);
	tmp = get_job_by_id(&djobs->jobs, id);
	if (tmp && tmp->ground == 0)
		print_and_put_fg(tmp);
	else if (!av[1])
		ret = print_no_job();
	return (ret);
}
