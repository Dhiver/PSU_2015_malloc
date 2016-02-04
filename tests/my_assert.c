/*
** my_assert.c for my_assert in /home/perso/work/projets/malloc_doc/PSU_2015_malloc/tests
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Thu Feb 04 12:29:30 2016 Bastien DHIVER
** Last update Thu Feb 04 13:43:37 2016 Bastien DHIVER
*/

#include <stdlib.h>
#include <stdio.h>
#include <execinfo.h>
#include "my_assert.h"

void		my_assert(int state, const char *file, int line, const char *fct)
{
  if (!state)
    printf("\033[31;1m KO! \033[0min %s on %d by %s\n", file, line, fct);
  else
    printf("\033[32;1m OK! \033[0min %s : %d by %s\n", file, line, fct);
}
