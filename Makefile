##
## Makefile for malloc in /home/perso/work/projets/malloc_doc/PSU_2015_malloc
## 
## Made by Bastien DHIVER
## Login   <dhiver_b@epitech.net>
## 
## Started on  Wed Jan 27 15:24:21 2016 Bastien DHIVER
## Last update Sun Feb 14 19:57:04 2016 Bastien DHIVER
##

CC	= gcc

RM	= rm -f

CFLAGS	+= -W -Wall -Wextra -pedantic
CFLAGS	+= -Werror
CFLAGS	+= -fPIC
CFLAGS	+= -I./include/
CFLAGS  += -lpthread

LDFLAGS	= -shared

SRCF	= src/

NAME	= libmy_malloc.so

SRCS	= $(SRCF)malloc.c		\
	  $(SRCF)free.c			\
	  $(SRCF)realloc.c		\
	  $(SRCF)calloc.c		\
	  $(SRCF)show_alloc_mem.c	\
	  $(SRCF)align.c		\
	  $(SRCF)utils.c           	\
	  $(SRCF)utils_block.c
      
OBJS	= $(SRCS:.c=.o)


$(NAME): $(OBJS)
	$(CC) $(LDFLAGS) -o $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

