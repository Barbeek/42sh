/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brackets_walker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 16:39:34 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/09 18:36:35 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char	*walkparenthese(char *s)
{
	while (*s)
	{
		if (*s == '\\')
			++s;
		else if (*s == '(')
			s = walkparenthese(s + 1);
		else if (*s == ')')
			break ;
		*s && ++s;
	}
	return (s);
}

char	*walkbracket(char *s)
{
	while (*s)
	{
		if (*s == '\\')
			++s;
		else if (*s == '}')
			break ;
		*s && ++s;
	}
	return (s);
}

char	*walkdollar(char *s)
{
	if (*s == '(')
		s = walkparenthese(s + 1);
	else if (*s == '{')
		s = walkbracket(s + 1);
	return (s);
}
