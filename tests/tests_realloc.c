/*
** tests_realloc.c for tests_realloc in /home/perso/work/projets/malloc_doc/PSU_2015_malloc/tests
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Mon Feb 08 18:34:58 2016 Bastien DHIVER
** Last update Tue Feb 09 21:34:22 2016 Bastien DHIVER
*/

#include "test_main.h"

void	tests_realloc(void)
{
  char	*tmp;
  int	a_int;

  ast(realloc(&a_int, 42) == NULL);
  tmp = realloc(NULL, 42);
  ast(tmp != NULL);
  ast(start_point == (t_block)((char *)tmp - META_SIZE));
  ast(end_point == ((t_block)((char *)tmp - META_SIZE))->next);
  ast(((t_block)tmp)->size = align_size(42));
  tmp = realloc(tmp, 20);
  ast(((t_block)((char *)tmp - META_SIZE))->size == align_size(42));
  tmp = realloc(tmp, 70);
  ast(((t_block)((char *)tmp - META_SIZE))->size == align_size(70));
  tmp = realloc(tmp, 4099);
  ast(((t_block)((char *)tmp - META_SIZE))->size == align_size(4099));
  tmp = realloc(tmp, 0);
  ast(start_point == NULL);
  ast(end_point == NULL);
}
