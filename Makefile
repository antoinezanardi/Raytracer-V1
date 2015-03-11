##
## Makefile for make in /home/zanard_a/rendu/Projets Piscines/expr
##
## Made by Antoine Zanardi
## Login   <zanard_a@epitech.net>
##
## Started on  Tue Oct 21 16:47:57 2014 Antoine Zanardi
## Last update Mon Mar  9 10:42:44 2015 Antoine Zanardi
##

DEBUG	=	no

ifeq ($(DEBUG), yes)
CFLAGS	+=	-g -Wall -Wextra
endif

ifeq ($(CC), clang)
CFLAGS	=	-Weverything -Wno-padded
endif

LIB_PA	=	./lib/my/

NAME	=	rtv1

SRC_PA	=	./srcs/

SRCS	=	$(SRC_PA)main.c \
		$(SRC_PA)error.c \
		$(SRC_PA)parsing.c \
		$(SRC_PA)parse_line.c \
		$(SRC_PA)fc.c \
		$(SRC_PA)param_to_list.c \
		$(SRC_PA)v_to_elem.c \
		$(SRC_PA)treat.c \
		$(SRC_PA)treat_form.c \
		$(SRC_PA)treat_k.c \
		$(SRC_PA)translation.c \
		$(SRC_PA)picture.c \
		$(SRC_PA)light.c \
		$(SRC_PA)normal.c \
		$(SRC_PA)view.c \
		$(SRC_PA)get_double.c \
		$(SRC_PA)brillance.c \
		$(SRC_PA)shadow.c \

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
