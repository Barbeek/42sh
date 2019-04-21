/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pespalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 14:46:23 by pespalie          #+#    #+#             */
/*   Updated: 2019/03/18 14:46:25 by pespalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	fill_array(t_h_table *hashtable, t_h_item *tmp, t_h_item *node, int i)
{
	if (tmp == NULL)
	{
		node->next = hashtable->array[i];
		hashtable->array[i] = node;
		hashtable->array[i]->hits = hashtable->reset == 0 ? 1 : 0;
	}
	else
	{
		free(tmp->command);
		if (hashtable->reset == 0)
			tmp->hits += 1;
		else
			tmp->hits = 0;
		tmp->command = ft_strdup(node->command);
		free(node->command);
		free(node->key);
		free(node);
	}
}

void	node_handler(t_h_table *hashtable, t_h_item *node)
{
	unsigned int	i;
	t_h_item		*tmp;

	i = hash(node->key, hashtable->size);
	tmp = hashtable->array[i];
	if (hashtable->array[i] != NULL)
	{
		tmp = hashtable->array[i];
		while (tmp != NULL)
		{
			if (ft_strcmp(tmp->command, node->command) == 0)
				break ;
			tmp = tmp->next;
		}
		if (ft_strcmp(node->key, node->command) != 0)
			fill_array(hashtable, tmp, node, i);
	}
	else
	{
		node->next = NULL;
		hashtable->array[i] = node;
		hashtable->array[i]->hits = hashtable->reset == 0 ? 1 : 0;
	}
}
