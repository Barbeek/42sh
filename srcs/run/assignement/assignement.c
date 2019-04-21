/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assignement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 16:33:08 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/29 19:20:13 by pespalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int		get_next_type(t_ast *ast)
{
	while (ast)
	{
		if (ast->token->type == ASSIGNEMENT)
			return (ASSIGNEMENT);
		if (ast->token->type == WORD)
			return (WORD);
		ast = ast->right;
	}
	return (0);
}

static void		switch_env(t_data *data)
{
	char **tmp;

	tmp = data->env;
	data->env = data->tmpenv;
	data->tmpenv = tmp;
}

static void		transvase(char ***dst, char ***src)
{
	char	**tmp;

	tmp = *src;
	while (*tmp)
	{
		set_keyval(dst, *tmp);
		++tmp;
	}
	ft_strtabdel(src);
	*src = try_m(ft_strtabnew(0));
}

static int		exec_temp_assignement(t_data *data, t_ast *ast)
{
	int		ret;
	char	**tmp;

	set_keyval(&data->tmpenv, ast->token->val);
	tmp = try_m(ft_strtabdup(data->env));
	transvase(&tmp, &data->tmpenv);
	free(data->tmpenv);
	data->tmpenv = tmp;
	switch_env(data);
	ret = exec_cmd_line(data, ast->right);
	switch_env(data);
	ft_strtabdel(&data->tmpenv);
	data->tmpenv = try_m(ft_strtabnew(0));
	return (ret);
}

int				exec_assignement(t_data *data, t_ast *ast)
{
	int		ret;
	int		nexttype;

	ret = OK;
	nexttype = get_next_type(ast->right);
	if (nexttype == WORD)
		ret = exec_temp_assignement(data, ast);
	else if (nexttype == ASSIGNEMENT)
	{
		set_keyval(&data->tmpenv, ast->token->val);
		ret = exec_cmd_line(data, ast->right);
	}
	else
	{
		transvase(&data->loc, &data->tmpenv);
		set_keyval(&data->loc, ast->token->val);
		if (ast->right)
			ret = exec_cmd_line(data, ast->right);
	}
	return (ret);
}
