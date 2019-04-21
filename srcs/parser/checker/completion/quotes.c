/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 20:25:46 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/19 17:41:34 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static char
	check_str_quote(char **s)
{
	if (**s == '\'')
	{
		if (!*(*s = walksimplequote(*s + 1)))
			return ('\'');
	}
	else if (**s == '"')
	{
		if (!*(*s = walkdoublequote(*s + 1)))
			return ('"');
		else if (**s == '`')
			return ('`');
	}
	else if (**s == '`')
	{
		if (!*(*s = walkbacktick(*s + 1)))
			return ('`');
	}
	return (0);
}

static char
	check_str_bracket(char **s)
{
	if (**s == '$' && *(*s + 1) == '(')
	{
		if (!*(*s = walkparenthese(*s + 2)))
			return ('(');
	}
	else if (**s == '$' && *(*s + 1) == '{')
	{
		if (!*(*s = walkbracket(*s + 2)))
			return ('{');
	}
	return (0);
}

static char
	check_str(char *s)
{
	char c;

	while (*s)
	{
		if (*s == '\\')
			++s;
		else if ((c = check_str_quote(&s))
			|| (c = check_str_bracket(&s)))
			return (c);
		*s && ++s;
	}
	return (0);
}

char
	check_quote(t_token *token)
{
	while (token->next && token->next->type != NEWLINE)
		token = token->next;
	return (check_str(token->val));
}
