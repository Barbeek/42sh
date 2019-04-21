# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/29 21:21:07 by hben-yah          #+#    #+#              #
#    Updated: 2019/03/29 21:21:07 by hben-yah         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	42sh

COMP			=	clang
FLAG			=	-Wall -Wextra -Werror -g3
FLAGDEV         =   -std=c89 -pedantic

# Sources paths
FILES_C			=   \
					builtins/alias/alias_output.c \
					builtins/alias/error.c \
					builtins/alias/main.c \
					builtins/alias/options.c \
					builtins/bg/error.c \
					builtins/bg/main.c \
					builtins/builtins.c \
					builtins/cd/build_pwd_tab.c \
					builtins/cd/flags.c \
					builtins/cd/get_final_path.c \
					builtins/cd/get_pwd_for_cd.c \
					builtins/cd/main.c \
					builtins/cd/utils_cd.c \
					builtins/echo/error.c \
					builtins/echo/main.c \
					builtins/exit/error.c \
					builtins/exit/main.c \
					builtins/export/error.c \
					builtins/export/main.c \
					builtins/fc/error.c \
					builtins/fc/main.c \
					builtins/fg/error.c \
					builtins/fg/main.c \
					builtins/hash/error.c \
					builtins/hash/main.c \
					builtins/hash/options.c \
					builtins/jobs/error.c \
					builtins/jobs/get_job_id.c \
					builtins/jobs/get_jobs_signal.c \
					builtins/jobs/main.c \
					builtins/jobs/option_jobs.c \
					builtins/jobs/print_jobs.c \
					builtins/jobs/utils_jobs_id.c \
					builtins/set/error.c \
					builtins/set/main.c \
					builtins/test/main.c \
					builtins/test/operands.c \
					builtins/test/parse_args.c \
					builtins/test/permissions.c \
					builtins/test/string.c \
					builtins/test/three_args.c \
					builtins/test/two_args.c \
					builtins/type/error.c \
					builtins/type/main.c \
					builtins/unalias/main.c \
					builtins/unset/error.c \
					builtins/unset/main.c \
					core/check_terminal.c \
					core/exit.c \
					core/init.c \
					core/reset.c \
					core/shell.c \
					error/alloc_error.c \
					error/arg_error.c \
					error/general_error.c \
					error/syntax_error.c \
					error/terminal_error.c \
					error/unexpected_eof.c \
					expansion/alias/alias.c \
					expansion/arithmetic/arithmetic.c \
					expansion/arithmetic/computor/calcul.c \
					expansion/arithmetic/computor/compute.c \
					expansion/arithmetic/computor/crementation.c \
					expansion/arithmetic/computor/logical.c \
					expansion/arithmetic/parser/ast/build_ast.c \
					expansion/arithmetic/parser/ast/fill_node.c \
					expansion/arithmetic/parser/ast/precedence.c \
					expansion/arithmetic/parser/ast/tools.c \
					expansion/arithmetic/parser/checker/checker.c \
					expansion/arithmetic/parser/checker/grammar/check_expression.c \
					expansion/arithmetic/parser/checker/grammar/check_number.c \
					expansion/arithmetic/parser/checker/grammar/check_operande.c \
					expansion/arithmetic/parser/checker/grammar/check_operator.c \
					expansion/arithmetic/parser/checker/grammar/check_sub_expression.c \
					expansion/arithmetic/parser/checker/grammar/check_variable.c \
					expansion/arithmetic/parser/lexer/delimitor.c \
					expansion/arithmetic/parser/lexer/lexer.c \
					expansion/command_substitution/command_substitution.c \
					expansion/expansion.c \
					expansion/field_splitting/field_split.c \
					expansion/parameter/goto_next_quote.c \
					expansion/parameter/vars.c \
					expansion/parameter/vars_assign.c \
					expansion/parameter/vars_get.c \
					expansion/parameter/vars_substitute.c \
					expansion/quote/quotes.c \
					expansion/tilde/tilde.c \
					interaction/autocompletion/alias.c \
					interaction/autocompletion/builtin.c \
					interaction/autocompletion/command.c \
					interaction/autocompletion/completion.c \
					interaction/autocompletion/file.c \
					interaction/autocompletion/parameter.c \
					interaction/autocompletion/print.c \
					interaction/editor/cars_position.c \
					interaction/editor/cursor.c \
					interaction/editor/delete_car.c \
					interaction/editor/editor.c \
					interaction/editor/init.c \
					interaction/editor/insert_car.c \
					interaction/editor/keys/alt_c.c \
					interaction/editor/keys/alt_left.c \
					interaction/editor/keys/alt_right.c \
					interaction/editor/keys/alt_v.c \
					interaction/editor/keys/alt_x.c \
					interaction/editor/keys/arrow_down.c \
					interaction/editor/keys/arrow_left.c \
					interaction/editor/keys/arrow_right.c \
					interaction/editor/keys/arrow_up.c \
					interaction/editor/keys/backspace.c \
					interaction/editor/keys/ctlr_d.c \
					interaction/editor/keys/delete.c \
					interaction/editor/keys/end.c \
					interaction/editor/keys/enter.c \
					interaction/editor/keys/home.c \
					interaction/editor/keys/shift_down.c \
					interaction/editor/keys/shift_left.c \
					interaction/editor/keys/shift_right.c \
					interaction/editor/keys/shift_tab.c \
					interaction/editor/keys/shift_up.c \
					interaction/editor/keys/tabulation.c \
					interaction/editor/line.c \
					interaction/editor/print.c \
					interaction/editor/prompt.c \
					interaction/editor/reset.c \
					interaction/editor/select_mode.c \
					interaction/editor/termcaps/clear_down.c \
					interaction/editor/termcaps/clear_effects.c \
					interaction/editor/termcaps/clear_screen.c \
					interaction/editor/termcaps/clear_to_eol.c \
					interaction/editor/termcaps/cursor_invisible.c \
					interaction/editor/termcaps/cursor_move.c \
					interaction/editor/termcaps/cursor_move_begin.c \
					interaction/editor/termcaps/cursor_move_down.c \
					interaction/editor/termcaps/cursor_move_left.c \
					interaction/editor/termcaps/cursor_move_right.c \
					interaction/editor/termcaps/cursor_move_up.c \
					interaction/editor/termcaps/cursor_newline.c \
					interaction/editor/termcaps/ring_bell.c \
					interaction/editor/termcaps/scroll_down.c \
					interaction/editor/termcaps/scroll_up.c \
					interaction/editor/termcaps/standout_off.c \
					interaction/editor/termcaps/standout_on.c \
					interaction/editor/utils.c \
					options/option_d.c \
					options/options.c \
					parameters/export_var.c \
					parameters/get_param.c \
					parameters/get_var.c \
					parameters/set_special_param.c \
					parameters/set_var.c \
					parameters/unset_var.c \
					parser/ast/build_ast.c \
					parser/ast/fill_node.c \
					parser/ast/precedence.c \
					parser/ast/tools.c \
					parser/checker/checker.c \
					parser/checker/completion/brackets.c \
					parser/checker/completion/completion.c \
					parser/checker/completion/newline.c \
					parser/checker/completion/operators.c \
					parser/checker/completion/quotes.c \
					parser/checker/grammar/check_and_or.c \
					parser/checker/grammar/check_brace_group.c \
					parser/checker/grammar/check_cmd_name.c \
					parser/checker/grammar/check_cmd_prefix.c \
					parser/checker/grammar/check_cmd_suffix.c \
					parser/checker/grammar/check_cmd_word.c \
					parser/checker/grammar/check_command.c \
					parser/checker/grammar/check_complete_command.c \
					parser/checker/grammar/check_complete_commands.c \
					parser/checker/grammar/check_compound_command.c \
					parser/checker/grammar/check_compound_list.c \
					parser/checker/grammar/check_filename.c \
					parser/checker/grammar/check_here_end.c \
					parser/checker/grammar/check_io_file.c \
					parser/checker/grammar/check_io_here.c \
					parser/checker/grammar/check_io_redirect.c \
					parser/checker/grammar/check_linebreak.c \
					parser/checker/grammar/check_list.c \
					parser/checker/grammar/check_newline_list.c \
					parser/checker/grammar/check_pipe_sequence.c \
					parser/checker/grammar/check_pipeline.c \
					parser/checker/grammar/check_program.c \
					parser/checker/grammar/check_redirect_list.c \
					parser/checker/grammar/check_separator.c \
					parser/checker/grammar/check_separator_op.c \
					parser/checker/grammar/check_simple_command.c \
					parser/checker/grammar/check_subshell.c \
					parser/checker/grammar/check_term.c \
					parser/checker/grammar/check_token.c \
					parser/checker/grammar/check_wordlist.c \
					parser/checker/heredoc/heredoc.c \
					parser/lexer/delimitor.c \
					parser/lexer/lexer.c \
					parser/lexer/word.c \
					run/assignement/assignement.c \
					run/control/group.c \
					run/control/logical.c \
					run/control/newline.c \
					run/control/pipes.c \
					run/control/semicolon.c \
					run/exec_cmd_line.c \
					run/exec_cmd_line_tools.c \
					run/execution/executor.c \
					run/execution/subshell.c \
					run/jobs/check_builtins.c \
					run/jobs/control.c \
					run/jobs/create_job_struct.c \
					run/jobs/create_operators_lst.c \
					run/jobs/create_pipeline_lst.c \
					run/jobs/free_jobs.c \
					run/jobs/get_data_jobs.c \
					run/jobs/get_job_by_id.c \
					run/jobs/get_job_name.c \
					run/jobs/get_sig_str.c \
					run/jobs/is_job_ctrl_bt.c \
					run/jobs/job_addend.c \
					run/jobs/job_control.c \
					run/jobs/launch_job.c \
					run/jobs/launch_process.c \
					run/jobs/manag_lst.c \
					run/jobs/manage_job_ground.c \
					run/jobs/monitor_process.c \
					run/jobs/process_addend.c \
					run/jobs/removing_job.c \
					run/jobs/routine_fork.c \
					run/jobs/routine_operators.c \
					run/jobs/routine_pipe.c \
					run/jobs/token_lst_dup_jc.c \
					run/jobs/update_jobs_status.c \
					run/jobs/update_last_status.c \
					run/jobs/upt_pgid_and_process.c \
					run/path/path.c \
					run/redirection/fd_agregator.c \
					run/redirection/heredoc.c \
					run/redirection/redirections.c \
					signals/sigint.c \
					signals/signals.c \
					signals/sigwinch.c \
					structs/ast/ast.c \
					structs/car/car.c \
					structs/car/carlist.c \
					structs/data/data.c \
					structs/hashtable/free.c \
					structs/hashtable/hashtable.c \
					structs/hashtable/node_handler.c \
					structs/token/token.c \
					structs/token/tokenlist.c \
					tools/boolean/assignement.c \
					tools/boolean/spaces.c \
					tools/boolean/token.c \
					tools/boolean/variable.c \
					tools/keyval/get_value.c \
					tools/keyval/set_value.c \
					tools/keyval/unset_value.c \
					tools/print/print_ast.c \
					tools/print/print_lex.c \
					tools/print/sh_putchar.c \
					tools/read/read.c \
					tools/remove/newline.c \
					tools/walker/brackets_walker.c \
					tools/walker/quotes_walker.c \
					tools/walker/skip_spaces.c \
					tools/walker/token_walker.c
FILES_O			=	$(FILES_C:.c=.o)
FILES_H			=	\
					defines.h \
					prototypes.h \
					shell.h \
					structs.h

# Directories
SRCS_SD			= 	\
					builtins \
					builtins/alias \
					builtins/bg \
					builtins/cd \
					builtins/echo \
					builtins/exit \
					builtins/export \
					builtins/fc \
					builtins/fg \
					builtins/hash \
					builtins/jobs \
					builtins/set \
					builtins/test \
					builtins/type \
					builtins/unalias \
					builtins/unset \
					core \
					error \
					expansion \
					expansion/alias \
					expansion/arithmetic \
					expansion/arithmetic/computor \
					expansion/arithmetic/parser \
					expansion/arithmetic/parser/ast \
					expansion/arithmetic/parser/checker \
					expansion/arithmetic/parser/checker/grammar \
					expansion/arithmetic/parser/lexer \
					expansion/command_substitution \
					expansion/field_splitting \
					expansion/parameter \
					expansion/quote \
					expansion/tilde \
					interaction \
					interaction/autocompletion \
					interaction/editor \
					interaction/editor/keys \
					interaction/editor/termcaps \
					options \
					parameters \
					parser \
					parser/ast \
					parser/checker \
					parser/checker/completion \
					parser/checker/grammar \
					parser/checker/heredoc \
					parser/lexer \
					run \
					run/assignement \
					run/control \
					run/execution \
					run/jobs \
					run/path \
					run/redirection \
					signals \
					structs \
					structs/ast \
					structs/car \
					structs/data \
					structs/hashtable \
					structs/token \
					tools \
					tools/boolean \
					tools/keyval \
					tools/print \
					tools/read \
					tools/remove \
					tools/walker
SRCS_D			=	./srcs/
OBJS_D			=   ./objs/
INCL_D 			=	./includes/

# Paths
SRCS			= 	$(addprefix $(SRCS_D), $(FILES_C))
OBJS			=	$(addprefix $(OBJS_D), $(FILES_O))
INCL			=	$(addprefix $(INCL_D), $(FILES_H))

# Libft
LFT_D			=	./libft/
LFT_P			=	$(addprefix $(LFT_D), libft.a)
LFT_I			=	./libft/includes/
LFT_L			=	./libft
LFT_H			=	\
					ft_defines.h \
					ft_prototypes.h \
					ft_structs.h \
					libft.h

# Termcaps

TRMCP_I			=	-ltermcap

# Rules

all				:	$(NAME)

dev				:	debug $(NAME)


$(NAME)			:	$(LFT_P) $(OBJS)
					@echo "\nAssemblage et création de l'exécutable $(NAME)"
					@$(COMP) $(FLAG) $(OBJS) $(LFT_P) $(TRMCP_I) -o $(NAME)
					@echo "Terminé"

$(LFT_P)		:	force
					@echo "Vérification de la librairie Libft"
					@make -C $(LFT_D)

$(OBJS_D)%.o	:	$(SRCS_D)%.c $(addprefix $(LFT_I), $(LFT_H)) $(INCL)
					@echo -e "\033[2K\c"
					@echo "\rCréation de l'objet $@\c"
					@mkdir -p $(addprefix $(OBJS_D), $(SRCS_SD))
					@$(COMP) $(FLAG) -I $(LFT_I) -I $(INCL_D) -o $@ -c $<

clean			:
					@make -C $(LFT_D) clean
					@echo "Nettoyage des objets $(OBJS_D)"
					@rm -rf $(OBJS_D)

fclean			:
					@make -C $(LFT_D) fclean
					@echo "Nettoyage des objets $(OBJS_D)"
					@rm -rf $(OBJS_D)
					@echo "Nettoyage de l'exécutable $(NAME)"
					@rm -f $(NAME)

re				:	fclean all

debug			:	force
					@$(eval FLAG = "$(FLAG) $(FLAGDEV)"))

force			:
					@true

.PHONY			:	all clean fclean re force debug dev
