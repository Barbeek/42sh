/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 20:57:53 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/23 16:40:46 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static const char *g_tokensstr[] = {
	"WORD", "ASSIGNEMENT", "IO_NUMBER",
	"TRIPLELESS", "TRIPLEGREAT", "DOUBLELESSDASH", "DOUBLELESSAND",
	"DOUBLEGREATAND", "ANDDOUBLEGREAT", "ANDDOUBLELESS", "DOUBLESEMICOLONAND",
	"DOUBLEAND", "DOUBLEPIPE", "DOUBLESEMICOLON", "DOUBLELESS", "DOUBLEGREAT",
	"LESSGREAT", "LESSAND", "GREATAND", "ANDGREAT", "ANDLESS", "GREATPIPE",
	"PIPEAND", "SEMICOLONAND", "PIPE", "AND", "SEMICOLON", "LESS", "GREAT",
	"OP_PAR", "CL_PAR", "OP_BRA", "CL_BRA", "NEWLINE", "BANG", "DOUBLEEQUAL",
	"BANGEQUAL", "LESSEQUAL", "GREATEQUAL", "DOUBLEPLUS", "DOUBLEMINUS",
	"PLUS", "MINUS", "STAR", "PERCENT", "SLASH", "NUMBER", "VARIABLE",
	"INVALID", 0};

static const int	g_delim[] = {
	WORD, ASSIGNEMENT, IO_NUMBER,
	TRIPLELESS, TRIPLEGREAT, DOUBLELESSDASH, DOUBLELESSAND, DOUBLEGREATAND,
	ANDDOUBLEGREAT, ANDDOUBLELESS, DOUBLESEMICOLONAND, DOUBLEAND, DOUBLEPIPE,
	DOUBLESEMICOLON, DOUBLELESS, DOUBLEGREAT, LESSGREAT, LESSAND, GREATAND,
	ANDGREAT, ANDLESS, GREATPIPE, PIPEAND, SEMICOLONAND, PIPE, AND, SEMICOLON,
	LESS, GREAT, OP_PAR, CL_PAR, OP_BRA, CL_BRA, NEWLINE, BANG, DOUBLEEQUAL,
	BANGEQUAL, LESSEQUAL, GREATEQUAL, DOUBLEPLUS, DOUBLEMINUS, PLUS, MINUS,
	STAR, PERCENT, SLASH, NUMBER, VARIABLE, INVALID, 0};

int		print_lex(t_token *token, char *name)
{
	int i;

	ft_putstr3_fd("\n--- ", name, " ---\n", FD_ERR);
	while (token)
	{
		write(FD_ERR, token->val, token->length);
		ft_putstrnbr_fd(" (", token->length, ") => ", FD_ERR);
		i = 0;
		while (g_delim[i])
		{
			if (g_delim[i] == token->type)
			{
				ft_putstr_fd(g_tokensstr[i], FD_ERR);
				ft_putstrnbr_fd(" (", token->type, ")", FD_ERR);
			}
			++i;
		}
		ft_putchar_fd('\n', FD_ERR);
		token = token->next;
	}
	ft_putstr_fd("--------------\n\n", FD_ERR);
	return (1);
}
