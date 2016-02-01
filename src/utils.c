/*
** utils.c for utils in /home/perso/work/projets/malloc_doc/PSU_2015_malloc/src
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Mon Feb 01 11:59:58 2016 Bastien DHIVER
** Last update Mon Feb 01 15:26:42 2016 Bastien DHIVER
*/

#include "malloc.h"

size_t		get_memory_size(size_t size)
{
  int		page_size;

  page_size = getpagesize();
  if (size % page_size == 0)
    return (page_size * (size / page_size));
  else
    return (page_size * ((size / page_size) + 1));
}

t_block		get_block(void *ptr)
{
  char		*tmp;

  tmp = ptr;
  return (ptr = tmp -= META_SIZE);
}

bool		check_addr(void *ptr)
{
  if (!start_point || !ptr || !(ptr > start_point && ptr < sbrk(0)))
    return (FALSE);
  else if (ptr == (get_block(ptr))->ptr)
    return (TRUE);
  else
    return (FALSE);
}

void		set_next_and_prev(t_block tmp)
{
  if (!tmp->prev)
    tmp->prev->next = tmp->next;
  if (!tmp->next)
    tmp->next->prev = tmp->prev;
}
