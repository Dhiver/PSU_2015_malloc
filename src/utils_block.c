/*
** utils_block.c for utils_block in /home/perso/work/projets/malloc_doc/PSU_2015_malloc/src
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Mon Feb 01 13:37:17 2016 Bastien DHIVER
** Last update Wed Feb 03 13:50:23 2016 Bastien DHIVER
*/

#include "malloc.h"

t_block			create_block(size_t size)
{
  t_block		out;

  out = sbrk(0);
  if (sbrk(get_memory_size(size + META_SIZE)) == (void *)-1)
    return (NULL);
  out->size = size;
  out->free = 1;
  out->ptr = (char *)out + META_SIZE;
  out->prev = end_point;
  out->next = NULL;
  end_point = out;
  return (out);
}

t_block		find_block(t_block *ptr, size_t size)
{
  t_block	tmp;

  tmp = start_point;
  if (ptr)
    *ptr = NULL;
  while (tmp && !(tmp->free && tmp->size >= size))
    {
      if (ptr && tmp)
	*ptr = tmp;
      tmp = tmp->next;
    }
  return (tmp);
}

void			merge_block(t_block blk)
{
  t_block		tmp;

  tmp = start_point;
  while (tmp && tmp->next)
    {
      if ((t_block)tmp->ptr + tmp->size == blk - META_SIZE && tmp->free)
	{
	  blk->ptr = tmp->ptr;
	  blk->size += tmp->size + META_SIZE;
	  set_next_and_prev(tmp);
	}
      else if ((t_block)tmp->ptr - META_SIZE ==
	       (t_block)blk->ptr + blk->size && tmp->free)
	{
	  blk->size += tmp->size + META_SIZE;
	  set_next_and_prev(tmp);
	}
      tmp = tmp->next;
    }
}

void			copy_block(t_block old_blk, t_block new_blk)
{
  size_t		i;

  if (new_blk->size < old_blk->size)
    return ;
  i = 0;
  while (i < old_blk->size)
    {
      new_blk[i] = old_blk[i];
      i++;
    }
}

bool		split_block(t_block blk, size_t size)
{
  t_block	new;

  if (!blk || size > blk->size + META_SIZE || (int)(blk->size - size) < (int)META_SIZE)
    return (FALSE);
  new = (t_block)((char *)blk + META_SIZE + size);
  new->size = blk->size - META_SIZE - size;
  blk->size = size;
  new->free = 1;
  new->ptr = (t_block)((char *)new + META_SIZE);
  if (blk->next)
    {
      blk->next->prev = new;
      new->next = blk->next;
    }
  else
    new->next = NULL;
  new->prev = blk;
  blk->next = new;
  if (blk == end_point)
    end_point = new;
  return (TRUE);
}

