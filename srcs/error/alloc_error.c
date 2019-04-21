/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 14:27:05 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/04 19:20:18 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	*try_m(void *ptr)
{
	if (!ptr)
		shell_exit(put_error(MAJOR_ERROR, "memory allocation error"));
	return (ptr);
}
