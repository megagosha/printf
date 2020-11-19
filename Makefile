NAME = libftprintf.a

LIBFT = libft.a

FLAGS = gcc -Wall -Wextra -Werror $(LIBFT_H) -c -o

LIBFT_H = -I srcs/libft/
PRINTF_H = -I srcs/

SRC_DIR = srcs/
OBJ_DIR = obj/
LIB_DIR = srcs/libft/

CFILES = ft_printf.c ft_putnbr_base.c ft_putstr.c printer.c apply_params.c ft_itoa_unsigned.c

CFIND = $(CFILES:%=$(SRC_DIR)%)

OFILES = $(CFILES:%.c=%.o)

OBJ = $(addprefix $(OBJ_DIR), $(OFILES))

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
			@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ)
				@make -C $(LIB_DIR)
				@echo Copy $(LIB_DIR)$(LIBFT) to root
				@cp $(LIB_DIR)$(LIBFT) .
				@mv $(LIBFT) $(NAME)
				@echo $(NAME) $(OBJ)
				ar -src $(NAME) $(addprefix $(OBJ_DIR), $(OFILES))
$(OBJ): $(CFIND)
				@$(MAKE) $(OFILES)
$(OFILES):
			@echo Compiled: $(@:obj/%=%)
			@$(FLAGS) $(OBJ_DIR)$@ $(SRC_DIR)$(@:%.o=%.c)
clean:
				/bin/rm -rf $(OBJ_DIR)

fclean:			clean
				/bin/rm -f $(NAME)

re: 			fclean all

.PHONY:			all clean flcean re
