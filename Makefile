NAME = server

NAME2 = client

RED = \033[0;31m

GREEN = \033[0;32m

SRC = ft_printf.c client.c server.c

SRCB = ft_printf.c client_bonus.c server_bonus.c

OBJ = $(SRCB:.c=.o)

CC = cc -Wall -Wextra -Werror

all : $(NAME) $(NAME2)

%.o : %.c minitalk.h
	@$(CC) -c $<

server : server.o ft_printf.o
	@$(CC) -o $(NAME) server.o ft_printf.o
	@echo "$(GREEN) SERVER READY ✅"

client : client.o ft_printf.o
	@$(CC) -o $(NAME2) client.o ft_printf.o
	@echo "$(GREEN) CLIENT READY ✅"

bonus : $(OBJ) minitalk_bonus.h
	@$(CC) -o $(NAME) server_bonus.o ft_printf.o
	@$(CC) -o $(NAME2) client_bonus.o ft_printf.o
	@echo "$(GREEN) BONUS SERVER & CLIENT ARE READY ✅"

clean :
	@rm -rf client.o ft_printf.o server.o $(OBJ)
	@echo "$(RED) OBJS DELETED ❌"

fclean : clean
	@rm -rf $(NAME) $(NAME2)
	@echo "$(RED) ALL CLEAN 🔥"

re : fclean all
