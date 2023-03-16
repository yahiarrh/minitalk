NAME = server

NAME2 = client

RED = \033[0;31m

GREEN = \033[0;32m

SRC = ft_printf.c client.c server.c

OBJ = (SRC:.c=.o)

CC = cc -Wall -Wextra -Werror

all : $(NAME) $(NAME2)

%.o : %.c minitalk.h
	@$(CC) -c $<

server : server.o ft_printf.o
	@$(CC) -o server server.o ft_printf.o
	@rm -rf server.o
	@echo "$(GREEN) FILES COOKING ✅"

client : client.o ft_printf.o
	@$(CC) -o client client.o ft_printf.o
	@rm -rf client.o ft_printf.o
	@echo "$(GREEN) FILES COOKING ✅"

clean :
	@rm -rf $(NAME) $(NAME2)
	@echo "$(RED)DELETED ❌"