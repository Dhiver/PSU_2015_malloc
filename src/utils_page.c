/*
** utils_page.c for utils_page in /home/perso/work/projets/malloc_doc/PSU_2015_malloc/src
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Mon Feb 01 17:15:46 2016 Bastien DHIVER
** Last update Mon Feb 01 17:26:47 2016 Bastien DHIVER
*/

#include "malloc.h"

size_t		get_nb_pages(void)
{
  t_block	tmp;
  size_t	i;
  size_t	j;

  tmp = start_point;
  i = 0;
  while (tmp)
    {
      j = ((size_t)tmp + tmp->size + META_SIZE) / getpagesize();
      if (j > i)
	i = j;
      tmp = tmp->next;
    }
  return (i);
}
