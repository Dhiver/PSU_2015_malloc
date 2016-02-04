/*
** free.c for free in /home/perso/work/projets/malloc_doc/PSU_2015_malloc/src
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Wed Jan 27 15:39:37 2016 Bastien DHIVER
** Last update Thu Feb 04 17:05:02 2016 Bastien DHIVER
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
  show_alloc_mem_all();
  merge_block(tmp->next);
  show_alloc_mem_all();
  if (tmp == ((t_block)end_point)->prev && ((t_block)end_point)->free)
  {
    printf("toto\n");
    nb_page  = get_nb_page(tmp) + 1;
    printf("get_nb_page = %ld\n", nb_page);
    printf("tmp->size = %ld\n", tmp->size);
    if (nb_page * getpagesize() - META_SIZE == tmp->size)
    {
      printf("toto 2\n");
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
