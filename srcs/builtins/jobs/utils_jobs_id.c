/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_jobs_id.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroblin <aroblin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 07:11:02 by aroblin           #+#    #+#             */
/*   Updated: 2019/03/26 21:21:14 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int			max_id(t_job **jobs)
{
	int		id;
	t_job	*tmp;

	if (!jobs || !(*jobs))
		return (0);
	tmp = *jobs;
	id = tmp->id;
	while (tmp)
	{
		if (tmp->id > id)
			id = tmp->id;
		tmp = tmp->next;
	}
	return (id);
}

int			min_id(t_job **jobs)
{
	int		id;
	t_job	*tmp;

	id = 1;
	if (!jobs || !(*jobs))
		return (0);
	tmp = *jobs;
	id = tmp->id;
	while (tmp)
	{
		if (tmp->id < id)
			id = tmp->id;
		tmp = tmp->next;
	}
	return (id);
}

int			last_id(t_job **jobs)
{
	int		id;
	t_job	*tmp;

	id = 0;
	if (!jobs || !(*jobs))
		return (0);
	tmp = *jobs;
	while (tmp)
	{
		if (tmp->ground == 0)
			id = tmp->id;
		tmp = tmp->next;
	}
	return (id);
}

int			check_str_digit(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int			same_letter(char *str, char *str2)
{
	int		i;

	i = 0;
	if (ft_strlen(str) < ft_strlen(str2))
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] != str2[i])
			return (i);
		i++;
	}
	return (i);
}
