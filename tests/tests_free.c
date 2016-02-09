/*
** tests_free.c for tests_free in /home/perso/work/projets/malloc_doc/PSU_2015_malloc/tests
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Tue Feb 02 16:40:46 2016 Bastien DHIVER
** Last update Tue Feb 09 21:30:44 2016 Bastien DHIVER
*/

#include "test_main.h"

void	tests_free_forever(void)
{
  char	*tmp;
  char	*tmp2;
  char	*tmp3;
  char	*tmp4;

  start_point = NULL;
  end_point = NULL;
  tmp = malloc(568);
  tmp2 = malloc(1600);
  tmp3 = malloc(1024);
  tmp4 = malloc(2048);
  free(tmp3);
  free(tmp);
  ast(start_point == (t_block)((char *)tmp - META_SIZE));
  ast(((t_block)start_point)->size == align_size(568));
  ast(((t_block)start_point)->free == 1);
  ast(((t_block)start_point)->prev == NULL);
  ast(((t_block)start_point)->next == (t_block)((char *)tmp2 - META_SIZE));
  (void)tmp4;
}

void    tests_free_again2(char *tmp, char *tmp2)
{
  int	i;

  start_point = NULL;
  end_point = NULL;
  tmp = malloc(568);
  tmp2 = malloc(42);
  free(tmp2);
  tmp2 = malloc(1457664);
  free(tmp2);
  tmp2 = malloc(5242880);
  free(tmp2);
  ast(((t_block)tmp2-META_SIZE)->size < 4096);
  tmp2 = malloc(2);
  i = 1;
  while (i <= 1024)
    {
      tmp2 = malloc(i);
      i *= 2;
    }
  tmp2 = malloc(12288);
  (void)tmp;
  tests_free_forever();
}

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
  tests_free_again2(tmp, tmp2);
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
