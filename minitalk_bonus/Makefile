NAME = server

NAME2 = client

RED = \033[0;31m

GREEN = \033[0;32m

SRC = ft_printf.c client_bonus.c server_bonus.c

OBJ = (SRC:.c=.o)

CC = cc -Wall -Wextra -Werror

all : $(NAME) $(NAME2)

%.o : %.c minitalk.h
	@$(CC) -c $?

server : server_bonus.o ft_printf.o
	@$(CC) -o server server_bonus.o ft_printf.o
	@rm -rf server_bonus.o ft_printf.o
	@echo "$(GREEN) FILES COOKING ✅"

client : client_bonus.o ft_printf.o
	@$(CC) -o client client_bonus.o ft_printf.o
	@rm -rf client_bonus.o ft_printf.o
	@echo "$(GREEN) FILES COOKING ✅"

clean :
	@rm -rf $(NAME) $(NAME2)
	@echo "$(RED)DELETED ❌"