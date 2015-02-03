##
## Makefile for make in /home/zanard_a/rendu/Projets Piscines/expr
##
## Made by Antoine Zanardi
## Login   <zanard_a@epitech.net>
##
## Started on  Tue Oct 21 16:47:57 2014 Antoine Zanardi
## Last update Tue Feb  3 18:08:50 2015 Antoine Zanardi
##

DEBUG	=	no

ifeq ($(DEBUG), yes)
CFLAGS	+=	-g -Wall -Wextra
endif

LIB_PA	=	./lib/my/

NAME	=	rtv1

SRCS	=	main.c \
		error.c \
		parsing.c \
		parse_line.c \
		fc.c \
		param_to_list.c \
		v_to_elem.c \

SRCS_LI	=	$(LIB_PA)my_getnbr.c \
		$(LIB_PA)my_putchar.c \
		$(LIB_PA)my_put_nbr.c \
		$(LIB_PA)my_putstr.c \
		$(LIB_PA)my_strlen.c \

OBJS	=	$(SRCS:.c=.o)

OBJS_LI	=	$(SRCS_LI:.c=.o)

INC	=	-I include/ \
		-I minilibX/ \

LIB_CMP	=	$(LIB_PA)libmy.a

CFLAGS	+=	$(INC)

MLX	=	minilibx/libmlx_x86_64.a \
		-L/usr/lib64/X11 -lXext -lX11 \
		-lm

all: $(LIB_CMP) $(NAME)

$(LIB_CMP): $(OBJS_LI)
	ar rc $(LIB_CMP) $(OBJS_LI)
	ranlib $(LIB_CMP)
	cp $(LIB_PA)my.h ./include/

$(NAME): $(OBJS)
	cc -Wall $(OBJS) lib/my/libmy.a $(MLX) $(INC) -o $(NAME)

clean:
	rm -f $(OBJS)
	rm -f $(OBJS_LI)

fclean: clean
	rm -f $(NAME)
	rm -f $(LIB_CMP)

re: fclean all

.PHONY: all clean fclean all
