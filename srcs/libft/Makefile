# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edebi <edebi@student.21-school.ru>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/23 21:47:39 by edebi             #+#    #+#              #
#    Updated: 2020/11/11 02:37:22 by edebi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJ_DIR = obj/

SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c \
       ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
	   ft_issprint.c ft_memccpy.c ft_memchr.c ft_memcmp.c \
	   ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c \
	   ft_strdup.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c \
	   ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c \
	   ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c \
	   ft_split.c ft_itoa.c ft_strmapi.c ft_putchar_fd.c \
	   ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	   ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
		ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
		ft_lstclear.c ft_lstiter.c ft_lstmap.c

NAME =			libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror -c -o

OFILE =			$(SRCS:%.c=%.o)

OBJ =			$(addprefix $(OBJ_DIR), $(OFILE))

all:			$(OBJ_DIR) $(NAME)
				@echo Library created

$(OBJ_DIR):
				mkdir -p $(OBJ_DIR)
				@echo Created objects directory

$(NAME): $(OBJ) libft.h
				ar -src $(NAME) $(addprefix $(OBJ_DIR), $(OFILE))

$(OBJ): $(SRCS)
				$(MAKE) $(OFILE)

$(OFILE):
				$(CC) $(CFLAGS) $(OBJ_DIR)$@ $(SRC_DIR)$(@:%.o=%.c)

clean:
				/bin/rm -rf $(OBJ_DIR)

fclean:			clean
				/bin/rm -f $(NAME)

re: 			fclean all

.PHONY:			all clean flcean re
