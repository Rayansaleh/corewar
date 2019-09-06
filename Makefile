# **************************************************************************** #
# PROGRAM                                                                      #
# **************************************************************************** #

NAME		=	asm
NAME_ONLY	=	$(basename $(NAME))

# **************************************************************************** #
# SOURCES                                                                      #
# **************************************************************************** #

FILES				=	main.c \
						cmd_input.c \
						get_next_line.c 
SRCDIR				=	./

LEXER 				=	free_lexer.c\
						get_dote_start.c \
						get_string.c \
						tab_token.c \
						get_comment_sep.c \
						get_indirect.c \
						lexer.c \
						get_direct.c \
						get_label.c \
						line_to_token.c 

LEXERDIR			=	./lexer/
FILES_LEXER 		=	$(addprefix $(LEXERDIR), $(LEXER))

OP					=	op.c \
						swap.c 
OPDIR				=	./op/
FILES_OP			=	$(addprefix $(OPDIR), $(OP))

AST_TO_BYTE			=	ast_to_byte.c \
						len_prog.c \
						write_header.c \
						write_param.c \
						feed_label.c \
						open_new_file.c \
						write_insts.c 
ATBDIR				=	./ast_to_byte/
FILES_AST_TO_BYTE	=	$(addprefix $(ATBDIR), $(AST_TO_BYTE))

PARSER				=	ast_add_inst.c \
						check_ast.c \
						check_registres.c \
						parser.c \
						ast_add_next.c \
						check_insts.c \
						free_parser.c \
						ast_dote_start.c \
						check_labels.c \
						inst_add_params.c
PARSERDIR			=	./parser/
FILES_PARSER		=	$(addprefix $(PARSERDIR), $(PARSER))

PRINT				=	print_ast.c \
						print_error.c \
						print_tab_token.c
PRINTDIR			=	./print/
FILES_PRINT			=	$(addprefix $(PRINTDIR), $(PRINT))

DPD					=	$(addprefix $(OBJ_PATH), $(FILES:=.d))

# **************************************************************************** #
# OBJECT                                                                       #
# **************************************************************************** #

OBJ			=	$(FILES:.c=.o)
OBJ			+=	$(LEXER:.c=.o)
OBJ			+=	$(OP:.c=.o)
OBJ			+=	$(AST_TO_BYTE:.c=.o)
OBJ			+=	$(PARSER:.c=.o)
OBJ			+=	$(PRINT:.c=.o)
OBJ_PATH	=	./objs/
OBJS		=	$(addprefix $(OBJ_PATH), $(OBJ))
OBJS_DIRS	=	$(sort $(dir $(OBJS)))

# **************************************************************************** #
# INCLUDES                                                                     #
# **************************************************************************** #

INC_PATH		=	./includes/
INCS_DIRS		=	$(addsuffix , $(INC_PATH))
INCS			=	$(addprefix -I , $(INCS_DIRS))

PRINTF			=	libftprintf.a
PRINTF_PATH		=	./printf/
PRINTFS_DIRS	=	$(addsuffix , $(PRINTF_PATH))
PRINTFS			=	$(addprefix $(PRINTFS_DIRS), $(PRINTF))

INCPRINTF_PATH		=	$(addsuffix includes/, $(PRINTFS_DIRS))
INCPRINTFS_DIRS	=	$(addsuffix , $(INCPRINTF_PATH))
INCPRINTFS			=	$(addprefix -I , $(INCPRINTFS_DIRS))

# **************************************************************************** #
# COLORS AND EFFECT                                                            #
# **************************************************************************** #

CE_NOCOLOR		=	\033[00m
CE_CLEAR		=	\033[2K
CE_UP 			=	\033[A
CE_BLACK		=	\033[30m
CE_RED			=	\033[31m
CE_GREEN		=	\033[32m
CE_YELLOW		=	\033[33m
CE_BLUE			=	\033[34m
CE_PURPLE		=	\033[35m
CE_CYAN			=	\033[36m
CE_WHITE		=	\033[37m
CE_SUR_BLACK	=	\033[40m
CE_SUR_RED		=	\033[41m
CE_SUR_GREEN	=	\033[42m
CE_SUR_YELLOW	=	\033[43m
CE_SUR_BLUE		=	\033[44m
CE_SUR_PURPLE	=	\033[45m
CE_SUR_CYAN		=	\033[46m
CE_SUR_WHITE	=	\033[47m
CE_GRAS			=	\033[1m
CE_SOUS			=	\033[4m

# **************************************************************************** #
# DBG MESSAGE                                                                  #
# **************************************************************************** #

MESS_ERROR		=	$(CE_RED)->ERROR<-$(CE_NOCOLOR)
MESS_WARNING	=	$(CE_YELLOW)->WARNING<-$(CE_NOCOLOR)
MESS_FAIL		=	$(CE_CYAN)->FAIL<-$(CE_NOCOLOR)
MESS_OK			=	$(CE_GREEN)... ->OK<-$(CE_NOCOLOR)
MESS_SUCCESS	=	$(CE_GREEN)->SUCCESS<-$(CE_NOCOLOR)
MESS_VALIDED	=	$(CE_GREEN)[ ✓ ]$(CE_NOCOLOR)
MESS_CURRENT	=	$(CE_CYAN)[ $@ ]$(CE_NOCOLOR)
MESS_COMPILED	=	$(CE_YELLOW)Compiled ==>>$(CE_NOCOLOR)
MESS_COMPIL		=	$(CE_YELLOW)-- Compiling$(CE_NOCOLOR)
MESS_ADD		=	$(CE_YELLOW)created ==>>$(CE_NOCOLOR)
MESS_DEL		=	$(CE_RED)==>> deleted$(CE_NOCOLOR)
MESS_NODEL		=	$(CE_CYAN)==>> nothing to delete$(CE_NOCOLOR)
MESS_NAME		=	$(CE_SUR_BLUE)$(CE_GRAS)$(CE_PURPLE)[ $(NAME_ONLY) ]$(CE_NOCOLOR)
MESS_ASSEMBLING	=	$(CE_GRAS)$(CE_YELLOW)Assembling ==>>$(CE_NOCOLOR)

# **************************************************************************** #
# PRINT                                                                        #
# **************************************************************************** #

ECHO_ASSEMBLING		=	$(MESS_NAME) $(MESS_ASSEMBLING) $(MESS_CURRENT) $(MESS_VALIDED)
ECHO_COMPILED		=	$(MESS_NAME) $(MESS_COMPILED) $(MESS_CURRENT) $(MESS_VALIDED)
ECHO_COMPIL			=	$(MESS_NAME) $(ACTUAL) / $(NBSRC) $(MESS_COMPIL) $(MESS_CURRENT) $(MESS_OK) $(CE_UP)	\
						$(eval ACTUAL=$(shell echo $$(($(ACTUAL) + 1))))
ECHO_OBJ_DIRECTORY	=	$(MESS_NAME) $(MESS_ADD) $(CE_BLUE)[ objs/ ] directory$(CE_NOCOLOR) $(MESS_SUCCESS)
ECHO_DELOBJ			=	$(MESS_NAME) $(CE_BLUE)[ OBJS.o ]$(CE_NOCOLOR) $(MESS_DEL) $(MESS_SUCCESS)
ECHO_NODELOBJ		=	$(MESS_NAME) $(CE_BLUE)[ OBJS.o ]$(CE_NOCOLOR) $(MESS_NODEL)
ECHO_DELALL			=	$(MESS_NAME) $(CE_CYAN)[ $(NAME) ]$(CE_NOCOLOR) $(MESS_DEL) $(MESS_SUCCESS)
ECHO_NODELALL		=	$(MESS_NAME) $(CE_CYAN)[ $(NAME) ]$(CE_NOCOLOR) $(MESS_NODEL)
ECHO_AUTEUR			=	$(CE_GREEN)=> AUTEUR CREATED <=$(CE_NOCOLOR)
ECHO_LOG			=	$(CE_SUR_BLACK)$(CE_GREEN)$(CE_GRAS)
ECHO_LOG2			=	$(CE_SUR_BLACK)$(CE_BLUE)$(CE_GRAS)

# **************************************************************************** #
# VAR INT                                                                      #
# **************************************************************************** #

NBSRC	=	$(words $(SRC))
ACTUAL	=	1

# **************************************************************************** #
# COMPILATION & ORDER                                                          #
# **************************************************************************** #

CC		=	clang
CFLAGS	=	-g3 -Wall -Wextra -Werror -MMD
ECHO	=	echo "$(CE_CLEAR)"
MKDIR	=	mkdir -p
RM		=	rm -f
RMR		=	rm -R
LDFLAGS	=	$(addprefix -L, $(PRINTF_PATH))
LDPRINTFS	=	-lft
LDFLAGS2	=	$(addprefix -L, ./libft/)

# **************************************************************************** #
# RULES                                                                        #
# **************************************************************************** #

opti:
	$(MAKE) all

all: objs makeprintf $(NAME)

$(NAME): $(PRINTFS) $(OBJS)
	$(ECHO)"$(ECHO_ASSEMBLING)"
	$(CC) $(CFLAGS) $(LDFLAGS) $(LDFLAGS2) $(LDPRINTFS) $^ -o $@ $(INCS) $(INCPRINTFS)
	$(ECHO)"$(ECHO_COMPILED)"

makeprintf:
	$(MAKE) all -C $(PRINTFS_DIRS)

objs:
	$(MKDIR) $(OBJS_DIRS)
	$(ECHO)"$(ECHO_OBJ_DIRECTORY)"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) $(CFLAGS) -o $@ -c $< $(INCS) $(INCPRINTFS)
	$(ECHO) "$(ECHO_COMPIL)"

$(OBJ_PATH)%.o: %.c
	gcc -o $@ -c $< $(CFLAGS) -I $(INC_PATH)
	$(ECHO) "$(ECHO_COMPIL)"
$(OBJ_PATH)%.o: $(ATBDIR)%.c
	gcc -o $@ -c $< $(CFLAGS) -I $(INC_PATH)
	$(ECHO) "$(ECHO_COMPIL)"
$(OBJ_PATH)%.o: $(LEXERDIR)%.c
	gcc -o $@ -c $< $(CFLAGS) -I $(INC_PATH)
	$(ECHO) "$(ECHO_COMPIL)"
$(OBJ_PATH)%.o: $(OPDIR)%.c
	gcc -o $@ -c $< $(CFLAGS) -I $(INC_PATH)
	$(ECHO) "$(ECHO_COMPIL)"
$(OBJ_PATH)%.o: $(PARSERDIR)%.c
	gcc -o $@ -c $< $(CFLAGS) -I $(INC_PATH)
	$(ECHO) "$(ECHO_COMPIL)"
$(OBJ_PATH)%.o: $(PRINTDIR)%.c
	gcc -o $@ -c $< $(CFLAGS) -I $(INC_PATH)
	$(ECHO) "$(ECHO_COMPIL)"

clean:
	$(MAKE) clean -C $(PRINTFS_DIRS)
ifneq ("$(shell ls -R | grep main.o)","")
	$(RMR) $(OBJ_PATH)
	$(ECHO)"$(ECHO_DELOBJ)"
else
	$(ECHO)"$(ECHO_NODELOBJ)"
endif

fclean:		clean
	$(MAKE) fclean -C $(PRINTFS_DIRS)
ifneq ("$(shell ls | grep asm)","")
	$(RM) $(NAME)
	$(ECHO)"$(ECHO_DELALL)"
else
	$(ECHO)"$(ECHO_NODELALL)"
endif

re:
	$(MAKE) fclean
	$(MAKE) all

# **************************************************************************** #
# PHONY                                                                        #
# **************************************************************************** #

.PHONY: all clean fclean re
.SILENT:

-include $(DPD)
