# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asenat <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/07 17:26:46 by asenat            #+#    #+#              #
#    Updated: 2017/06/15 16:02:33 by asenat           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
CC 		= gcc
FLAG 	= -Wall -Wextra -Werror
RM		= rm -Rf
OBJDIR	= obj/
SRC = ft_atoi.c ft_itoa.c ft_memmove.c ft_putstr.c \
	  ft_strdel.c ft_strlen.c ft_strnew.c ft_tolower.c \
	  ft_bzero.c ft_memalloc.c ft_memset.c ft_putstr_fd.c \
	  ft_strdup.c ft_strmap.c ft_strnstr.c ft_toupper.c \
	  ft_isalnum.c ft_memccpy.c ft_putchar.c ft_strcat.c \
	  ft_strequ.c ft_strmapi.c ft_strrchr.c ft_isalpha.c \
	  ft_memchr.c ft_putchar_fd.c ft_strchr.c ft_striter.c \
	  ft_strncat.c ft_strsplit.c ft_isascii.c ft_memcmp.c \
	  ft_putendl.c ft_strclr.c ft_striteri.c ft_strncmp.c \
	  ft_strstr.c ft_isdigit.c ft_memcpy.c ft_putendl_fd.c \
	  ft_strcmp.c ft_strjoin.c ft_strncpy.c ft_strsub.c \
	  ft_isprint.c ft_memdel.c ft_putnbr.c ft_strcpy.c \
	  ft_strlcat.c ft_strnequ.c ft_strtrim.c ft_putnbr_fd.c \
	  ft_lstadd.c ft_lstadd_back.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c \
	  ft_lstiter.c ft_lstrev.c ft_lstmap.c ft_isspace.c ft_isblank.c \
	  ft_islower.c ft_isupper.c ft_strrev.c ft_pow.c ft_realloc.c \
	  ft_putnstr.c ft_lstlen.c ft_putwchar_fd.c ft_wcharsize.c \
	  ft_putwchar.c ft_putwstr.c ft_putwstr_fd.c ft_putnbyteswstr.c \
	  ft_wstrsize.c ft_wstrlen.c ft_getcolor.c \
	  ft_strappend.c ft_strcappend.c ft_getnblen.c ft_queue.c get_next_line.c \
	  ft_pathappend.c ft_putcolored.c ft_strncappend.c ft_removechar.c \
	  ft_strnappend.c ft_doublearraydel.c ft_tnewnode.c ft_tdelone.c ft_tdel.c \
	  ft_taddnode.c ft_lstpopnext.c ft_isstrnum.c ft_taddrnode.c ft_lstnewraw.c \
	  ft_iswellquoted.c ft_splitfilepath.c ft_star_match.c ft_lstgetlast.c ft_putnchar.c \
	  ft_doublearrayndel.c ft_strescape.c

SRCS = $(addprefix srcs/, $(SRC))
OBJ = $(addprefix obj/, $(SRC:.c=.o))

BLUE	= "\033[34m"
GREEN	= "\033[32m"
RESET	= "\033[0m"
PNAME	= $(BLUE)$(NAME)$(RESET)

all: $(NAME)

$(NAME): $(OBJDIR) $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo $(PNAME)$(GREEN) "generated !"$(RESET)

obj/%.o: srcs/%.c includes/libft.h
	@$(CC) -o $@ -c $< $(FLAGS) -I includes
	@echo $(GREEN)"Libft: "$(RESET)$@

$(OBJDIR):
	@mkdir -p $(OBJDIR)

clean:
	@echo "Cleaning objects..."
	@$(RM) $(OBJ)
	@rm -rf $(OBJDIR)
	@echo "Done."

fclean: clean
	@$(RM) $(NAME)
	@echo $(PNAME) "deleted."

re: fclean all

.PHONY: clean fclean re all
