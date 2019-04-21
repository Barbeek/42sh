/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 11:20:42 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/23 11:53:52 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char	*get_val(char **vars, char *key)
{
	char	**v;

	if (!key || !*key
		|| !(v = get_keyval(vars, key)))
		return (NULL);
	return (ft_strchr(*v, '=') + 1);
}

char	**get_keyval(char **vars, char *key)
{
	int		keylen;
	int		i;

	if (!vars || !key || !*key)
		return (NULL);
	keylen = ft_strlen(key);
	i = 0;
	while (vars[i])
	{
		if (ft_strnequ(vars[i], key, keylen) && vars[i][keylen] == '=')
			return (&vars[i]);
		++i;
	}
	return (NULL);
}
