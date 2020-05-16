NAME	:=	ft_select
FILES	:=	main

SRC_D	:=	src
INC_D	:=	inc
OBJ_D	:=	objs
LIB_D	:=	libft

SRC		:=	$(addprefix $(SRC_D)/, $(patsubst %, %.c, $(FILES)))
OBJ		:=	$(addprefix $(OBJ_D)/, $(patsubst %, %.o, $(FILES))) 

SUB_DIR := $(OBJ_D)

FLAGS	:=	-g #-Wall -Wextra -Werror
LIB_LNK :=	-L$(LIB_D) -lft -ltermcap

.PHONY: clean fclean re begin_work

all: begin_work $(NAME)

begin_work:
	@make -C $(LIB_D)

$(SUB_DIR):
	@mkdir $@

$(NAME): libft/libft.a $(SUB_DIR) $(OBJ)
	@gcc $(FLAGS) $(OBJ) $(LIB_LNK) -o $(NAME)
	@printf "\r\033[32;1mCreate $(NAME)!                                      \n\033[0m"
	@printf "\033[?25h"

$(OBJ_D)/%.o: $(SRC_D)/%.c $(INC_D)/colors.h $(INC_D)/keys.h
	@printf "\033[?25l"
	@gcc -I$(INC_D) -I$(LIB_D) -I$(INCL_DIR_CALC) $(FLAGS) -o $@ -c $<
	@printf "\r\033[34;1mNow compiling $@!                                    \033[0m"

clean:
	@make -C $(LIB_D) fclean
	@/bin/rm -f $(OBJ)
	@printf "\r\033[31mDell all for $(NAME)!                                  \n\033[0m"

fclean: clean
	@/bin/rm -f $(NAME)
	@printf "\r\033[31;1mDell $(NAME)!                                        \n\033[0m"

re: fclean all