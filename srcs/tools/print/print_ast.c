/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 14:38:09 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/19 15:36:19 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void
	print_name(char *name, int depth)
{
	ft_putstr_fd(".. ", FD_ERR);
	ft_putstrlpad_fd(name, ' ', 5, FD_ERR);
	ft_putchar_fd(' ', FD_ERR);
	ft_putnbr_fd(depth, FD_ERR);
	ft_putstr_fd(" ..\n", FD_ERR);
}

static int
	print_node(t_ast *ast, char *name, int depth)
{
	int		ret;
	t_token	*tok;

	if ((ret = 0) || !ast || !name)
		return (0);
	if (ast->right)
		ret += print_node(ast->right, "right", depth + 1);
	ft_putstrlpad_fd("", ' ', depth * 14, FD_ERR);
	print_name(name, depth);
	ft_putstrlpad_fd("", ' ', (depth * 14) + 1, FD_ERR);
	if (ast->left_arg)
		ft_putstr2_fd(ast->left_arg->val, " ", FD_ERR);
	if (ast->token && (tok = ast->token))
		ft_putstr2_fd(tok->val, " ", FD_ERR);
	if (ast->right_arg)
		ft_putstr2_fd(" ", ast->right_arg->val, FD_ERR);
	if (ast->token)
		while (tok->next && (tok = tok->next))
			ft_putstr2_fd(" ", tok->val, FD_ERR);
	ft_putchar_fd('\n', FD_ERR);
	ft_putstrlpad_fd("", ' ', depth * 14, FD_ERR);
	ft_putstr_fd(".............\n", FD_ERR);
	if (ast->left)
		ret += print_node(ast->left, "left", depth + 1);
	return (ret);
}

int
	print_ast(t_ast *ast)
{
	int ret;

	ret = 0;
	if (ast)
	{
		ft_putstr_fd("\n--- AST ---\n\n", FD_ERR);
		ret = print_node(ast, "begin", 0);
		ft_putstr_fd("\n-----------\n", FD_ERR);
	}
	return (ret);
}
