# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: guillaumecools <guillaumecools@student.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/16 13:04:57 by kederhet          #+#    #+#              #
#    Updated: 2025/01/23 11:47:31 by guillaumeco      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
# INCLUDE = libft.h
CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar -r

SOURCES = ft_atoi ft_bzero ft_isalnum		\
		  ft_isalpha ft_isascii ft_isdigit	\
		  ft_isprint ft_memchr ft_memcmp	\
		  ft_memcpy ft_memset ft_strchr		\
		  ft_strlcat ft_strlcpy ft_strlen	\
		  ft_strncmp ft_strnstr ft_strrchr	\
		  ft_tolower ft_toupper ft_strdup	\
		  ft_calloc ft_substr ft_strjoin	\
		  ft_strtrim ft_split ft_memmove	\
		  ft_itoa ft_strmapi ft_striteri	\
		  ft_putchar_fd ft_putstr_fd		\
		  ft_putendl_fd ft_putnbr_fd
		  

SRCS = $(addsuffix .c, $(SOURCES))
OBJS = $(addsuffix .o, $(SOURCES))

all : $(NAME)

$(NAME) : $(OBJS)
	@$(AR) $(NAME) $(OBJS)

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@rm -rf $(OBJS)

fclean : clean
	@rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re