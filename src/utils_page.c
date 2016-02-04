/*
** utils_page.c for utils_page in /home/perso/work/projets/malloc_doc/PSU_2015_malloc/src
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Mon Feb 01 17:15:46 2016 Bastien DHIVER
** Last update Thu Feb 04 15:00:18 2016 Bastien DHIVER
*/

#include "malloc.h"

size_t		get_nb_page(t_block tmp)
{
    size_t	j;

    j = ((char*)tmp - (char*)start_point) / getpagesize();
    if ((((char*)tmp - (char*)start_point) % getpagesize()) > 0)
      j += 1;
    return (j);
}
