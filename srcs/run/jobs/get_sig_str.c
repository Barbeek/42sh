/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sig_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroblin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 18:32:09 by aroblin           #+#    #+#             */
/*   Updated: 2019/03/22 18:32:40 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char		*get_sig_str(int sig)
{
	static char *mes[32] = {NULL, "hangup", NULL, NULL,
		"illegal hardware instruction", "trace trap", "abort",
		"EMT instruction", "floating point exception", "killed", "bus error",
		"segmentation fault", "invalid system call", NULL, "alarm", NULL, NULL,
		"suspended", NULL, "continued", NULL, NULL, NULL, NULL,
		"cpu limit exceeded", "file size limit exceeded", "virtual time alarm",
		"profile signal", NULL, NULL, "user-defined signal 1",
		"user-defined signal 2"};

	return (mes[sig]);
}
