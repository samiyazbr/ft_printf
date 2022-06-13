NAME = libftprintf.a
SRCS = ft_printdec.c ft_printhexup.c ft_printunint.c \
ft_printf.c ft_putchar.c \
ft_printhexlow.c ft_printpointer.c ft_putstr.c

OBJS := $(SRCS:%.c=%.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJS)
	ar -rc $@ $^
clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : re clean fclean all