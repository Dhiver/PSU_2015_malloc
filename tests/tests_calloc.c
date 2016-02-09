/*
** tests_calloc.c for tests_calloc in /home/perso/work/projets/malloc_doc/PSU_2015_malloc/tests
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Mon Feb 08 17:53:17 2016 Bastien DHIVER
** Last update Tue Feb 09 12:48:21 2016 Bastien DHIVER
*/

#include "test_main.h"

void	tests_calloc(void)
{
  char	*tmp;
  int	i;

  tmp = calloc(25, sizeof(int));
  i = 0;
  while (++i < 25 * (int)sizeof(int))
    ast(tmp[i] == '\0');
}
