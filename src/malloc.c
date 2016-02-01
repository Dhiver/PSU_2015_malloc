/*
** malloc.c for malloc in /home/perso/work/projets/malloc_doc/PSU_2015_malloc/src
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Wed Jan 27 15:39:00 2016 Bastien DHIVER
** Last update Mon Feb 01 16:06:26 2016 Bastien DHIVER
*/

#include "malloc.h"

void		*start_point = NULL;
void		*end_point = NULL;

void		*malloc(size_t size)
{
  t_block	new;
  t_block	last;

  printf("Notre malloc, META_SIZE = %ld\n", META_SIZE);
  if (!start_point)
    {
      if (!(new = create_block(size)))
	return (NULL);
      split_block(new, size);
      start_point = new;
      new->free = 0;
      return (new->ptr);
    }
  last = end_point;
  if (!(new = find_block(&last, size)))
    if (!(new = create_block(size)))
      return (NULL);
  split_block(new, size);
  end_point = new;
  new->free = 0;
  return (new->ptr);
}
