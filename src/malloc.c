/*
** malloc.c for malloc in /home/perso/work/projets/malloc_doc/PSU_2015_malloc/src
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Wed Jan 27 15:39:00 2016 Bastien DHIVER
** Last update Thu Feb 04 15:50:20 2016 Bastien DHIVER
*/

#include "malloc.h"

void		*start_point = NULL;
void		*end_point = NULL;

void		*malloc(size_t size)
{
  t_block	new;
  t_block	last;

  if (!start_point)
    {
      if (!(new = create_block(size)))
	return (NULL);
      split_block(new, size);
      start_point = new;
      end_point = new->next;
      new->free = 0;
      return (new->ptr);
    }
  if (!(new = find_block(&last, size)))
      if (!(new = create_block(size)))
	return (NULL);
  merge_block(new);
  split_block(new, size);
  new->free = 0;
  return (new->ptr);
}
