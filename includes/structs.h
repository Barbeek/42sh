/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 16:58:11 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/30 01:52:53 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

/*
** Signal handler typedef
*/

typedef void				(*t_sighandler)(int);

/*
** ---------------------------
** TOKEN STRUCT (LINKED LIST)
** ---------------------------
** structure for lexical analysis
*/

typedef struct				s_token
{
	char					*val;
	size_t					length;
	int						type;
	int						valid;
	struct s_token			*next;
}							t_token;

/*
** -------------------------
** AST STRUCT (BINARY TREE)
** -------------------------
** structure for Abstract Syntax Tree
*/

typedef struct				s_ast
{
	t_token					*token;
	t_token					*left_arg;
	t_token					*right_arg;
	struct s_ast			*left;
	struct s_ast			*right;
}							t_ast;

/*
** ---------------------------
** VARIABLE STRUCT (not used)
** ---------------------------
** structure for key/val
*/

typedef struct				s_var
{
	char					*key;
	char					*val;
}							t_var;

/*
** ------------------
** HASH BUILTIN STRUCT
** ------------------
*/

typedef struct				s_h_item
{
	char					*key;
	int						hits;
	char					*command;
	struct s_h_item			*next;
}							t_h_item;

typedef struct				s_h_table
{
	unsigned int			size;
	t_h_item				**array;
	int						reset;
}							t_h_table;

/*
** ------------------
** CD BUILTIN STRUCT
** ------------------
** structure for Line Edition
*/

typedef struct				s_cdenv
{
	char					*old;
	char					*pwd;
	char					*home;
}							t_cdenv;

/*
** --------------------------------
** CHARACTERS STRUCT (LINKED LIST)
** --------------------------------
** structure for Line Edition
** --------------------
** LINE EDITION STRUCT
** --------------------
*/

typedef	struct				s_car
{
	char					val;
	char					selected;
	int						v;
	int						h;
	struct s_car			*prev;
	struct s_car			*next;
	struct s_car			*wide;
}							t_car;

/*
** --------------------
** LINE EDITION STRUCT
** --------------------
** Chained list of edition line cars
** last : last char of the list
** bef  : char from where to update the display
** cur  : current char
** select_ori : cur char when alt (select mode) is pressed
** buff  : (later : to get what is read before prompt is displayed)
*/

struct						s_hist
{
	char					**list;
	int						count;
	int						cur;
	char					*tmpline;
};

struct						s_prompt
{
	char					*val;
	int						h;
	int						v;
	int						len;
};

struct						s_sugg
{
	char					**list;
	int						ncol;
	int						nrow;
	int						len;
	int						max;
};

typedef struct				s_edl
{
	char					*line;
	struct s_hist			hist;
	struct s_prompt			prompt;
	t_car					*last;
	t_car					*bef;
	t_car					*cur;
	t_car					*select_ori;
	size_t					len;

	t_car					*clip;

	char					select_mode;
	char					tabul;
	char					key_mode;

	char					enter;
	char					eof;
	int						incomp_type;

	int						ncol;
	int						nrow;
	struct s_sugg			sugg;

}							t_edl;

/*
** -----------------------
** SHELL MAIN DATA STRUCT
** -----------------------
*/

struct						s_param
{
	char					*term_name;
	char					run;
	char					cancel;
	char					interactive;
	char					subcmd;
	char					**av;
	int						ac;
	int						status;
	int						options;
	pid_t					pid;
	pid_t					last_bg_pid;
};

typedef struct				s_data
{
	char					**env;
	char					**loc;
	char					**spe;
	char					**alias;
	char					**tmpenv;
	char					*arguments;
	struct s_param			param;
	char					*command;
	t_token					*token;
	t_ast					*ast;

	t_edl					edl;
	t_h_table				*hashtable;

	struct termios			term_dft_config;
}							t_data;

/*
**  --------------------------
**  VARIABLE EXPANSION STRUCT
**  --------------------------
**
**	Structure utile uniquement dans l'objet d'expansion
**		=> Contient l'ensemble des regles d'expansion
**		=> Un lien vers l'env
*/

/*
** Definition du type representant une regles d'expansion pour les variables
*/
typedef struct s_varsexp	t_varsexp;

typedef struct				s_varsexp_rules
{
	char					*op;
	char					*(*set)(t_varsexp *exp, char *key, char *val,
								char *word);
	char					*(*null)(t_varsexp *exp, char *key, char *val,
								char *word);
	char					*(*unset)(t_varsexp *exp, char *key, char *val,
								char *word);
}							t_varsexp_rules;

struct						s_varsexp
{
	t_data					*data;
	char					*str;
	char					*res;
	t_varsexp_rules			*rule;
	char					format;
};

/*
** Structs arithmetics
*/

typedef struct				s_aritoken
{
	char					*data;
	int						type;
	size_t					len;
	struct s_aritoken		*next;
}							t_aritoken;

typedef struct				s_tree_expr
{
	t_aritoken				*token;
	t_aritoken				*right;
	t_aritoken				*left;
	struct s_tree_expr		*son_left;
	struct s_tree_expr		*son_right;
}							t_tree_expr;

typedef struct				s_aridata
{
	char					*value;
	t_aritoken				*token;
	t_tree_expr				*ast;
}							t_aridata;

/*
** Job control
*/

typedef struct				s_pipeline
{
	t_list					*pipeline;
	int						prev_operator;
	int						last_pid;
}							t_pipeline;

typedef struct				s_process
{
	pid_t					pid;
	int						completed;
	int						stopped;
	int						status;
	struct s_process		*next;
	struct s_process		*prev;
}							t_process;

typedef struct				s_job
{
	int						id;
	struct s_job			*next;
	char					*command;
	t_ast					*ast;
	t_process				*first_process;
	pid_t					pgid;
	struct termios			tmodes;
	int						ground;
	int						stopped;
	pid_t					last_pid;
}							t_job;

typedef struct				s_data_jobs
{
	pid_t					shell_pgid;
	t_job					*jobs;
	t_token					*token_list;
	t_token					*current_token;
	int						current_id;
	int						old_current_id;
	int						last_status;
	int						shell_terminal;
}							t_data_jobs;

#endif
