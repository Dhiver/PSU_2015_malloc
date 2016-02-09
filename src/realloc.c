/*
** realloc.c for realloc in /home/perso/work/projets/malloc_doc/PSU_2015_malloc/src
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Wed Jan 27 15:40:08 2016 Bastien DHIVER
** Last update Tue Feb 09 21:40:36 2016 Bastien DHIVER
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
      tmp = malloc(size);
      copy_data(ptr_sav, (t_block)((char *)tmp - META_SIZE));
      free(ptr->ptr);
      /*printf("realloc(%p, %ld) return %p is %d\n", (char *)ptr + META_SIZE, size, tmp, ((char *)tmp)[0]);*/
      /*show_alloc_mem_all();*/
      return (tmp);
    }
  else
    {
      split_block(ptr, size);
      copy_data(ptr_sav, ptr);
      /*printf("realloc(%p, %ld) return %p is %d\n", (char *)ptr + META_SIZE, size, ptr->ptr, ((char *)ptr->ptr)[0]);*/
      /*show_alloc_mem_all();*/
      return (ptr->ptr);
    }
}

void		*realloc(void *ptr, size_t size)
{
  t_block	tmp;

  /*printf("realloc(%p, %ld)\n", ptr, size);*/
  if (!ptr)
    return (malloc(size));
  if (!size)
    {
      free(ptr);
      return (NULL);
    }
  if (!check_addr(ptr))
    {
      /*printf("realloc does nothing\n");*/
      return (NULL);
    }
  if ((tmp = get_block(ptr)) == NULL)
    {
      /*printf("realloc does nothing\n");*/
      return (NULL);
    }
  return (realloc_merge(tmp, size));
}
