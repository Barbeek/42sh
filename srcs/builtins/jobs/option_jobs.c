/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_jobs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroblin <aroblin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 14:42:05 by aroblin           #+#    #+#             */
/*   Updated: 2019/03/08 16:25:42 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int					is_l_opt(char *opt)
{
	if (!opt)
		return (0);
	if (opt[ft_strlen(opt) - 1] == 'l')
		return (1);
	else
		return (0);
}

int					is_p_opt(char *opt)
{
	if (!opt)
		return (0);
	if (opt[ft_strlen(opt) - 1] == 'p')
		return (1);
	else
		return (0);
}

int					check_opt(char *opt)
{
	int		i;

	i = 0;
	while (opt[i])
	{
		if (opt[i] != 'l' && opt[i] != 'p')
			return (0);
		i++;
	}
	return (1);
}

void				build_opt(char **arg, char **opt, int *i)
{
	char	*tmp;

	tmp = NULL;
	while (arg[*i])
	{
		if (arg[*i][0] == '-')
		{
			if (*opt == NULL)
				*opt = ft_strdup(arg[*i] + 1);
			else
			{
				tmp = *opt;
				*opt = ft_strjoin(*opt, arg[*i] + 1);
				ft_strdel(&tmp);
			}
		}
		else
			break ;
		*i = *i + 1;
	}
}
