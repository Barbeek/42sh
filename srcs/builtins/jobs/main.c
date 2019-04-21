/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 14:09:13 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/29 14:40:44 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/*
**   http://pubs.opengroup.org/onlinepubs/9699919799/utilities/jobs.html
*/

static int			get_job(char *str, t_job *tmp, char *opt)
{
	int				id;
	int				ret;
	t_data_jobs		*djobs;

	djobs = get_data_jobs();
	ret = EXIT_SUCCESS;
	id = 0;
	ret = 0;
	if (str[0] == '%')
		id = parse_job_id_arg(str, &djobs->jobs);
	else
		id = last_id(&djobs->jobs);
	if ((id == 0 && str) || id == -1)
		ret = print_bad_job(id, str);
	tmp = get_job_by_id(&djobs->jobs, id);
	if (tmp)
	{
		if (is_l_opt(opt))
			print_detail_jobs(tmp, djobs);
		else if (is_p_opt(opt))
			print_process_group(tmp);
		else
			print_classic_jobs(tmp, djobs);
	}
	return (ret);
}

static void			print_all_jobs(t_job *tmp, char *opt)
{
	t_data_jobs		*djobs;

	djobs = get_data_jobs();
	tmp = djobs->jobs;
	print_job_list(tmp, djobs, opt);
}

static void			del_and_usage(char *opt)
{
	ft_putstr3(""SH_NAME": jobs: ", opt, ": invalid option\n");
	ft_strdel(&opt);
	ft_putendl("jobs: usage: jobs [-lp] [job_id...]");
}

static int			bad_option(char *opt)
{
	if (check_opt(opt) != 1)
	{
		del_and_usage(opt);
		return (0);
	}
	return (1);
}

int					sh_jobs(t_data *data, int ac, char **av)
{
	t_job			*tmp;
	int				i;
	char			*opt;
	int				ret;

	tmp = NULL;
	opt = NULL;
	(void)ac;
	(void)data;
	i = 1;
	ret = 0;
	build_opt(av, &opt, &i);
	if (opt)
		if (!bad_option(opt))
			return (EXIT_FAILURE);
	if (!av[i])
		print_all_jobs(tmp, opt);
	while (av[i])
	{
		ret = get_job(av[i], tmp, opt);
		i++;
	}
	ft_strdel(&opt);
	return (ret);
}
