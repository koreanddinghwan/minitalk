# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myukang <myukang@student.42.kr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/09 15:53:38 by myukang           #+#    #+#              #
#    Updated: 2022/05/10 19:19:29 by myukang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
SERVER = server
CLIENT = client
GCC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT = ./libft.a
INC = ./includes/
DIR = ./minitalk_srcs/

CLIENT_SRCS = client.c
CLIENT_OBJS_O = $(CLIENT_SRCS:.c=.o)
CLIENT_OBJS = $(addprefix $(DIR), $(CLIENT_OBJS_O))

SERVER_SRCS = server.c 
SERVER_OBJS_O = $(SERVER_SRCS:.c=.o)
SERVER_OBJS = $(addprefix $(DIR), $(SERVER_OBJS_O))

OBJ_FILES = $(CLIENT_OBJS) $(SERVER_OBJS)

all : $(LIBFT) $(SERVER) $(CLIENT)

$(NAME) : all

$(LIBFT) : 
	make -C ./libft/
	mv ./libft/$(LIBFT) ./$(LIBFT)

$(SERVER) : $(SERVER_OBJS)
	$(GCC) $(CFLAGS) -o $(SERVER) $^ $(LIBFT)

$(CLIENT) : $(CLIENT_OBJS)
	$(GCC) $(CFLAGS) -o $(CLIENT) $^ $(LIBFT)

%.o : %.c
	$(GCC) $(CFLAGS) -c -o $@ -I$(INC) $^

clean : 
	make clean -C ./libft
	rm -rf $(OBJ_FILES) $(LIBFT) $(SERVER) $(CLIENT)

fclean : 
	make clean
	rm -rf $(OBJ_FILES) $(NAME)

re : 
	make fclean
	make all
	
.PHONY : all clean fclean re
