/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_walker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 14:24:49 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/19 19:48:49 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char	*walkdoublequote(char *s)
{
	char *c;

	while (*s)
	{
		if (*s == '\\')
			++s;
		else if (*s == '"')
			break ;
		else if (*s == '`')
		{
			if (!*(c = walkbacktick(s + 1)))
				return (s);
			else
				s = c;
		}
		*s && ++s;
	}
	return (s);
}

char	*walksimplequote(char *s)
{
	while (*s)
	{
		if (*s == '\'')
			break ;
		++s;
	}
	return (s);
}

char	*walkbacktick(char *s)
{
	while (*s)
	{
		if (*s == '\\')
			++s;
		else if (*s == '\'')
			s = walksimplequote(s + 1);
		else if (*s == '`')
			break ;
		*s && ++s;
	}
	return (s);
}

int		has_quotes_or_backslash(char *s)
{
	while (*s)
	{
		if (*s == '\'' || *s == '"' || *s == '\\')
			return (1);
		s++;
	}
	return (0);
}
