/*
** tests_malloc.c for tests_malloc in /home/perso/work/projets/malloc_doc/PSU_2015_malloc/tests
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Wed Feb 03 14:23:22 2016 Bastien DHIVER
** Last update Thu Feb 04 13:46:34 2016 Bastien DHIVER
*/

#include <string.h>
#include "test_main.h"

void		tests_malloc_again(char *tmp, char *tmp2)
{
  ast(((t_block)((char *)tmp2 - META_SIZE))->next == NULL);
  ast(((t_block)((char *)tmp2 - META_SIZE))->free == 0);
  ast(start_point == (char *)tmp - META_SIZE);
  ast((char *)start_point + META_SIZE == tmp);
  ast((char *)start_point + META_SIZE ==
	 ((t_block)((char *)tmp - META_SIZE))->ptr);
  ast((char *)start_point + META_SIZE + 7 ==
	 (char *)tmp + ((t_block)((char *)tmp - META_SIZE))->size);
  /*ast((char *)start_point + META_SIZE + 7 + 1 == (char *)tmp2 - META_SIZE);*/
}

void		tests_malloc(void)
{
  char		*tmp;
  char		*tmp2;

  tmp = malloc(7);
  tmp[0] = 'z';
  tmp[1] = 'o';
  tmp[2] = 'm';
  tmp[3] = 'b';
  tmp[4] = 'i';
  tmp[5] = 'e';
  tmp[6] = '\0';
  ast(strcmp(tmp, "zombie") == 0);
  ast(start_point == tmp - META_SIZE);
  ast(end_point == tmp - META_SIZE);
  ast(((t_block)((char *)tmp - META_SIZE))->next == NULL);
  ast(((t_block)((char *)tmp - META_SIZE))->prev == NULL);
  tmp2 = malloc(42);
  ast(start_point == tmp - META_SIZE);
  ast(end_point == tmp2 - META_SIZE);
  ast(((t_block)((char *)tmp2 - META_SIZE))->prev ==
	 (t_block)((char *)tmp - META_SIZE));
  ast(((t_block)((char *)tmp - META_SIZE))->next ==
	 (t_block)((char *)tmp2 - META_SIZE));
  tests_malloc_again(tmp, tmp2);
}
