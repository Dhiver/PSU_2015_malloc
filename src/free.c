/*
** free.c for free in /home/perso/work/projets/malloc_doc/PSU_2015_malloc/src
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Wed Jan 27 15:39:37 2016 Bastien DHIVER
** Last update Mon Feb 01 23:21:04 2016 Bastien DHIVER
*/

#include "malloc.h"

void		free(void *ptr)
{
  t_block	tmp;
  size_t    nb_page;

  if (!ptr || !check_addr(ptr))
    return ;
  if (!(tmp = get_block(ptr)) && tmp->free)
    return ;
  tmp->free = 1;
  merge_block(tmp);
  if (tmp == end_point)
  {
    nb_page  = get_nb_page(tmp);
    if (nb_page * getpagesize() == tmp->size)
    {
        if (tmp->prev)
            end_point = tmp->prev;
        else
        {
            end_point = NULL;
            brk(start_point);
            start_point = NULL;
            return ;
        }
    }
    brk((char*)start_point + (nb_page * getpagesize()));
  }
}
