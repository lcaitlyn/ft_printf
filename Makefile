NAME	=	libftprintf.a

LIST	=	ft_printf.c ft_strlen.c ft_toupper.c\
		ft_putchar.c ft_putstr.c ft_putnbr.c\
		ft_bzero.c ft_calloc.c ft_strlcpy.c\
		ft_itoa.c rev_print.c ft_hexadecimal.c\
		ft_unsigned_int.c ft_strchr.c ft_put_char.c

OBJ	=	$(LIST:%.c=%.o)

HEADER	=	ft_printf.h

FLAGS	=	-Wall -Wextra -Werror

.PHONY	:	all clean clean re bonus

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		ar rcs $(NAME) $?

%.o	:	%.c $(HEADER)
		gcc $(FLAGS) -c $< -o $@

clean	:
		@rm -f $(OBJ) $(OBJ_B)

fclean	:	clean
		@rm -f $(NAME)

re	:	fclean all
