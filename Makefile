# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/08 16:22:01 by jdaufin           #+#    #+#              #
#    Updated: 2017/03/17 10:18:13 by jdaufin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PRONY : clean fclean

NAME = libft.a
SRC = ft_atoi.c ft_memdel.c ft_strcat.c ft_strncat.c ft_bzero.c\
	  ft_memmove.c ft_strchr.c ft_strncpy.c ft_isalnum.c ft_memset.c ft_strclr.c ft_strnequ.c\
	  ft_isalpha.c ft_putbstr.c ft_strcmp.c ft_strnew.c ft_isascii.c ft_putchar.c\
	  ft_strcpy.c ft_strnstr.c ft_isdigit.c ft_putchar_fd.c ft_strdup.c ft_strrchr.c ft_isprint.c\
	  ft_putendl.c ft_strequ.c ft_strstr.c ft_memalloc.c ft_putendl_fd.c ft_striter.c ft_tolower.c\
	  ft_memccpy.c ft_putnbr.c ft_striteri.c ft_toupper.c ft_memchr.c ft_putnbr_fd.c ft_strlen.c\
	  ft_memcmp.c ft_putstr.c ft_strmap.c ft_memcpy.c ft_putstr_fd.c ft_strmapi.c\
	  ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strlcat.c ft_strlcpy.c ft_strsplit.c ft_itoa.c\
	  ft_wordcount.c ft_putstrtab.c ft_strncmp.c ft_strdel.c ft_lstnew.c ft_lstadd.c ft_lstdel.c\
	  ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstappend.c ft_lstinsert.c\
	  ft_realloc.c
OBJ = $(SRC:.c=.o)
HDR = libft.h
CCFLAGS = -Wall -Wextra -Werror -g

all : $(NAME)

$(NAME) : $(OBJ)
	@ar -urc $@ $^
	@ranlib $@

$(OBJ) : $(SRC) $(HDR)
	@gcc $(CCFLAGS) -c $(SRC) -I .

clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean all
