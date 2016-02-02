##
## Makefile for tests in /home/perso/work/projets/malloc_doc/PSU_2015_malloc/tests
## 
## Made by Bastien DHIVER
## Login   <dhiver_b@epitech.net>
## 
## Started on  Tue Feb 02 15:45:14 2016 Bastien DHIVER
## Last update Tue Feb 02 16:14:51 2016 Bastien DHIVER
##

CC	= gcc

RM	= rm -f

CFLAGS	+= -W -Wall -Wextra -pedantic
CFLAGS	+= -Werror
CFLAGS	+= -I../include/ -I.

SLIB	= ../libmy_malloc.so

NAME	= run_for_tests

NOWHERE	= /dev/null

SRCS	= $(SRCF)test_main.c			\
	  $(SRCF)tests_get_memory_size.c	\

OBJS	= $(SRCS:.c=.o)


$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(SLIB)

all: $(NAME)

tests: $(NAME)
	LD_LIBRARY_PATH=. LD_PRELOAD=$(CURDIR)/../libmy_malloc.so ./$(NAME)
	@make fclean > /dev/null $(NOWHERE)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
