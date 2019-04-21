# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/29 19:51:11 by hben-yah          #+#    #+#              #
#    Updated: 2019/03/29 19:51:11 by hben-yah         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	libft.a

COMP			=	clang
FLAG			=	-Wall -Wextra -Werror
FLAGDEV         =   -g3 -std=c89 -pedantic

# Sources paths
FILES_C			=   \
					boolean/ft_is_base.c \
					boolean/ft_isalnum.c \
					boolean/ft_isalpha.c \
					boolean/ft_isascii.c \
					boolean/ft_isdigit.c \
					boolean/ft_ishexa.c \
					boolean/ft_islower.c \
					boolean/ft_isprime.c \
					boolean/ft_isprint.c \
					boolean/ft_isspace.c \
					boolean/ft_isspace_wnt.c \
					boolean/ft_isupper.c \
					char/ft_charswap.c \
					char/ft_tolower.c \
					char/ft_toupper.c \
					collection/arraylist.c \
					convert/ft_atoi.c \
					convert/ft_atoi_base.c \
					convert/ft_atol.c \
					convert/ft_atol_base.c \
					convert/ft_convert_base.c \
					convert/ft_itoa.c \
					convert/ft_itoa_base.c \
					convert/ft_ltoa.c \
					input/get_next_line.c \
					integer/ft_intswap.c \
					integer/ft_nbrlen.c \
					list/ft_lstadd.c \
					list/ft_lstcnt.c \
					list/ft_lstdel.c \
					list/ft_lstdelone.c \
					list/ft_lstiter.c \
					list/ft_lstmap.c \
					list/ft_lstnew.c \
					list/ft_lstrev.c \
					math/ft_abs.c \
					math/ft_max.c \
					math/ft_min.c \
					math/ft_pow.c \
					math/ft_sqrt.c \
					memory/ft_bzero.c \
					memory/ft_memalloc.c \
					memory/ft_memccpy.c \
					memory/ft_memchr.c \
					memory/ft_memcmp.c \
					memory/ft_memcpy.c \
					memory/ft_memdel.c \
					memory/ft_memmove.c \
					memory/ft_memset.c \
					misc/ft_indexof.c \
					misc/ft_linear_interpolate.c \
					output/ft_putchar.c \
					output/ft_putchar_fd.c \
					output/ft_putendl.c \
					output/ft_putendl_fd.c \
					output/ft_putnbr.c \
					output/ft_putnbr_base.c \
					output/ft_putnbr_fd.c \
					output/ft_putnbrtab.c \
					output/ft_putstr.c \
					output/ft_putstr_fd.c \
					output/ft_putstrnbr.c \
					output/ft_putstrpad.c \
					output/ft_putstrtab.c \
					output/ft_putstrtab_fd.c \
					sort/ft_sortinttab.c \
					sort/ft_sortstrtab.c \
					string/ft_hasnodupl.c \
					string/ft_printabilize.c \
					string/ft_split_chars.c \
					string/ft_stralloc.c \
					string/ft_strcat.c \
					string/ft_strchr.c \
					string/ft_strclr.c \
					string/ft_strcmp.c \
					string/ft_strcpy.c \
					string/ft_strdel.c \
					string/ft_strdup.c \
					string/ft_strequ.c \
					string/ft_striter.c \
					string/ft_striteri.c \
					string/ft_strjoin.c \
					string/ft_strjoinf.c \
					string/ft_strjoinfs.c \
					string/ft_strlastchr.c \
					string/ft_strlcat.c \
					string/ft_strlcpy.c \
					string/ft_strlen.c \
					string/ft_strmap.c \
					string/ft_strmapi.c \
					string/ft_strmove.c \
					string/ft_strncat.c \
					string/ft_strncmp.c \
					string/ft_strncpy.c \
					string/ft_strnequ.c \
					string/ft_strnew.c \
					string/ft_strnstr.c \
					string/ft_strover.c \
					string/ft_strrchr.c \
					string/ft_strrealloc.c \
					string/ft_strrev.c \
					string/ft_strrmvchr.c \
					string/ft_strsplit.c \
					string/ft_strstr.c \
					string/ft_strsub.c \
					string/ft_strtolower.c \
					string/ft_strtoupper.c \
					string/ft_strtrim.c \
					string/ft_wrdcnt.c \
					string/stringbuffer/stringbuffer.c \
					table/ft_strtabdel.c \
					table/ft_strtabdup.c \
					table/ft_strtabjoin.c \
					table/ft_tabadd.c \
					table/ft_taballoc.c \
					table/ft_tabcpy.c \
					table/ft_tabdel.c \
					table/ft_tablcpy.c \
					table/ft_tablen.c \
					table/ft_tabncpy.c \
					table/ft_tabnew.c \
					table/ft_tabrealloc.c \
					table/ft_tabswap.c
FILES_O			=	$(FILES_C:.c=.o)
FILES_H			=	\
					ft_defines.h \
					ft_prototypes.h \
					ft_structs.h \
					libft.h

# Directories
SRCS_SD			= 	\
					boolean \
					char \
					collection \
					convert \
					input \
					integer \
					list \
					math \
					memory \
					misc \
					output \
					sort \
					string \
					string/stringbuffer \
					table
SRCS_D			=	./srcs/
OBJS_D			=   ./objs/
INCL_D 			=	./includes/

# Paths
SRCS			= 	$(addprefix $(SRCS_D), $(FILES_C))
OBJS			=	$(addprefix $(OBJS_D), $(FILES_O))
INCL			=	$(addprefix $(INCL_D), $(FILES_H))



# Termcaps

TRMCP_I			=	-ltermcap

# Rules

all				:	$(NAME)

dev				:	debug $(NAME)

$(NAME)			:	$(OBJS)
					@echo "\nAssemblage et création de la librairie $(NAME)"
					@ar rc $(NAME) $(OBJS)
					@ranlib $(NAME)
					@echo "Libft terminée"

$(OBJS_D)%.o	:	$(SRCS_D)%.c $(INCL)
					@echo -e "\033[2K\c"
					@echo "\rCréation de l'objet $@\c"
					@mkdir -p $(addprefix $(OBJS_D), $(SRCS_SD))
					@$(COMP) $(FLAG) -I $(INCL_D) -o $@ -c $<

clean			:
					@echo "Nettoyage des objets ./libft/objs/"
					@rm -rf $(OBJS_D)

fclean			:	clean
					@echo "Nettoyage de la librairie $(NAME)"
					@rm -f $(NAME)

re				:	fclean all

debug			:	force
					@$(eval FLAG = "$(FLAG) $(FLAGDEV)")

force			:
					@true

.PHONY			:	all clean fclean re force debug dev
