/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pespalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 14:33:02 by pespalie          #+#    #+#             */
/*   Updated: 2019/03/18 14:33:06 by pespalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int			test_parse(char **str, int i)
{
	if (i == 1)
		return (one_arg(str));
	if (i == 2)
		return (two_args(str));
	if (i == 3)
		return (three_args(str));
	return (1);
}
