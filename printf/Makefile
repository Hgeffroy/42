# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/13 12:02:28 by hgeffroy          #+#    #+#              #
#    Updated: 2022/11/22 12:46:28 by hgeffroy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Variables

NAME = libftprintf.a
FLAGS = -Wall -Werror -Wextra
AR = ar rcs
CC = cc
RM = rm -f
OBJ_DIR = obj/
SRC_DIR = src/
LIBFT_DIR = libft/
LIBFT = libft.a
HEADER = $(SRC_DIR)ft_printf.h

#Files

SRC_F = ft_printf.c\
		ft_printf_nb.c\
		ft_printf_unb.c\
		ft_printf_char.c\
		
OBJ = $(addprefix $(OBJ_DIR), $(SRC_F:.c=.o))

OBJ_LIBFT = $(LIBFT_DIR)$(OBJ_DIR)ft_atoi.o \
			$(LIBFT_DIR)$(OBJ_DIR)ft_bzero.o \
			$(LIBFT_DIR)$(OBJ_DIR)ft_calloc.o \
			$(LIBFT_DIR)$(OBJ_DIR)ft_isalnum.o \
			$(LIBFT_DIR)$(OBJ_DIR)ft_isalpha.o \
			$(LIBFT_DIR)$(OBJ_DIR)ft_isascii.o \
			$(LIBFT_DIR)$(OBJ_DIR)ft_isdigit.o \
			$(LIBFT_DIR)$(OBJ_DIR)ft_isprint.o \
			$(LIBFT_DIR)$(OBJ_DIR)ft_itoa.o \
			$(LIBFT_DIR)$(OBJ_DIR)ft_memchr.o \
			$(LIBFT_DIR)$(OBJ_DIR)ft_memcmp.o \
			$(LIBFT_DIR)$(OBJ_DIR)ft_memcpy.o \
			$(LIBFT_DIR)$(OBJ_DIR)ft_memmove.o \
			$(LIBFT_DIR)$(OBJ_DIR)ft_memset.o \
			$(LIBFT_DIR)$(OBJ_DIR)ft_putchar_fd.o \
			$(LIBFT_DIR)$(OBJ_DIR)ft_putendl_fd.o \
			$(LIBFT_DIR)$(OBJ_DIR)ft_putnbr_fd.o \
			$(LIBFT_DIR)$(OBJ_DIR)ft_putstr_fd.o \
			$(LIBFT_DIR)$(OBJ_DIR)ft_split.o \
			$(LIBFT_DIR)$(OBJ_DIR)ft_strchr.o \
			$(LIBFT_DIR)$(OBJ_DIR)ft_strdup.o \
			$(LIBFT_DIR)$(OBJ_DIR)ft_striteri.o \
			$(LIBFT_DIR)$(OBJ_DIR)ft_strjoin.o \
			$(LIBFT_DIR)$(OBJ_DIR)ft_strlcat.o \
			$(LIBFT_DIR)$(OBJ_DIR)ft_strlcpy.o \
			$(LIBFT_DIR)$(OBJ_DIR)ft_strlen.o \
			$(LIBFT_DIR)$(OBJ_DIR)ft_strmapi.o \
			$(LIBFT_DIR)$(OBJ_DIR)ft_strncmp.o \
			$(LIBFT_DIR)$(OBJ_DIR)ft_strnstr.o \
			$(LIBFT_DIR)$(OBJ_DIR)ft_strrchr.o \
			$(LIBFT_DIR)$(OBJ_DIR)ft_strtrim.o \
			$(LIBFT_DIR)$(OBJ_DIR)ft_substr.o \
			$(LIBFT_DIR)$(OBJ_DIR)ft_tolower.o \
			$(LIBFT_DIR)$(OBJ_DIR)ft_toupper.o \
			$(LIBFT_DIR)$(OBJ_DIR)ft_lstadd_back.o \
			$(LIBFT_DIR)$(OBJ_DIR)ft_lstadd_front.o \
			$(LIBFT_DIR)$(OBJ_DIR)ft_lstclear.o \
			$(LIBFT_DIR)$(OBJ_DIR)ft_lstdelone.o \
			$(LIBFT_DIR)$(OBJ_DIR)ft_lstiter.o \
			$(LIBFT_DIR)$(OBJ_DIR)ft_lstlast.o \
			$(LIBFT_DIR)$(OBJ_DIR)ft_lstmap.o \
			$(LIBFT_DIR)$(OBJ_DIR)ft_lstnew.o \
			$(LIBFT_DIR)$(OBJ_DIR)ft_lstsize.o \

#Rules

all : $(NAME)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c $(LIBFT) $(HEADER) Makefile
	$(CC) $(FLAGS) -c $< -o $@ -I $(HEADER)

$(NAME) : $(OBJ_DIR) $(OBJ)
	$(AR) $(NAME) $(OBJ) $(OBJ_LIBFT)

$(OBJ_DIR) :
	mkdir -p $(OBJ_DIR)

$(LIBFT) :
	make bonus -C $(LIBFT_DIR)
	cp $(LIBFT_DIR)/libft.a ./

clean :
	$(RM) -r $(OBJ_DIR) libft.a
	make fclean -C $(LIBFT_DIR)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : re fclean clean all