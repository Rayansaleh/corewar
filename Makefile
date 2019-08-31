# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsaleh <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/31 17:42:02 by rsaleh            #+#    #+#              #
#    Updated: 2019/08/31 22:39:06 by rsaleh           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS		=	-Wall -Wextra -Werror
NAME		=	asm
SRCDIR		=	./
OBJDIR		=	obj/
FILES		=	./main.c ./cmd_input.c ./get_next_line.c lexer/free_lexer.c \
				lexer/get_dote_start.c lexer/get_string.c lexertab_token.c \
				lexer/get_comment_sep.c lexer/get_indirect.c lexer/lexer.c \
				lexer/get_direct.c lexer/get_label.c lexer/line_to_token.c \
				op/op.c op/swap.c ast_to_byte/ast_to_byte.c \
				ast_to_byte/len_prog.c ast_to_byte/write_header.c \
				ast_to_byte/write_param.c ast_to_byte/feed_label.c \
				ast_to_byte/open_new_file.c ast_to_byte/write_insts.c \
				parser/ast_add_inst.c parser/check_ast.c \
				parser/check_registres.c parser/parser.c \
				parser/ast_add_next.c parser/check_insts.c \
				parser/free_parser.c parser/ast_dote_start.c \
				parser/check_labels.c parser/inst_add_params.c \
				print/print_ast.c print/print_error.c print/print_tab_token.c
INCLUDE		=	includes/
OBJ			=	$(addprefix $(OBJDIR), $(patsubst %.c, %.o, $(FILES)))

all: $(NAME)

$(NAME): $(OBJ)
	make -C printf
	gcc -o $(NAME) $(OBJDIR)*.o

$(OBJDIR)%.o: $(SRCDIR)%.c  
	mkdir -p $(OBJDIR)
	gcc -o $@ -c $< $(CFLAGS) -I $(INCLUDE)

clean:
	make clean -C printf
	rm -rf $(OBJDIR)

fclean: clean
	make fclean -C printf
	rm -rf $(NAME)

re: fclean all
