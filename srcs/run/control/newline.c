/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newline.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 15:25:09 by hwolff            #+#    #+#             */
/*   Updated: 2019/03/20 10:50:36 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		exec_newline(t_data *data, t_ast *ast)
{
	int ret;

	ret = ERROR;
	if (ast->left)
		ret = exec_cmd_line(data, ast->left);
	if (ast->right)
		ret = exec_cmd_line(data, ast->right);
	return (ret);
}
