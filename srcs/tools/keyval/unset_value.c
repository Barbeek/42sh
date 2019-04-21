/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_value.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 11:20:43 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/29 13:27:16 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		unset_val(char ***vars, char *key)
{
	int		keylen;
	int		i;

	if (!vars || !*vars || !key || !*key)
		return (0);
	keylen = ft_strlen(key);
	i = 0;
	while ((*vars)[i]
		&& (!ft_strnequ((*vars)[i], key, keylen)
			|| (*vars)[i][keylen] != '='))
		++i;
	if ((*vars)[i])
	{
		ft_strdel(&(*vars)[i]);
		ft_strtabcpy((*vars + i), (*vars + i + 1));
	}
	return (1);
}
