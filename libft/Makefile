# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsaleh <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 18:15:53 by rsaleh            #+#    #+#              #
#    Updated: 2019/01/16 17:16:39 by rsaleh           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME      = libft.a

CC        = gcc
C_FLAGS   = -Wall -Wextra -Werror

HEADER    = libft.h

OBJDIR    = obj/

FILES = ft_isblank.c ft_atoi_only.c ft_free_tabchar.c ft_strichr.c ft_realloc.c ft_power.c ft_charswap.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c  ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_nbwords.c ft_strclength.c ft_itoa.c ft_swap.c ft_count.c ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_strlcpy.c

OBJ = $(addprefix $(OBJDIR), $(patsubst %.c, %.o, $(notdir $(FILES))))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@printf "Created $@\n"
	
$(OBJDIR)%.o: %.c
	@mkdir -p $(OBJDIR)
	@gcc -c -o $@ $< $(C_FLAGS)
	@printf "Compiling $@\n"
	
clean:
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all
