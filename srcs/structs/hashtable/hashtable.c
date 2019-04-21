/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 14:40:03 by pespalie          #+#    #+#             */
/*   Updated: 2019/03/27 00:49:30 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/*
** Crée un tableau de hash.
*/

t_h_table		*ht_create(unsigned int size)
{
	t_h_table		*ht;

	if (size < 1)
		return (NULL);
	try_m(ht = malloc(sizeof(t_h_table)));
	if (ht == NULL)
		return (NULL);
	try_m(ht->array = (t_h_item **)malloc(size * sizeof(t_h_item)));
	if (ht->array == NULL)
		return (NULL);
	ft_memset(ht->array, 0, size * sizeof(t_h_item));
	ht->size = size;
	ht->reset = 0;
	return (ht);
}

/*
** Trouve l'index de la clé passée en argument si elle existe.
*/

unsigned int	hash(char *key, unsigned int size)
{
	unsigned int	hash;
	unsigned int	i;

	hash = 0;
	i = 0;
	while (key && key[i])
	{
		hash = (hash + key[i]) % size;
		++i;
	}
	return (hash);
}

int				ht_put(t_h_table *hashtable, char *key, char *value)
{
	t_h_item	*node;

	if (hashtable == NULL)
		return (1);
	if (!(try_m(node = (t_h_item*)ft_memalloc(sizeof(t_h_item)))))
		return (1);
	try_m(node->key = ft_strdup(key));
	try_m(node->command = ft_strdup(value));
	node_handler(hashtable, node);
	hashtable->reset = 0;
	return (0);
}

char			*ht_get(t_h_table *hashtable, char *key)
{
	char			*key_cp;
	unsigned int	i;
	t_h_item		*tmp;

	if (hashtable == NULL)
		return (NULL);
	try_m(key_cp = ft_strdup(key));
	i = hash(key, hashtable->size);
	tmp = hashtable->array[i];
	while (tmp != NULL)
	{
		if (ft_strcmp(tmp->key, key_cp) == 0)
			break ;
		tmp = tmp->next;
	}
	free(key_cp);
	if (tmp == NULL)
		return (NULL);
	return (tmp->command);
}
