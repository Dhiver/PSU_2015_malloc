/*
** utils.c for utils in /home/perso/work/projets/malloc_doc/PSU_2015_malloc/src
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Mon Feb 01 11:59:58 2016 Bastien DHIVER
** Last update Tue Feb 09 09:13:05 2016 Bastien DHIVER
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

void		copy_data(t_block old_blk, t_block new_blk)
{
  size_t	i;

  if (new_blk->size < old_blk->size)
    return ;
  i = META_SIZE;
  while (i < old_blk->size)
    {
      new_blk[i] = old_blk[i];
      i++;
    }
}
