/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 15:08:32 by hwolff            #+#    #+#             */
/*   Updated: 2019/03/29 17:56:51 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		check_fd(int fd)
{
	int		dfd;

	if ((dfd = dup(fd)) == -1)
		return (0);
	close(dfd);
	return (1);
}

int		check_word(char *s)
{
	int isfd;
	int	closed;

	isfd = 0;
	closed = 0;
	if (*s == '-' && !*(s + 1))
		return (4);
	if (*s && *s >= '0' && *s <= '9')
	{
		isfd = 1;
		while (*s >= '0' && *s <= '9')
			++s;
	}
	while (*s && *(s + 1))
		++s;
	if (*s == '-')
		closed = 1;
	return (closed + 2 * isfd);
}

/*
** > : redirige dans un fichier et l'écrase s'il existe déjà ;
** >> : redirige à la fin d'un fichier et le crée s'il n'existe pas.
** < : envoie le contenu d'un fichier à une commande ;
** << : passe la console en mode saisie au clavier, ligne par ligne (heredoc).
** Toutes ces lignes seront envoyées à la commande lorsque le mot-clé de fin
** aura été écrit.
** 2>> et 2> OK
*/

int		exec_back_redirect(t_data *data, t_ast *ast)
{
	int		ret;
	int		fd_g;
	int		fd_d;
	int		stdin;

	fd_d = open(ast->right_arg->val, O_RDONLY);
	if (fd_d >= 0)
	{
		fd_g = (ast->left_arg ? ft_atoi(ast->left_arg->val) : 0);
		stdin = dup(fd_g);
		dup2(fd_d, fd_g);
		ret = exec_redirect2(data, ast);
		dup2(stdin, fd_g);
		close(fd_d);
		close(stdin);
		return (ret);
	}
	else
		return (put_error2(ERROR, ast->right_arg
				? ast->right_arg->val : NULL, "No such file or directory"));
}

int		exec_redirect2(t_data *data, t_ast *ast)
{
	int ret;

	ret = 0;
	if (ast->right)
		ret = exec_cmd_line(data, ast->right);
	if (ast->left)
		ret = exec_cmd_line(data, ast->left);
	return (ret);
}

int		exec_redirect(t_data *data, t_ast *ast, int rafter)
{
	int		ret;
	int		fd_g;
	int		fd_d;
	int		stdin;

	fd_d = 0;
	if (rafter == GREAT)
		fd_d = open(ast->right_arg->val, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	else if (rafter == DOUBLEGREAT)
		fd_d = open(ast->right_arg->val, O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (fd_d >= 0)
	{
		fd_g = (ast->left_arg ? ft_atoi(ast->left_arg->val) : 1);
		stdin = dup(fd_g);
		dup2(fd_d, fd_g);
		ret = exec_redirect2(data, ast);
		write(fd_g, "\0", 0);
		dup2(stdin, fd_g);
		close(fd_d);
		close(stdin);
		return (ret);
	}
	else
		return (put_error2(ERROR, ast->right_arg
					? ast->right_arg->val : "", "No such file or directory"));
}
