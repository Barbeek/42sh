/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   removing_job.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroblin <aroblin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 07:17:53 by aroblin           #+#    #+#             */
/*   Updated: 2019/03/08 16:25:42 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void			ft_jobdelone(t_job **jlst)
{
	t_process	*next;

	if ((*jlst)->first_process)
	{
		while ((*jlst)->first_process)
		{
			next = (*jlst)->first_process->next;
			ft_memdel((void **)&(*jlst)->first_process);
			(*jlst)->first_process = NULL;
			(*jlst)->first_process = next;
		}
	}
	ft_strdel(&(*jlst)->command);
	ft_memdel((void **)jlst);
	*jlst = NULL;
	jlst = NULL;
}

static int		routine_del(t_job *tmp, t_job *prev, int iffreeast, int id)
{
	while (tmp)
	{
		if (tmp->next && tmp->next->id == id)
		{
			prev = tmp->next;
			tmp->next = tmp->next->next;
			if (iffreeast)
			{
				if (prev->ast)
				{
					astlist_del(&prev->ast);
					prev->ast = NULL;
				}
			}
			ft_jobdelone(&prev);
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

int				remove_one_job_by_id(t_job **jobs_lst, int id, int iffreeast)
{
	t_job	*prev;
	t_job	*tmp;

	prev = NULL;
	tmp = *jobs_lst;
	if (tmp && tmp->id == id)
	{
		prev = tmp;
		*jobs_lst = tmp->next;
		if (iffreeast)
		{
			if (prev->ast)
			{
				astlist_del(&prev->ast);
				prev->ast = NULL;
			}
		}
		ft_jobdelone(&prev);
		return (1);
	}
	return (routine_del(tmp, prev, iffreeast, id));
}
