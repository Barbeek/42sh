/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolff <hwolff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 19:02:53 by hwolff            #+#    #+#             */
/*   Updated: 2019/03/11 19:02:55 by hwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		rest_of_operands(char op, char *perm)
{
	if (op == 'p' && perm[0] == 'p')
		return (0);
	if (op == 'r' && perm[1] == 'r')
		return (0);
	if (op == 'S' && perm[0] == 's')
		return (0);
	if (op == 'u' && (perm[3] == 's' || perm[3] == 'S'))
		return (0);
	if (op == 'w' && perm[2] == 'w')
		return (0);
	if (op == 'x' && (perm[3] == 'x' || perm[3] == 's'))
		return (0);
	return (1);
}

int		operands_b_to_l(char op, char *perm)
{
	if (op == 'b' && perm[0] == 'b')
		return (0);
	if (op == 'c' && perm[0] == 'c')
		return (0);
	if (op == 'd' && perm[0] == 'd')
		return (0);
	if (op == 'e' && perm[0] != 0)
		return (0);
	if (op == 'f' && perm[0] == '-')
		return (0);
	if (op == 'g' && (perm[6] == 's' || perm[6] == 'S'))
		return (0);
	if ((op == 'h' || op == 'L') && perm[0] == 'l')
		return (0);
	return (1);
}
