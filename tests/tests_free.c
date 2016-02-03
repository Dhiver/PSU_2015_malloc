/*
** tests_free.c for tests_free in /home/perso/work/projets/malloc_doc/PSU_2015_malloc/tests
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Tue Feb 02 16:40:46 2016 Bastien DHIVER
** Last update Wed Feb 03 09:08:55 2016 Bastien DHIVER
*/

#include "test_main.h"

void    tests_free()
{
  char *	tmp;
  char *	tmp2;
  size_t    page; 

  tmp = malloc(4096);
  tmp2 = malloc(8195);
  page= get_nb_page((t_block)(tmp2 - META_SIZE));

  (void)tmp;
  (void)page;
}