##
## Makefile for tests in /home/perso/work/projets/malloc_doc/PSU_2015_malloc/tests
## 
## Made by Bastien DHIVER
## Login   <dhiver_b@epitech.net>
## 
## Started on  Tue Feb 02 15:45:14 2016 Bastien DHIVER
## Last update Sun Feb 14 19:57:15 2016 Bastien DHIVER
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
	  $(SRCF)tests_check_addr.c		\
	  $(SRCF)tests_create_block.c		\
	  $(SRCF)tests_find_block.c		\
	  $(SRCF)tests_split_block.c		\
	  $(SRCF)tests_malloc.c			\
	  $(SRCF)tests_free.c			\
	  $(SRCF)tests_merge_block.c		\
	  $(SRCF)tests_align_size.c		\
	  $(SRCF)tests_align_page.c		\
	  $(SRCF)my_assert.c			\
	  $(SRCF)tests_get_nb_page.c		\
	  $(SRCF)tests_realloc.c		\
	  $(SRCF)tests_calloc.c

OBJS	= $(SRCS:.c=.o)


$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(SLIB)

all: $(NAME)

tests: $(NAME)
	@echo
	@echo
	LD_LIBRARY_PATH=. LD_PRELOAD=$(CURDIR)/../libmy_malloc.so ./$(NAME)
	@make fclean > /dev/null $(NOWHERE)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

