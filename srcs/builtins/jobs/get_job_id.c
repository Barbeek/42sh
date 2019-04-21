/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_job_id.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroblin <aroblin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 07:03:16 by aroblin           #+#    #+#             */
/*   Updated: 2019/03/08 16:01:07 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int			get_begin_str_id(t_job *tmp, int *equ, char *str, int *let)
{
	char	*buf;
	int		id;

	id = 0;
	buf = NULL;
	if (same_letter(tmp->command, str) != 0
		&& *(let) <= same_letter(tmp->command, str))
	{
		if (*let == same_letter(tmp->command, str))
			*equ = *equ + 1;
		else
			*equ = 1;
		*let = same_letter(tmp->command, str);
		id = tmp->id;
	}
	return (id);
}

static int			chr_begin_str_cmd(t_job **jobs, char *str)
{
	int		id;
	t_job	*tmp;
	int		equi;
	int		letter;

	letter = 0;
	equi = 0;
	id = 0;
	if (!jobs)
		return (0);
	tmp = *jobs;
	while (tmp)
	{
		if (id < get_begin_str_id(tmp, &equi, str, &letter))
			id = tmp->id;
		tmp = tmp->next;
	}
	if (equi == 1)
		return (id);
	else if (equi == 0)
		return (0);
	return (-1);
}

static int			get_str_id(t_job *tmp, int *equiv, char *str)
{
	char	*buf;
	int		id;

	buf = NULL;
	id = 0;
	if (ft_strstr(tmp->command, str))
	{
		*equiv = *equiv + 1;
		id = tmp->id;
	}
	return (id);
}

static int			chr_str_in_cmd(t_job **jobs, char *str)
{
	int		id;
	t_job	*tmp;
	int		equiv;

	equiv = 0;
	id = 0;
	if (!jobs)
		return (0);
	tmp = *jobs;
	while (tmp)
	{
		if (id < get_str_id(tmp, &equiv, str))
			id = tmp->id;
		tmp = tmp->next;
	}
	if (equiv == 1)
		return (id);
	else if (equiv == 0)
		return (0);
	return (-1);
}

int					parse_job_id_arg(char *str, t_job **jobs)
{
	int		id;

	id = 0;
	if (check_str_digit(str + 1))
	{
		id = ft_atoi(str + 1);
		if (id > last_id(jobs) || id < min_id(jobs))
			id = 0;
	}
	else if (str[1] == '%' || str[1] == '+')
		id = last_id(jobs);
	else if (str[1] == '-')
		id = last_id(jobs) - 1;
	else if (str[1] == '?')
		id = chr_str_in_cmd(jobs, str + 2);
	else
		id = chr_begin_str_cmd(jobs, str + 1);
	return (id);
}
