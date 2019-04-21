/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pespalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 14:34:34 by pespalie          #+#    #+#             */
/*   Updated: 2019/03/18 14:46:46 by pespalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		h_item_free(t_h_table *hashtable)
{
	t_h_item		*tmp;
	unsigned int	i;

	i = 0;
	while (i < hashtable->size)
	{
		if (hashtable->array[i] != NULL)
		{
			while (hashtable->array[i] != NULL)
			{
				tmp = hashtable->array[i]->next;
				free(hashtable->array[i]->key);
				free(hashtable->array[i]->command);
				free(hashtable->array[i]);
				hashtable->array[i] = tmp;
			}
		}
		i++;
	}
	return (0);
}

void	h_table_free(t_h_table *hashtable)
{
	t_h_item		*tmp;
	unsigned int	i;

	if (hashtable == NULL)
		return ;
	i = 0;
	while (i < hashtable->size)
	{
		if (hashtable->array[i] != NULL)
		{
			while (hashtable->array[i] != NULL)
			{
				tmp = hashtable->array[i]->next;
				free(hashtable->array[i]->key);
				free(hashtable->array[i]->command);
				free(hashtable->array[i]);
				hashtable->array[i] = tmp;
			}
		}
		i++;
	}
	free(hashtable->array);
	free(hashtable);
}
