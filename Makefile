SRC	= server.c client.c

SERVER = server

CLIENT = client

CFLAGS	= -Wall -Werror -Wextra 

CC		= cc

RM 		= rm -rf

LIBFTH = minitalk.h

OBJS	= $(SRC:.c=.o)

all : $(SERVER) $(CLIENT) $(NAME)

%.o :  %.c  
	$(CC) $(CFLAGS) -o $(SERVER) ft_printf.c server.c
	$(CC) $(CFLAGS) -o $(CLIENT) ft_printf.c client.c

#clean : $(OBJS)
#	$(RM) server client

#fclean : clean


#re : fclean all

#.PHONY : all clean fclean re