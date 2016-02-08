/*
** tests_free.c for tests_free in /home/perso/work/projets/malloc_doc/PSU_2015_malloc/tests
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Tue Feb 02 16:40:46 2016 Bastien DHIVER
** Last update Mon Feb 08 13:37:35 2016 Bastien DHIVER
*/

#include "test_main.h"

void    tests_free_again(char *tmp, char *tmp2, char *tmp3, void *old_break)
{
  old_break = sbrk(0);
  tmp = malloc(24);
  tmp2 = malloc(42);
  tmp3 = malloc(84);
  free(tmp3);
  free(tmp2);
  free(tmp);
  ast(start_point == NULL);
  ast(end_point == NULL);
  ast(sbrk(0) == old_break);
  tmp = malloc(8192);
  tmp2 = malloc(2);
  free(tmp);
  free(tmp2);
  ast(start_point == NULL);
  ast(end_point == NULL);
  ast(sbrk(0) == old_break);
}

void    tests_free()
{
  char	*tmp;
  char	*tmp2;
  char	*tmp3;
  void	*old_break;

  old_break = sbrk(0);
  tmp = malloc(42);
  free(tmp);
  ast(start_point == NULL);
  ast(end_point == NULL);
  ast(sbrk(0) == old_break);
  tmp2 = malloc(4096);
  tmp3 = malloc(28);
  free(tmp3);
  ast(start_point == (t_block)((char *)tmp2 - META_SIZE));
  ast(end_point == ((t_block)((char *)tmp2 - META_SIZE))->next);
  ast(((t_block)((char *)tmp2 - META_SIZE))->next->next == NULL);
  ast(((t_block)start_point)->prev == NULL);
  ast(((t_block)((char *)tmp2 - META_SIZE))->next->free == 1);
  free(tmp2);
  ast(start_point == NULL);
  ast(end_point == NULL);
  tests_free_again(tmp, tmp2, tmp3, old_break);
}
