/*
** free.c for free in /home/perso/work/projets/malloc_doc/PSU_2015_malloc/src
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Wed Jan 27 15:39:37 2016 Bastien DHIVER
** Last update Tue Feb 09 11:14:32 2016 Bastien DHIVER
*/

#include "malloc.h"

bool		free_at_page_end(t_block tmp)
{
  size_t	nb_page;

  nb_page  = get_nb_page(tmp) + 1;
  if (nb_page * PAGE_SIZE - META_SIZE == tmp->size)
    {
      if (tmp->prev)
	end_point = tmp->prev;
      else
	{
	  end_point = NULL;
	  brk(start_point);
	  start_point = NULL;
	  return (TRUE);
	}
    }
  brk((char*)start_point + (nb_page * PAGE_SIZE));
  tmp->size -= ((tmp->size / PAGE_SIZE) * PAGE_SIZE);
  return (FALSE);
}

void		free(void *ptr)
{
  t_block	tmp;

  if (!ptr || !check_addr(ptr))
    return ;
  if (!(tmp = get_block(ptr)) && tmp->free)
    return ;
  tmp->free = 1;
  merge_block(&tmp);
  if (tmp == end_point && tmp->free)
    if (free_at_page_end(tmp))
      return ;
  if (start_point == end_point && ((t_block)end_point)->free)
    {
      brk(start_point);
      start_point = NULL;
      end_point = NULL;
    }
}
