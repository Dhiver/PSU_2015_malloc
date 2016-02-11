/*
** realloc.c for realloc in /home/perso/work/projets/malloc_doc/PSU_2015_malloc/src
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Wed Jan 27 15:40:08 2016 Bastien DHIVER
** Last update Wed Feb 10 16:41:31 2016 Bastien DHIVER
*/

#include "malloc.h"

void		*realloc_merge(t_block ptr, size_t size)
{
  t_block	ptr_sav;
  void		*tmp;

  ptr_sav = ptr;
  merge_block(&ptr);
  if (ptr->size < size)
    {
      tmp = malloc_func(size);
      copy_data(ptr_sav, (t_block)((char *)tmp - META_SIZE));
      free_func(ptr->ptr);
      return (tmp);
    }
  else
    {
      split_block(ptr, size);
      copy_data(ptr_sav, ptr);
      return (ptr->ptr);
    }
}

void		*realloc_func(void *ptr, size_t size)
{
  t_block	tmp;
  void		*back;

  if (!ptr)
    {
      back = malloc_func(size);
      return (back);
    }
  if (!size)
    {
      free_func(ptr);
      return (NULL);
    }
  if (!check_addr(ptr))
    return (NULL);
  if ((tmp = get_block(ptr)) == NULL)
    return (NULL);
  return (realloc_merge(tmp, size));
}

void		*realloc(void *ptr, size_t size)
{
  void		*back;

  pthread_mutex_lock(&lock);
  back = realloc_func(ptr, size);
  pthread_mutex_unlock(&lock);
  return (back);
}
