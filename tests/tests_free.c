/*
** tests_free.c for tests_free in /home/perso/work/projets/malloc_doc/PSU_2015_malloc/tests
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Tue Feb 02 16:40:46 2016 Bastien DHIVER
** Last update Thu Feb 04 13:46:25 2016 Bastien DHIVER
*/

#include "test_main.h"

void    tests_free()
{
  char	*tmp;
  char	*tmp3;

  tmp = malloc(42);
  free(tmp);
  ast(start_point == NULL);
  ast(end_point == NULL);
  tmp = malloc(4097);
  ast(start_point == (t_block)((char *)tmp - META_SIZE));
  tmp3 = malloc(4000);
  free(tmp3);
}
