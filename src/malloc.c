/*
** malloc.c for malloc in /home/perso/work/projets/malloc_doc/PSU_2015_malloc/src
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Wed Jan 27 15:39:00 2016 Bastien DHIVER
** Last update Tue Feb 09 21:40:56 2016 Bastien DHIVER
*/

#include "malloc.h"

void		*start_point = NULL;
void		*end_point = NULL;

void		*malloc(size_t size)
{
  t_block	new;
  t_block	last;

  /*printf("malloc(%ld)\n", size);*/
  if (!start_point)
    {
      if (!(new = create_block(size)))
	{
	  /*printf("malloc(%ld) return %p\n", size, NULL);*/
	  /*show_alloc_mem_all();*/
	  return (NULL);
	}
      split_block(new, size);
      start_point = new;
      end_point = new->next;
      new->free = 0;
      /*printf("malloc(%ld) return %p\n", size, new->ptr);*/
      /*show_alloc_mem_all();*/
      return (new->ptr);
    }
  if (!(new = find_block(&last, size)))
    if (!(new = create_block(size)))
      {
	/*printf("malloc(%ld) return %p\n", size, NULL);*/
	/*show_alloc_mem_all();*/
	return (NULL);
      }
  split_block(new, size);
  new->free = 0;
  /*printf("malloc(%ld) return %p is %d size\n", size, new->ptr, ((char *)new->ptr)[0]);*/
  /*printf("malloc(%ld) return %p\n", size, new->ptr);*/
  /*show_alloc_mem_all();*/
  return (new->ptr);
}
