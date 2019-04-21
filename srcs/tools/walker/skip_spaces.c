/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_spaces.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 12:00:24 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/23 12:00:53 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	arith_skip_spaces(char **line)
{
	while (arith_isspace(**line))
		++(*line);
}

void	skip_spaces(char **line)
{
	while (sh_isspace(**line))
		++(*line);
}
