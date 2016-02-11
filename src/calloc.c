/*
** calloc.c for calloc in /home/perso/work/projets/malloc_doc/PSU_2015_malloc/src
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Mon Feb 08 16:57:08 2016 Bastien DHIVER
** Last update Wed Feb 10 16:41:12 2016 Bastien DHIVER
*/

#include <string.h>
#include "malloc.h"

void		*calloc_func(size_t nelem, size_t elsize)
{
  void		*p;
  size_t	mul;

  mul = nelem * elsize;
  if ((p = malloc_func(mul)))
    memset(p, '\0', mul);
  return (p);
}

void		*calloc(size_t nelem, size_t elsize)
{
  void		*back;

  pthread_mutex_lock(&lock);
  back = calloc_func(nelem, elsize);
  pthread_mutex_unlock(&lock);
  return (back);
}
