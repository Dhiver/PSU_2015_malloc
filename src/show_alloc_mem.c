/*
** show_alloc_mem.c for show_alloc_mem in /home/perso/work/projets/malloc_doc/PSU_2015_malloc/src
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Wed Jan 27 15:48:04 2016 Bastien DHIVER
** Last update Thu Feb 04 14:12:01 2016 Bastien DHIVER
*/

#include "malloc.h"

void		show_alloc_mem(void)
{
  t_block	tmp;

  tmp = sbrk(0);
  printf("break : %p\n", (void *)tmp);
  tmp = start_point;
  while (tmp)
    {
      if (tmp->free == 0)
	{
	  printf("%p - %p : ", tmp->ptr, (char *)tmp->ptr + tmp->size);
	  printf("%ld bytes\n", tmp->size);
	}
      tmp = tmp->next;
    }
}

void		show_alloc_mem_free(void)
{
  t_block	tmp;

  tmp = sbrk(0);
  printf("break : %p\n", (void *)tmp);
  tmp = start_point;
  while (tmp)
    {
      if (tmp->free == 1)
	{
	  printf("%p - %p : ", tmp->ptr, (char *)tmp->ptr + tmp->size);
	  printf("%ld bytes\n", tmp->size);
	}
      tmp = tmp->next;
    }
}
