/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_job_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 16:58:14 by ndubouil          #+#    #+#             */
/*   Updated: 2019/03/27 19:40:31 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void	add_create_new_job(t_job **job, t_ast *ast, int ground)
{
	t_job		*new;
	t_data_jobs	*djobs;

	djobs = get_data_jobs();
	try_m(new = ft_memalloc(sizeof(t_job)));
	new->id = max_id(&djobs->jobs) + 1;
	new->ast = ast;
	get_job_name(&new->command);
	new->ground = ground;
	new->first_process = NULL;
	new->next = NULL;
	if (!(*job))
		*job = new;
	else
		job_addend(job, new);
}

static void	if_remove_ast(t_ast **ast, int flag)
{
	if (flag)
	{
		(*ast)->left = NULL;
		(*ast)->right = NULL;
		astlist_del(ast);
	}
}

void		create_job_struct(t_job **job, t_ast **ast, int ground, int flag)
{
	if (!ast || !(*ast))
		return ;
	if ((*ast)->token->type == SEMICOLON)
	{
		if ((*ast)->left)
			create_job_struct(job, &(*ast)->left, 1, flag);
		if ((*ast)->right)
			create_job_struct(job, &(*ast)->right, 1, flag);
		if_remove_ast(ast, flag);
	}
	else if ((*ast)->token->type == AND)
	{
		if ((*ast)->left)
			create_job_struct(job, &(*ast)->left, 0, flag);
		if ((*ast)->right)
			create_job_struct(job, &(*ast)->right, 1, flag);
		if_remove_ast(ast, flag);
	}
	else
		add_create_new_job(job, (*ast), ground);
}
