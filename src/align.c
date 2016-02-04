/*
** align.c for align in /home/perso/work/projets/malloc_doc/PSU_2015_malloc/src
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Thu Feb 04 10:28:32 2016 Bastien DHIVER
** Last update Thu Feb 04 10:54:59 2016 Bastien DHIVER
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
  int		page_size;

  page_size = getpagesize();
  if (size == 0)
    return (page_size);
  return ((size - 1) / page_size * page_size + page_size);
}
