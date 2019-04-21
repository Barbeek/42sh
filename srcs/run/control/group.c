/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   group.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 10:48:44 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/20 16:17:32 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		exec_command_group(t_data *data, t_ast *ast)
{
	int ret;

	ret = OK;
	if (ast->left)
		ret = exec_cmd_line(data, ast->left);
	if (ast->right)
		ret = exec_cmd_line(data, ast->right);
	return (ret);
}
