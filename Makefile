# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nikitos <nikitos@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/11 15:34:58 by nikitos           #+#    #+#              #
#    Updated: 2023/03/13 20:23:57 by nikitos          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk

LIBFT = libftPrintf/libft
PRINTF = libftPrintf/src

CLIENT_MAIN =  client.c
SERVER_MAIN = server.c

SERVER = ${SERVER_MAIN:.c=.o}
CLIENT = ${CLIENT_MAIN:.c=.o}

RM = rm -f

CFLAGS = -Wall -Wextra -Werror -g

CC = gcc

all:	$(NAME)

$(NAME):	$(SERVER) $(CLIENT)
			@make -C $(LIBFT)
			@make -C $(PRINTF)
			mv $(LIBFT)/libft.a libft.a
			mv $(PRINTF)/libftprintf.a libftprintf.a
			gcc $(CFLAGS) $(SERVER) $(CLIEN) -L. -lft -lftprintf -o $(NAME)

clean:
		@make -C $(LIBFT) clean
		@make -C $(PRINTF) clean
		$(RM) $(OBJS)
		$(RM) libft.a libftprintf.a

fclean: clean
		${RM} ${NAME}

re:		fclean all

.PHONY:		all clean fclean re