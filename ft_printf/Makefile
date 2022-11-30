# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yaassila <yaassila@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/17 12:35:41 by yaassila          #+#    #+#              #
#    Updated: 2022/11/23 11:26:56 by yaassila         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a

LIBFT_DIR	=	./libft
LIBFT		=	$(LIBFT_DIR)/libft.a

INCS_DIR	=	./includes

SRCS_DIR	=	./srcs
SRCS		=	$(SRCS_DIR)/ft_printf.c \
				$(SRCS_DIR)/ft_printf_flag_utils.c \
				$(SRCS_DIR)/ft_printf_nbr_utils.c \
				$(SRCS_DIR)/ft_printf_handlers_1.c \
				$(SRCS_DIR)/ft_printf_handlers_2.c

OBJS		=	$(SRCS:.c=.o)

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
AR			=	ar
ARFLAGS		=	-rcs
RM			=	rm -f

$(NAME): $(OBJS) $(LIBFT)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -I $(INCS_DIR) -I $(LIBFT_DIR) -c $< -o $@

$(LIBFT):
	make bonus -C $(LIBFT_DIR)
	cp $(LIBFT) $(NAME)

all: $(NAME)

clean:
	make clean -C $(LIBFT_DIR)
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
