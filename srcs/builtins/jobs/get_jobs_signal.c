/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_jobs_signal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroblin <aroblin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 19:27:26 by aroblin           #+#    #+#             */
/*   Updated: 2019/03/08 16:19:34 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char			*get_classic_sig(int sig)
{
	if (sig == 18)
		return ("Stopped(SIGTSTP)");
	else if (sig == 21)
		return ("Stopped(SIGTTIN)");
	else if (sig == 22)
		return ("Stopped(SIGTTOU)");
	else if (sig == 17 || sig == 19 || sig == 23)
		return ("Stopped (SIGSTOP)");
	return (NULL);
}

char			*get_detail_sig(int sig)
{
	char	*str;
	char	*tmp;

	str = NULL;
	tmp = ft_itoa(sig);
	if (sig == 18 || sig == 17 || sig == 19 || sig == 23)
		str = ft_strjoin("Suspended:            ", tmp);
	else if (sig == 21)
		str = ft_strjoin("Stopped (tty input):  ", tmp);
	else if (sig == 22)
		str = ft_strjoin("Stopped (tty output): ", tmp);
	ft_strdel(&tmp);
	return (str);
}
