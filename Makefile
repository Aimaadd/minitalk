# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abentaye <abentaye@student.s19.be >        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/30 15:39:35 by abentaye          #+#    #+#              #
#    Updated: 2024/02/06 17:42:30 by abentaye         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = includes/libft
PRINTF = includes/ft_printf
LIBA = libft.a
PRIA = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRCS = ./src/server.c
SRCC = ./src/client.c
SRCSB = ./src_bonus/server_bonus.c
SRCCB = ./src_bonus/client_bonus.c

OBJS = $(SRCS:.c=.o)
OBJC = $(SRCC:.c=.o)
OBJSB = $(SRCSB:.c=.o)
OBJCB = $(SRCCB:.c=.o)

LIBA = $(LIBFT)/libft.a
PRIA = $(PRINTF)/libftprintf.a

all: server client

server: $(OBJS) $(PRIA)
	$(CC) $(CFLAGS) $(OBJS) $(PRIA) -o $@

client: $(OBJC) $(LIBA) $(PRIA)
	$(CC) $(CFLAGS) $(OBJC) $(LIBA) $(PRIA) -o $@

bonus: server_b client_b
server_b: $(OBJSB) $(PRIA)
	$(CC) $(CFLAGS) $(OBJSB) $(PRIA) -o $@

client_b: $(OBJCB) $(LIBA) $(PRIA)
	$(CC) $(CFLAGS) $(OBJCB) $(LIBA) $(PRIA) -o $@

$(PRIA): printf

$(LIBA): libft

libft:
	make -C $(LIBFT)
	cp $(LIBA) .

printf:
	make -C $(PRINTF)
	cp $(PRIA) .

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(OBJC) $(OBJSB) $(OBJCB) $(LIBA) $(PRIA)
	make -C $(LIBFT) clean
	make -C $(PRINTF) clean
	$(RM) server client server_bonus client_bonus

fclean: clean
	$(RM) -r $(LIBFT)/$(LIBA) $(PRINTF)/$(PRIA)
	make -C $(LIBFT) fclean
	make -C $(PRINTF) fclean
	$(RM) server client server_bonus client_bonus server_b client_b libft.a libftprintf.a

finish: fclean

re: fclean all

reall: finish all

.PHONY: all libft printf clean fclean finish re reall bonus
