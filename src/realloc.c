/*
** realloc.c for realloc in /home/perso/work/projets/malloc_doc/PSU_2015_malloc/src
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Wed Jan 27 15:40:08 2016 Bastien DHIVER
** Last update Mon Feb 08 18:29:51 2016 Bastien DHIVER
*/

#include "malloc.h"

void		*realloc_merge(t_block ptr, size_t size)
{
  t_block	ptr_sav;

  ptr_sav = ptr;
  merge_block(&ptr);
  if (ptr->size >= size)
    copy_block(ptr_sav, ptr);
  else
    {
      free(ptr);
      return (malloc(size));
    }
  return (ptr->ptr);
}

void		*realloc(void *ptr, size_t size)
{
  t_block	tmp;

  if (!ptr)
    return (malloc(size));
  if (!check_addr(ptr))
    return (NULL);
  if ((tmp = get_block(ptr)) == NULL)
    return (NULL);
  return (realloc_merge(tmp, size));
}
