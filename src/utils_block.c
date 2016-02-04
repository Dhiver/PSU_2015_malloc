/*
** utils_block.c for utils_block in /home/perso/work/projets/malloc_doc/PSU_2015_malloc/src
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Mon Feb 01 13:37:17 2016 Bastien DHIVER
** Last update Thu Feb 04 17:24:00 2016 Bastien DHIVER
*/

#include "malloc.h"

t_block			create_block(size_t size)
{
  t_block		out;
  size_t		new_size;

  out = sbrk(0);
  new_size = align_page(align_size(size) + META_SIZE);
  if (sbrk(new_size) == (void *)-1)
    return (NULL);
  out->size = new_size - META_SIZE;
  out->free = 1;
  out->ptr = (char *)out + META_SIZE;
  out->prev = end_point;
  if (end_point)
    ((t_block)end_point)->next = out;
  out->next = NULL;
  end_point = out;
  return (out);
}

t_block		find_block(t_block *ptr, size_t size)
{
  t_block	tmp;

  size = align_size(size);
  tmp = start_point;
  if (ptr)
    *ptr = NULL;
  while (tmp && !(tmp->free && tmp->size >= size))
    {
      if (tmp)
	*ptr = tmp;
      tmp = tmp->next;
    }
  return (tmp);
}

void			merge_block(t_block blk)
{
  t_block		tmp;

  tmp = start_point;
  while (tmp)
    {
      if ((t_block)((char *)blk + blk->size + META_SIZE) ==
	  tmp && tmp->free)
	{
	  blk->next = tmp->next;
	  if (!blk->next)
	    end_point = blk;
	  if (tmp->next)
	    tmp->next->prev = blk;
	  blk->size += tmp->size + META_SIZE;
	}
      else if (tmp->free && blk ==
	       (t_block)((char *)tmp + tmp->size + META_SIZE))
	{
	  tmp->next = blk->next;
	  if (!tmp->next)
	    end_point = tmp;
	  if (blk->next)
	    blk->next->prev = tmp;
	  tmp->size += blk->size + META_SIZE;
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
  size_t	splited_blk_size;

  size = align_size(size);
  splited_blk_size = size + META_SIZE;
  if (!blk || blk->size < splited_blk_size)
    return (FALSE);
  new = (t_block)((char *)blk + splited_blk_size);
  new->size = blk->size - splited_blk_size;
  new->free = 1;
  new->ptr = (char *)new + META_SIZE;
  new->prev = blk;
  if (blk->next)
    {
      blk->next->prev = new;
      new->next = blk->next;
    }
  else
    new->next = NULL;
  blk->size = size;
  blk->next = new;
  if (blk == end_point)
    end_point = new;
  return (TRUE);
}
