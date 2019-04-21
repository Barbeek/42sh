/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 14:11:12 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/27 15:20:41 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		empty_hash(t_h_table *hashtable)
{
	return (h_item_free(hashtable));
}

int		check_each_path(t_data *data, char ***paths)
{
	int res;

	res = OK;
	while (**paths)
	{
		data->hashtable->reset = 1;
		if (find_path(data, **paths))
			res = hash_not_found(**paths);
		++*paths;
	}
	return (res);
}

void	display_spaces(t_h_item *hash)
{
	int		hits;
	int		spaces;

	spaces = 3;
	hits = hash->hits;
	while (hits / 10)
	{
		hits = hits / 10;
		spaces -= 1;
	}
	while (spaces-- > 0)
		ft_putchar(' ');
	return ;
}

void	display_list(t_h_table *ht)
{
	t_h_item	*cur;
	size_t		i;

	i = 0;
	ft_putstr("hits    ");
	ft_putendl("command");
	while (i < ht->size)
	{
		cur = ht->array[i];
		while (cur)
		{
			display_spaces(cur);
			ft_putnbr(cur->hits);
			ft_putstr("    ");
			ft_putendl(cur->command);
			cur = cur->next;
		}
		++i;
	}
}

int		sh_hash(t_data *data, int ac, char **av)
{
	int		options;
	int		res;

	if (!(options = 0) && check_hash_options(&options, ac, &av))
		return (MAJOR_ERROR);
	res = OK;
	if (options & HA_OP_R)
		empty_hash(data->hashtable);
	if (*av)
		res = check_each_path(data, &av);
	else if (!options)
	{
		if (!*data->hashtable->array)
			ft_putendl("hash: hash table empty");
		else
			display_list(data->hashtable);
	}
	return (res);
}
