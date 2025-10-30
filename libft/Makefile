# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ancarol9 <ancarol9@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/15 16:35:56 by ancarol9          #+#    #+#              #
#    Updated: 2025/03/10 18:07:18 by ancarol9         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FILE = src/libft_src/ft_isalpha.c \
	src/libft_src/ft_isdigit.c \
	src/libft_src/ft_isalnum.c \
	src/libft_src/ft_isascii.c \
	src/libft_src/ft_isprint.c \
	src/libft_src/ft_strlen.c \
	src/libft_src/ft_memset.c \
	src/libft_src/ft_bzero.c \
	src/libft_src/ft_memcpy.c \
	src/libft_src/ft_memmove.c \
	src/libft_src/ft_strlcpy.c \
	src/libft_src/ft_strlcat.c \
	src/libft_src/ft_toupper.c \
	src/libft_src/ft_tolower.c \
	src/libft_src/ft_strchr.c \
	src/libft_src/ft_strrchr.c \
	src/libft_src/ft_strncmp.c \
	src/libft_src/ft_strcmp.c \
	src/libft_src/ft_memchr.c \
	src/libft_src/ft_memcmp.c \
	src/libft_src/ft_strnstr.c \
	src/libft_src/ft_atoi.c \
	src/libft_src/ft_atol.c \
	src/libft_src/ft_calloc.c \
	src/libft_src/ft_strdup.c \
	src/libft_src/ft_substr.c \
	src/libft_src/ft_strjoin.c \
	src/libft_src/ft_strtrim.c \
	src/libft_src/ft_split.c \
	src/libft_src/ft_itoa.c \
	src/libft_src/ft_strmapi.c \
	src/libft_src/ft_striteri.c \
	src/libft_src/ft_putchar_fd.c \
	src/libft_src/ft_putstr_fd.c \
	src/libft_src/ft_putendl_fd.c \
	src/libft_src/ft_putnbr_fd.c \
	src/printf_src/ft_printf.c \
	src/printf_src/pf_putchar_fd.c \
	src/printf_src/pf_puthex_fd.c \
	src/printf_src/pf_putnbr_fd.c \
	src/printf_src/pf_putstr_fd.c \
	src/printf_src/pf_putunnbr_fd.c \
	src/gnl_src/get_next_line.c \
	src/gnl_src/get_next_line_utils.c

OBJ = $(FILE:.c=.o)

BONUS = src/libft_src/ft_lstnew_bonus.c \
	src/libft_src/ft_lstadd_front_bonus.c \
	src/libft_src/ft_lstsize_bonus.c \
	src/libft_src/ft_lstlast_bonus.c \
	src/libft_src/ft_lstadd_back_bonus.c \
	src/libft_src/ft_lstdelone_bonus.c \
	src/libft_src/ft_lstclear_bonus.c \
	src/libft_src/ft_lstiter_bonus.c \
	src/libft_src/ft_lstmap_bonus.c


BONUS_OBJ = $(BONUS:.c=.o)

CC = cc

C_FLAGS = -Wall -Wextra -Werror -I .

all : $(NAME)

$(NAME) : $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(C_FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus:	$(OBJ) $(BONUS_OBJ)
	ar rcs $(NAME) $(OBJ) $(BONUS_OBJ)
	

.PHONY: all clean fclean re bonus
