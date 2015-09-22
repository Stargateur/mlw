##
## Makefile for Makefile in /home/plasko_a/projet/epitech/mlw
## 
## Made by Antoine Plaskowski
## Login   <plasko_a@epitech.eu>
## 
## Started on  Tue Sep 22 23:29:00 2015 Antoine Plaskowski
## Last update Tue Sep 22 23:35:06 2015 Antoine Plaskowski
##

NAME		=	libmlw.a

CC		?=	gcc

AR		=	ar

RM		=	rm

DEBUG		?=	no

RANLIB		=	ranlib

LEVEL		?=	3

COLOR		?=	no

LIB		=

INCLUDE		=	-I include

CFLAGS		+=	-Wall -Wextra -O$(LEVEL)
CFLAGS		+=	-pedantic
CFLAGS		+=	$(INCLUDE)
#CFLAGS          +=      -D _POSIX_SOURCE -D _GNU_SOURCE -D _XOPEN_SOURCE

ifeq ($(CC), clang)
CFLAGS		+=	-Weverything -Wno-padded -Wno-disabled-macro-expansion
endif

ifneq ($(DEBUG), no)
CFLAGS		+=	-g
endif

ifneq ($(COLOR), no)
CFLAGS		+=	-fdiagnostics-color
endif

LDFLAGS		=	$(LIB)

ifeq ($(DEBUG), no)
LDFLAGS		+=	-s
endif

include			source.mk

DPD		=	$(SRC:.c=.dpd)

OBJ		=	$(SRC:.c=.o)

all		:	$(NAME)

$(NAME)		:	$(OBJ)
			$(AR) rc $(NAME) $(OBJ)
			$(RANLIB) $(NAME)

clean		:
			$(RM) -f $(OBJ)
			$(RM) -f $(DPD)

fclean		:	clean
			$(RM) -f $(NAME)

re		:	fclean
			$(MAKE) -C . all

%.dpd		:	%.c
			$(CC) -MM $(<) -o $(@) $(CFLAGS) -MT $(<:.c=.o)

%.o		:	%.c
			$(CC) -c $(<) -o $(@) $(CFLAGS)

.PHONY		:	all clean fclean re %.dpd %.o

.SUFFIXES	:	.o.c .dpd.c

include			$(DPD)
