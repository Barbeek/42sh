/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_addend.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroblin <aroblin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 22:14:17 by aroblin           #+#    #+#             */
/*   Updated: 2019/03/12 16:29:24 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void			process_addend(t_process **process, t_process *new)
{
	t_process	*tmp;
	t_process	*first;

	tmp = *process;
	first = *process;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	new->prev = tmp;
	*process = first;
}
