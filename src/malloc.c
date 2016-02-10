/*
** malloc.c for malloc in /home/perso/work/projets/malloc_doc/PSU_2015_malloc/src
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Wed Jan 27 15:39:00 2016 Bastien DHIVER
** Last update Wed Feb 10 13:43:05 2016 Jarry Maxime
*/

#include "malloc.h"

void		*start_point = NULL;
void		*end_point = NULL;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void		*malloc_func(size_t size)
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
  split_block(new, size);
  new->free = 0;
  return (new->ptr);
}

void		*malloc(size_t size)
{
  void		*back;

  pthread_mutex_lock(&lock);
  back = malloc_func(size);
  pthread_mutex_unlock(&lock);
  return (back);
}
