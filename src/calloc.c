/*
** calloc.c for calloc in /home/perso/work/projets/malloc_doc/PSU_2015_malloc/src
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Mon Feb 08 16:57:08 2016 Bastien DHIVER
** Last update Mon Feb 08 17:45:23 2016 Bastien DHIVER
*/

#include "malloc.h"

void	bzero(void *s, size_t n)
{
  char	*ptr;

  ptr = s;
  while (n != 0)
    {
      *ptr++ = 0;
      n--;
    }
}

void		*calloc(size_t nelem, size_t elsize)
{
  void		*p;
  size_t	sum;

  sum = nelem + elsize;
  if ((p = malloc(sum)) == NULL)
    return (p);
  bzero(p, sum);
  return (p);
}
