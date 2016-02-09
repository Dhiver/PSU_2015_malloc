/*
** calloc.c for calloc in /home/perso/work/projets/malloc_doc/PSU_2015_malloc/src
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Mon Feb 08 16:57:08 2016 Bastien DHIVER
** Last update Tue Feb 09 21:41:33 2016 Bastien DHIVER
*/

#include <string.h>
#include "malloc.h"

void		*calloc(size_t nelem, size_t elsize)
{
  void		*p;
  size_t	mul;

  /*printf("calloc(%ld, %ld)\n", nelem, elsize);*/
  mul = nelem * elsize;
  if ((p = malloc(mul)))
    memset(p, '\0', mul);
  /*printf("calloc(%ld, %ld) return %p\n", nelem, elsize, p);*/
  return (p);
}
