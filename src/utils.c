/*
** utils.c for utils in /home/perso/work/projets/malloc_doc/PSU_2015_malloc/src
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Mon Feb 01 11:59:58 2016 Bastien DHIVER
** Last update Thu Feb 04 16:51:34 2016 Bastien DHIVER
*/

#include "malloc.h"


t_block		get_block(void *ptr)
{
  return ((t_block)((char*)ptr - META_SIZE));
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

void		free_memory(void)
{
  t_block	tmp;
  size_t	page_size;

  page_size = getpagesize();
  tmp = end_point;
  if (tmp->size >= page_size)
    {
      if (tmp->size == page_size)
	  if ((size_t)tmp / page_size ==
	      ((size_t)tmp + tmp->size + META_SIZE) / page_size)
	    {
	      end_point = tmp->prev;
	      brk(tmp);
	      return ;
	    }
    }
}
