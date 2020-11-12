# NAME = libftprintf.a

# LIBFT = libft.a

# FLAGS = gcc -Wall -Wextra -Werror $(LIBFT_H) -c -o

# LIBFT_H = -I srcs/libft/

# SRC_DIR = srcs/
# OBJ_DIR = obj/
# LIB_DIR = srcs/libft/

# CFILES = main.c

# CFIND = $(CFILE:%=$(SRC_DIR)%)

# OFILES = $(CFILE:%.c=%.o)

# OBJ = $(addprefix $(OBJ_DIR), $(OFILES))

# all: $(OBJ_DIR) $(NAME)

# $(OBJ_DIR):
# 			@mkdir -p $(OBJ_DIR)

# $(NAME): $(OBJ)
# 				@make -C $(LIB_DIR)
# 				@mv $(LIBFT_A) $(NAME)
# 				ar -src $(NAME)
