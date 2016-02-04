/*
** free.c for free in /home/perso/work/projets/malloc_doc/PSU_2015_malloc/src
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Wed Jan 27 15:39:37 2016 Bastien DHIVER
** Last update Thu Feb 04 18:10:17 2016 Bastien DHIVER
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
  printf("end_point = %p\n", end_point);
  printf("tmp = %p\n", (void *)tmp);
  if (tmp == end_point && tmp->free)
  {
    nb_page  = get_nb_page(tmp) + 1;
    if (nb_page * getpagesize() - META_SIZE == tmp->size)
    {
      printf("toto 1\n");
        if (tmp->prev)
            end_point = tmp->prev;
        else
        {
            end_point = NULL;
	    printf("toto\n");
            brk(start_point);
            start_point = NULL;
            return ;
        }
    }
    brk((char*)start_point + (nb_page * getpagesize()));
  }
}
