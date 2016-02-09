/*
** align.c for align in /home/perso/work/projets/malloc_doc/PSU_2015_malloc/src
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Thu Feb 04 10:28:32 2016 Bastien DHIVER
** Last update Tue Feb 09 09:34:09 2016 Bastien DHIVER
*/

#include "malloc.h"

size_t		align_size(size_t size)
{
  if (size == 0)
    return (sizeof(void *));
  return ((size - 1) / sizeof(void *) * sizeof(void *) + sizeof(void *));
}

size_t		align_page(size_t size)
{
  if (size == 0)
    return (PAGE_SIZE);
  return ((size - 1) / PAGE_SIZE * PAGE_SIZE + PAGE_SIZE);
}
